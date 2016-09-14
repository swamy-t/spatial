import spatial.compiler._
import spatial.library._
import spatial.shared._

object GDA extends SpatialAppCompiler with GDA_App
trait GDA_App extends SpatialApp {
  type T = Flt
  type Array[T] = ForgeArray[T]

  val innerPar = 4
  val outerPar = 2
  val maxCols = 96
  val tileSize = 96

  def gda(xCPU: Rep[Array[T]], yCPU: Rep[Array[Bit]], mu0CPU: Rep[Array[T]], mu1CPU: Rep[Array[T]]) = {
    val rTileSize     = param(tileSize);  domainOf(rTileSize) = (96, 19200, 1)
    val op      = param(outerPar);  domainOf(op)  = (1, 8, 1)
    val ip      = param(innerPar);  domainOf(ip)  = (1, 12, 1)
    val subLoopPar    = param(innerPar);  domainOf(subLoopPar)    = (1, 16, 1)
    val prodLoopPar   = param(innerPar);  domainOf(prodLoopPar)   = (1, 96, 1)
    val outerAccumPar = param(innerPar);  domainOf(outerAccumPar) = (1, 1, 1)

    val rows = yCPU.length;   bound(rows) = 360000
    val cols = param(maxCols); bound(cols) = maxCols


    val R = ArgIn[SInt]
    val C = ArgIn[SInt]

    setArg(R, yCPU.length)
    setArg(C, mu0CPU.length)

    val x     = OffChipMem[T](R, C)
    val y     = OffChipMem[Bit](R)
    val mu0   = OffChipMem[T](C)
    val mu1   = OffChipMem[T](C)
    val sigma = OffChipMem[T](C, C)

    setMem(x, xCPU)
    setMem(y, yCPU)
    setMem(mu0, mu0CPU)
    setMem(mu1, mu1CPU)

    Accel {
      val mu0Tile = BRAM[T](cols)
      val mu1Tile = BRAM[T](cols)
      Parallel {
        mu0Tile := mu0(0::cols, subLoopPar)  // Load mu0
        mu1Tile := mu1(0::cols, subLoopPar)  // Load mu1
      }

      val sigmaOut = BRAM[T](cols, cols)

      Fold(R by rTileSize par op, outerAccumPar)(sigmaOut, 0.as[T]){ r =>
        val yTile = BRAM[Bit](rTileSize)
        val xTile = BRAM[T](rTileSize, cols)
        Parallel {
          yTile := y(r::r+rTileSize, subLoopPar)
          xTile := x(r::r+rTileSize, 0::cols, subLoopPar)  // Load tile of x
        }

        val sigmaBlk = BRAM[T](cols, cols)
        Fold(rTileSize par ip)(sigmaBlk, 0.as[Flt]){rr =>
          val subTile = BRAM[T](cols)
          val sigmaTile = BRAM[T](cols, cols)
          Pipe(C par subLoopPar){ cols =>
            subTile(cols) = xTile(rr,cols) - mux(yTile(rr), mu1Tile(cols), mu0Tile(cols))
          }
          Pipe(C by 1, C par prodLoopPar){ (ii,jj) =>
            sigmaTile(ii,jj) = subTile(ii) * subTile(jj)
          }
          sigmaTile
        }{_+_}
      }{_+_}

      sigma(0::cols, 0::cols, prodLoopPar) := sigmaOut
    }

    getMem(sigma)
  }

  def printArr(a: Rep[Array[T]], str: String = "") {
    println(str)
    (0 until a.length) foreach { i => print(a(i) + " ") }
    println("")
  }


  def main() {
    val R = args(0).to[SInt]
    val C = args(1).to[SInt] // TODO: Should be selectable up to maximum

    val x  = Array.fill(R){ Array.fill(C){ random[T](10) }}
    val ys = Array.fill(R){ random[Bit] }
    val mu0 = Array.fill(C){ random[T](10) }
    val mu1 = Array.fill(C){ random[T](10) }

    val result = gda(x.flatten, ys, mu0, mu1)

    // val gold = x.zip(ys){ (row, y) =>
    //   val sub = if (y) row.zip(mu1){_-_} else row.zip(mu0){_-_}
    //   Array.tabulate(C){i => Array.tabulate(C){j => sub(i) * sub(j) }}.flatten
    // }.reduce{(a,b) => a.zip(b){_+_}}

    //println("actual: " + gold.mkString(", "))
    //println("result: " + result.mkString(", "))
    // println("Sum of differences: " + gold.zip(result){_-_}.reduce{_+_})
    // assert( result == gold )
  }
}
