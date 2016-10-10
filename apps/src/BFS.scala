import spatial.compiler._
import spatial.library._
import spatial.shared._

object BFS extends SpatialAppCompiler with BFSApp
trait BFSApp extends SpatialApp {
  type Elem = Flt //FixPt[Signed, B16, B16]
  type T = Flt
  type Array[T] = ForgeArray[T]

  val tileSize = 192
  val edges_per_node = 6 // Will make this random later



  def bfs(INnodes: Rep[Array[SInt]], INedges: Rep[Array[SInt]], INcounts: Rep[Array[SInt]], INids: Rep[Array[SInt]], n: Rep[SInt], e: Rep[SInt]) = {
    
    val OCnodes = OffChipMem[SInt](n)
    val OCedges = OffChipMem[SInt](e) 
    val OCcounts = OffChipMem[SInt](n) 
    val OCids = OffChipMem[SInt](n) 
    val OCresult = OffChipMem[SInt](n)

    setMem(OCnodes, INnodes)
    setMem(OCedges, INedges)
    setMem(OCcounts, INcounts)
    setMem(OCids, INids)

    Accel {
      val frontierNodes = BRAM[SInt](tileSize)
      // val frontierCounts = BRAM[SInt](tileSize)
      // val frontierIds = BRAM[SInt](tileSize)
      val frontierLevels = BRAM[SInt](tileSize)
      // frontierCounts := OCcounts(0::1)
      // frontierIds := OCids(0::1)
      // val id = frontierIds(0)
      // val count = frontierCounts(0)
      frontierNodes := OCedges(0::tileSize)
      Pipe(edges_per_node by 1) { i => frontierLevels(i) = 1 }
      OCresult(frontierNodes, edges_per_node) := frontierLevels
      // Sequential(count by 1) { i => 
    }
    getMem(OCresult)
  }

  def printArr(a: Rep[Array[SInt]], str: String = "") {
    println(str)
    (0 until a.length) foreach { i => print(a(i) + " ") }
    println("")
  }

  def main() {
    val layers = 5
    val nodes = (scala.math.pow(edges_per_node, layers) - 1).toInt

    val OCnodes = Array.tabulate(nodes) {i => 0}
    val OCedges = Array.tabulate(nodes*edges_per_node){i => i+1}
    val OCcounts = Array.tabulate(nodes) { i => edges_per_node }
    val OCids = Array.tabulate(nodes) { i => i*edges_per_node }
    val gold = Array.empty[SInt](layers)
    (0 until nodes) foreach { i => 
      gold(i) = Array.tabulate(i) { j => i}.reduce{_*_}}
    val result = bfs(OCnodes, OCedges, OCcounts, OCids, nodes, nodes*edges_per_node)
    // println("expected: " + gold.mkString(","))

    printArr(gold, "result: ")

  }
}