package spatial.compiler.ops

import scala.reflect.{Manifest,SourceContext}
import scala.virtualization.lms.internal.Traversal
import ppl.delite.framework.transform.SinglePassTransformer

import spatial.shared._
import spatial.shared.ops._
import spatial.compiler._
import spatial.compiler.ops._

trait RegisterCleanupTransformExp extends MemoryAnalysisExp {this: SpatialExp => }

trait RegisterCleanupTransformer extends SinglePassTransformer {
  val IR: SpatialExp with RegisterCleanupTransformExp
  import IR._

  override val name = "Register Cleanup"
  debugMode = SpatialConfig.debugging
  verboseMode = SpatialConfig.verbose

  var pendingReaders = Map[Exp[Any], Map[Exp[Any],Exp[Any]]]()

  override def transform[A:Manifest](lhs: Sym[A], rhs: Def[A])(implicit ctx: SourceContext) = rhs match {
    case EatReflect(Reg_read(EatAlias(reg))) =>
      debug(s"$lhs = $rhs")
      debug(s"  Readers($reg) = ${readersOf(reg)}")

      val hasReader = readersOf(reg).exists{_.node == lhs}
      if (!hasReader) debug(s"REMOVING register read $lhs")

      if (hasReader && externalReadersOf(lhs).nonEmpty) {
        debug(s"  External readers: ${externalReadersOf(lhs)}")
        externalReadersOf(lhs).foreach{use =>
          val read = self_mirror(lhs, rhs)
          val map = pendingReaders.getOrElse(use, Map.empty) + (lhs -> read)
          debug(s"    Reader $use: $lhs -> $read")
          pendingReaders += use -> map
        }
      }
      if (!hasReader || externalReadersOf(lhs).nonEmpty) Some(Const(0))
      else None

    case EatReflect(Reg_write(EatAlias(reg),_)) =>
      debug(s"$lhs = $rhs")
      val hasReaders = readersOf(reg).nonEmpty || isArgOut(reg)
      if (!hasReaders) debug(s"  REMOVING register write $lhs")
      if (!hasReaders) Some(Const(0)) else None

    case EatReflect(Reg_new(_)) =>
      debug(s"$lhs = $rhs")
      val hasReaders = readersOf(lhs).nonEmpty
      if (!hasReaders) debug(s"  REMOVING register $lhs")
      if (!hasReaders) Some(Const(0)) else None

    case _ if pendingReaders contains lhs =>
      debug(s"$lhs = $rhs")
      debug(s"  External reader. Adding read substitutions.")
      val lhs2 = withSubstScope(pendingReaders(lhs).toList:_*){ self_mirror(lhs, rhs) }
      val Def(d) = lhs2
      debug(s"  $lhs2 = $d")
      Some(lhs2)

    case _ => super.transform(lhs, rhs)
  }
}
