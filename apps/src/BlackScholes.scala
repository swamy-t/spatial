import spatial.compiler._
import spatial.library._
import spatial.shared._

object BlackScholes extends SpatialAppCompiler with BlackScholesApp
trait BlackScholesApp extends SpatialApp {

  val tileSize = 96
  val outerPar = 1
  val innerPar = 2
  lazy val ts = param(tileSize)
  lazy val op = param(outerPar)
  lazy val ip = param(innerPar)
  lazy val numOptions = ArgIn[SInt]

  final val inv_sqrt_2xPI = 0.39894228040143270286f

  def CNDF(x: Rep[Flt]) = {
    val ax = abs(x)

    val xNPrimeofX = exp((ax ** 2) * -0.05f) * inv_sqrt_2xPI
    val xK2 = 1.as[Flt] / ((ax * 0.2316419f) + 1.0f)

    val xK2_2 = xK2 ** 2
    val xK2_3 = xK2_2 * xK2
    val xK2_4 = xK2_3 * xK2
    val xK2_5 = xK2_4 * xK2

    val xLocal_10 = xK2 * 0.319381530f
    val xLocal_20 = xK2_2 * -0.356563782f
    val xLocal_30 = xK2_3 * 1.781477937f
    val xLocal_31 = xK2_4 * -1.821255978f
    val xLocal_32 = xK2_5 * 1.330274429f

    val xLocal_21 = xLocal_20 + xLocal_30
    val xLocal_22 = xLocal_21 + xLocal_31
    val xLocal_23 = xLocal_22 + xLocal_32
    val xLocal_1 = xLocal_23 + xLocal_10

    val xLocal0 = xLocal_1 * xNPrimeofX
    val xLocal  = -xLocal0 + 1.0f

    mux(x < 0.0f, xLocal0, xLocal)
  }

  def BlkSchlsEqEuroNoDiv(sptprice: Rep[Flt], strike: Rep[Flt], rate: Rep[Flt],
                          volatility: Rep[Flt], time: Rep[Flt], otype: Rep[UInt]) = {

    val xLogTerm = log( sptprice / strike )
    val xPowerTerm = (volatility ** 2) * 0.5f
    val xNum = (rate + xPowerTerm) * time + xLogTerm
    val xDen = volatility * sqrt(time)

    val xDiv = xNum / (xDen ** 2)
    val nofXd1 = CNDF(xDiv)
    val nofXd2 = CNDF(xDiv - xDen)

    val futureValueX = strike * exp(-rate * time)

    val negNofXd1 = -nofXd1 + 1.0f
    val negNofXd2 = -nofXd2 + 1.0f

    val optionPrice1 = (sptprice * nofXd1) - (futureValueX * nofXd2)
    val optionPrice2 = (futureValueX * negNofXd2) - (sptprice * negNofXd1)
    mux(otype == 0, optionPrice2, optionPrice1)
  }

  def blackscholes(
    otype:      Rep[OffChipMem[UInt]],
    sptprice:   Rep[OffChipMem[Flt]],
    strike:     Rep[OffChipMem[Flt]],
    rate:       Rep[OffChipMem[Flt]],
    volatility: Rep[OffChipMem[Flt]],
    otime:      Rep[OffChipMem[Flt]],
    optprice:   Rep[OffChipMem[Flt]]
  ): Rep[Unit] = {

    Pipe((numOptions by ts) par op) { i =>
      val otypeRAM      = BRAM[UInt](ts)
      val sptpriceRAM   = BRAM[Flt](ts)
      val strikeRAM     = BRAM[Flt](ts)
      val rateRAM       = BRAM[Flt](ts)
      val volatilityRAM = BRAM[Flt](ts)
      val otimeRAM      = BRAM[Flt](ts)

      Parallel {
        otypeRAM := otype(i::i+ts, ip)
        sptpriceRAM := sptprice(i::i+ts, ip)
        strikeRAM := strike(i::i+ts, ip)
        rateRAM := rate(i::i+ts, ip)
        volatilityRAM := volatility(i::i+ts, ip)
        otimeRAM := otime(i::i+ts, ip)
      }

      val optpriceRAM = BRAM[Flt](ts)
      Pipe((ts by 1) par ip){ j =>
        val price = BlkSchlsEqEuroNoDiv(sptpriceRAM(j), strikeRAM(j), rateRAM(j), volatilityRAM(j), otimeRAM(j), otypeRAM(j))
        optpriceRAM(j) = price
      }
      optprice(i::i+ts, ip) := optpriceRAM
    }
  }

  def printArr(a: Rep[ForgeArray[Flt]], str: String = "") {
    println(str)
    (0 until a.length) foreach { i => print(a(i) + " ") }
    println("")
  }
  def main() {
    val N = args(0).to[SInt]

    bound(N) = 9995328
    domainOf(ts) = (96,19200,96)
    domainOf(op) = (1,1,1)
    domainOf(ip) = (1,96,1)

    setArg(numOptions, N)
    val types  = OffChipMem[UInt](numOptions)
    val prices = OffChipMem[Flt](numOptions)
    val strike = OffChipMem[Flt](numOptions)
    val rate   = OffChipMem[Flt](numOptions)
    val vol    = OffChipMem[Flt](numOptions)
    val time   = OffChipMem[Flt](numOptions)
    val optprice = OffChipMem[Flt](numOptions)

    val sotype      = Array.fill(N)(random[UInt](2))
    val ssptprice   = Array.fill(N)(random[Flt])
    val sstrike     = Array.fill(N)(random[Flt])
    val srate       = Array.fill(N)(random[Flt])
    val svolatility = Array.fill(N)(random[Flt])
    val sotime      = Array.fill(N)(random[Flt])

    setMem(types, sotype)
    setMem(prices, ssptprice)
    setMem(strike, sstrike)
    setMem(rate, srate)
    setMem(vol, svolatility)
    setMem(time, sotime)

    Accel{ blackscholes(types, prices, strike, rate, vol, time, optprice) }

    val out = getMem(optprice)

    // printArr(sstrike, "sstrike:")
    // printArr(out, "result:")
  }
}
