import spatial.compiler._
import spatial.library._
import spatial.shared._

object TPCHQ6 extends SpatialAppCompiler with TPCHQ6_App
trait TPCHQ6_App extends SpatialApp {
  type Array[T] = ForgeArray[T]

  val MIN_DATE = 70
  val MAX_DATE = 80
  val tileSize = 192
  val outerPar = 2
  val innerPar = 4

  def tpchq6(datesIn: Rep[Array[UInt]], quantsIn: Rep[Array[UInt]], disctsIn: Rep[Array[Flt]], pricesIn: Rep[Array[Flt]]): Rep[Flt] = {
    val dataSize = ArgIn[SInt]
    setArg(dataSize, datesIn.length)


    val dates  = OffChipMem[UInt](dataSize)
    val quants = OffChipMem[UInt](dataSize)
    val discts = OffChipMem[Flt](dataSize)
    val prices = OffChipMem[Flt](dataSize)
    val minDateIn = MIN_DATE
    val maxDateIn = MAX_DATE
    val out = ArgOut[Flt]

    val ts = param(tileSize);   domainOf(ts) = (96,192000,96)
    val op = param(outerPar);    domainOf(op) = (1,6,1)
    val ip = param(innerPar);    domainOf(ip) = (1,384,1)

    setMem(dates, datesIn)
    setMem(quants, quantsIn)
    setMem(discts, disctsIn)
    setMem(prices, pricesIn)

    Accel {
      val minDate = minDateIn
      val maxDate = maxDateIn

      val acc = Reg[Flt]
      Fold(dataSize by ts par op)(acc, 0.as[Flt]){ i =>
        val datesTile  = BRAM[UInt](ts)
        val quantsTile = BRAM[UInt](ts)
        val disctsTile = BRAM[Flt](ts)
        val pricesTile = BRAM[Flt](ts)
        Parallel {
          datesTile  := dates(i::i+ts, ip)
          quantsTile := quants(i::i+ts, ip)
          disctsTile := discts(i::i+ts, ip)
          pricesTile := prices(i::i+ts, ip)
        }
        Reduce(ts par ip)(0.as[Flt]){ j =>
          val date  = datesTile(j)
          val disct = disctsTile(j)
          val quant = quantsTile(j)
          val price = pricesTile(j)
          val valid = date > minDate && date < maxDate && disct >= 0.05f && disct <= 0.07f && quant < 24
          mux(valid, price * disct, 0.0f)
        }{_+_}
      }{_+_}
      Pipe {out := acc}
    }
    getArg(out)
  }


  def main() {
    val N = args(0).to[SInt]

    val dates  = Array.fill(N){random[UInt](20) + 65}
    val quants = Array.fill(N){random[UInt](25) }
    val discts = Array.fill(N){random[Flt] * 0.05f + 0.02f}
    val prices = Array.fill(N){random[Flt] * 1000f}

    val result = tpchq6(dates, quants, discts, prices)

    // --- software version
    val conds = Array.tabulate(N){i => dates(i) > MIN_DATE && dates(i) < MAX_DATE &&
                                       quants(i) < 24 && discts(i) >= 0.05f && discts(i) <= 0.07f }

    val gold = Array.tabulate(N){i => if (conds(i)) prices(i) * discts(i) else 0.0f.as[Flt] }.reduce{_+_}

    println("expected " + gold)
    println("result " + result)
    assert(result == gold)
  }
}
