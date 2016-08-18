package ppl.dsl.forge
package dsls
package spatial

trait GlobalAnalysis {
  this: SpatialDSL =>

  /**
   * In Spatial, a "global" is any value which is solely a function of input arguments
   * and constants. These are computed prior to starting the main computation, and
   * therefore appear constant to the majority of the program.
   *
   * Note that this is only true for stateless nodes. These rules should not be generated
   * for stateful hardware (e.g. accumulators, pseudo-random generators)
   **/

  def importGlobalAnalysis() = {
    val GlobalAnalyzer = analyzer("Global")
    val FixPt = lookupTpe("FixPt")
    val FltPt = lookupTpe("FltPt")
    val Tpes = lookupGrp("Tpes")
    val Ctrl = lookupGrp("BasicCtrl")
    val Lifts = lookupGrp("ConstLifts")
    val Reg = lookupTpe("Reg")

    def generateRule(args: List[String]) = "isGlobal(lhs) = " + args.map(arg => "isGlobal("+arg+")").mkString(" && ")

    val GlobalAnalysisRules = withAnalyzer(GlobalAnalyzer)
    GlobalAnalysisRules {
      analyze(Lifts, "constBit") using rule ${ isGlobal(lhs) = true }
      analyze(Lifts, "constFixPt") using rule ${ isGlobal(lhs) = true }
      analyze(Lifts, "constFltPt") using rule ${ isGlobal(lhs) = true }
      analyze(Reg, "reg_read") using rule ${ isGlobal(lhs) = regType($0) == ArgumentIn }

      // Holy hackery, batman!
      for (op <- FixPt.nodes ++ FltPt.nodes ++ Tpes.nodes ++ Ctrl.nodes) {
        analyze(op) using rule { generateRule(op.argNames) }
      }
    }
  }

}
