import spatial.compiler._
import spatial.library._
import spatial.shared._

object MatMult extends SpatialAppCompiler with MatMultApp
trait MatMultApp extends SpatialApp {
  type T = SInt //FixPt[Signed,B16,B16]
  type Array[T] = ForgeArray[T]

  val tileSizeM = 2
  val tileSizeN = 96
  val tileSizeP = 96
  val innerPar = 4
  val midPar = 2
  val outerPar = 2

  def matmult(A: Rep[Array[T]], B: Rep[Array[T]], mm: Rep[SInt], nn: Rep[SInt], pp: Rep[SInt]) = {
    val M = ArgIn[SInt]
    val N = ArgIn[SInt]
    val P = ArgIn[SInt]
    setArg(M,mm)
    setArg(N,nn)
    setArg(P,pp)

    val a = OffChipMem[T](M, P)
    val b = OffChipMem[T](P, N)
    val c = OffChipMem[T](M, N)

    val bm        = param(tileSizeM);   domainOf(bm) = (1,1536,1)
    val bn        = param(tileSizeN);   domainOf(bn) = (96,1536,96)
    val bp        = param(tileSizeP);   domainOf(bp) = (96,1536,96)
    val op  = param(outerPar);   domainOf(op)  = (1,6,1)
    val mp = param(midPar);   domainOf(mp) = (1,96,1)
    val ip  = param(innerPar);   domainOf(ip)  = (1,96,1)
    val upMidPar  = param(1);   domainOf(upMidPar)  = (1,1,1)
    val stPar     = param(1);   domainOf(stPar)     = (1,1,1)

    setMem(a, A)
    setMem(b, B)

    Accel {
      Pipe(M by bm, (N by bn) par op){(i,j) =>
        Pipe((P by bp) par upMidPar){k =>
          val tileA = BRAM[T](bm, bp)
          val tileB = BRAM[T](bp, bn)
          val tileC = BRAM[T](bm, bn)
          Parallel {
            tileA := a(i::i+bm, k::k+bp, param(1))
            tileB := b(k::k+bp, j::j+bn, param(1))
          }
          Sequential(bm by 1, (bn by 1) par mp){ (ii,jj) =>    // MetaPipe?
            val prod = Reduce((bp by 1) par ip)(0.as[T]){ kk => tileA(ii, kk) * tileB(kk, jj) }{_+_}
            val prev = mux(k == 0, 0.as[T], tileC(ii,jj))
            tileC(ii,jj) = prev + prod.value
          }
          c(i::i+bm, j::j+bn, stPar) := tileC
        }
      }
    }
    getMem(c)
  }

  def printArr(a: Rep[Array[T]], str: String = "") {
    println(str)
    (0 until a.length) foreach { i => print(a(i) + " ") }
    println("")
  }

  def main() = {
    val M = args(0).to[SInt]
    val N = args(1).to[SInt]
    val P = args(2).to[SInt]

    val a = Array.fill(M){ Array.fill(P){1} }
    val b = Array.fill(P){ Array.fill(N){1} }
    // val a = Array.fill(M){ Array.fill(P){random[T](100)} }
    // val b = Array.fill(P){ Array.fill(N){random[T](100)} }

    val result = matmult(a.flatten, b.flatten, M, N, P)

    val gold = Array.tabulate(M){i =>
      val aRow = a(i)
      Array.tabulate(N){j =>
        val bCol = b.map{row => row(j)}
        aRow.zip(bCol){_*_}.reduce{_+_}
      }
    }.flatten

    println("expected cksum: " + gold.map(a => a).reduce{_+_})
    println("result cksum: " + result.map(a => a).reduce{_+_})

    assert(gold == result)
  }
}
