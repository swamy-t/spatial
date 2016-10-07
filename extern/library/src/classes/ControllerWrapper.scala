package spatial.library.classes

import scala.annotation.unchecked.uncheckedVariance
import scala.reflect.{Manifest,SourceContext}

import spatial.shared._
import spatial.shared.ops._
import spatial.library._
import spatial.library.classes._

trait ControllerWrapper {
  this: SpatialBase with SpatialClasses =>

  private def loop(cchain: Rep[CounterChain], idx: Int, indices: List[FixPt[Signed,B32,B0]], func: Rep[Indices] => Rep[Unit]): Rep[Unit] = {
    val ctr = cchain(idx)
    if (idx >= cchain.length - 1) {
      for (i <- ctr) { func(indices_create(indices :+ i.head)) }
    }
    else {
      for (i <- ctr) { loop(cchain, idx+1, indices :+ i.head, func) }
    }
  }
  private def loopList(cchain: Rep[CounterChain], idx: Int, indices: List[FixPt[Signed,B32,B0]], func: List[Rep[FixPt[Signed,B32,B0]]] => Rep[Unit]): Rep[Unit] = {
    val ctr = cchain(idx)
    if (idx >= cchain.length - 1) {
      for (i <- ctr) { func(indices :+ i.head) }
    }
    else {
      for (i <- ctr) { loopList(cchain, idx+1, indices :+ i.head, func) }
    }
  }

  def parallel_pipe(func: => Rep[Unit])(implicit ctx: SourceContext): Rep[Pipeline] = func
  def unit_pipe(func: => Rep[Unit])(implicit ctx: SourceContext): Rep[Pipeline] = func

  def foreach_op(cchain: Rep[CounterChain], func: Rep[Indices] => Rep[Unit])(implicit ctx: SourceContext): Rep[Pipeline] = {
    loop(cchain, 0, Nil, func)
  }

  def reduce_op[T,C[T]](cchain: Rep[CounterChain], accum: Rep[C[T]], zero: Option[Rep[T]], func: Rep[Indices] => Rep[T], rFunc: (Rep[T],Rep[T]) => Rep[T], foldAccum: Boolean = true)(implicit ctx: SourceContext, __mem: Mem[T,C], __num: Num[T], __mT: Manifest[T], __mC: Manifest[C[T]]): Rep[Pipeline]  = {
    def iFunc(c: Rep[C[T]], i: Rep[Indices]): Rep[FixPt[Signed,B32,B0]] = __mem.flatIdx(c, i)
    def ldFunc(c: Rep[C[T]], i: Rep[FixPt[Signed,B32,B0]]): Rep[T] = __mem.ld(c, i)
    def stFunc(c: Rep[C[T]], i: Rep[FixPt[Signed,B32,B0]], x: Rep[T]): Rep[Unit] = __mem.st(c, i, x)

    loop(cchain, 0, Nil, {i: Rep[Indices] =>
      val idx = iFunc(accum, i)
      stFunc(accum, idx, rFunc(ldFunc(accum, idx), func(i)))
    })
  }

  def memreduce_op[T,C[T]](cchain: Rep[CounterChain], cchainRed: Rep[CounterChain], accum: Rep[C[T]], zero: Option[Rep[T]], func: Rep[Indices] => Rep[C[T]], rFunc: (Rep[T],Rep[T]) => Rep[T], foldAccum: Boolean = true)(implicit ctx: SourceContext, __mem: Mem[T,C], __num: Num[T], __mT: Manifest[T], __mC: Manifest[C[T]]): Rep[Pipeline] = {
    def iFunc(c: Rep[C[T]], i: Rep[Indices]): Rep[FixPt[Signed,B32,B0]] = __mem.flatIdx(c, i)
    def ldFunc(c: Rep[C[T]], i: Rep[FixPt[Signed,B32,B0]]): Rep[T] = __mem.ld(c, i)
    def stFunc(c: Rep[C[T]], i: Rep[FixPt[Signed,B32,B0]], x: Rep[T]) = __mem.st(c, i, x)

    var first = true
    loop(cchain, 0, Nil, {i: Rep[Indices] =>
      val part = func(i)

      loop(cchainRed, 0, Nil, {j: Rep[Indices] =>
        val idx  = iFunc(part, j)
        if (first && !foldAccum)
          stFunc(accum, idx, ldFunc(part, idx))
        else
          stFunc(accum, idx, rFunc(ldFunc(part, idx), ldFunc(accum, idx)))
      })
      first = false
    })
  }

}
