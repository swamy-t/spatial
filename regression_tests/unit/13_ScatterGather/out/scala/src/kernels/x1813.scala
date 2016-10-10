package generated.scala
//activation record for fat loop
final class activation_x1813 {
var left_act: activation_x1813 = _
var x1813: Array[FixedPoint[Signed,B32,B0]] = _
var x1813_data: Array[FixedPoint[Signed,B32,B0]] = _
}
object activation_x1813 {
}
object kernel_x1813 {
def apply(resourceInfo:generated.scala.ResourceInfo,x2:Int,x5:FixedPoint[Signed,B32,B0],x9:FixedPoint[Signed,B32,B0],x13:FixedPoint[Signed,B32,B0],x17:FixedPoint[Signed,B32,B0],x21:FixedPoint[Signed,B32,B0],x25:FixedPoint[Signed,B32,B0],x29:FixedPoint[Signed,B32,B0],x33:FixedPoint[Signed,B32,B0],x37:FixedPoint[Signed,B32,B0],x41:FixedPoint[Signed,B32,B0],x45:FixedPoint[Signed,B32,B0],x49:FixedPoint[Signed,B32,B0],x53:FixedPoint[Signed,B32,B0],x57:FixedPoint[Signed,B32,B0],x60:FixedPoint[Signed,B32,B0],x64:FixedPoint[Signed,B32,B0],x63:FixedPoint[Signed,B32,B0],x20:FixedPoint[Signed,B32,B0],x56:FixedPoint[Signed,B32,B0],x52:FixedPoint[Signed,B32,B0],x48:FixedPoint[Signed,B32,B0],x44:FixedPoint[Signed,B32,B0],x40:FixedPoint[Signed,B32,B0],x36:FixedPoint[Signed,B32,B0],x32:FixedPoint[Signed,B32,B0],x28:FixedPoint[Signed,B32,B0],x24:FixedPoint[Signed,B32,B0],x16:FixedPoint[Signed,B32,B0],x12:FixedPoint[Signed,B32,B0],x8:FixedPoint[Signed,B32,B0]): activation_x1813 = {
val x1813_closure = new generated.scala.DeliteOpMultiLoop[activation_x1813] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x2
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x1813 = {
val __act: activation_x1813 = new activation_x1813()
val x83 = (loopSize).asInstanceOf[Int]
if (x83 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x1777 = new Array[FixedPoint[Signed,B32,B0]](x83.toInt)
__act.x1813_data = x1777
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x1813]): activation_x1813 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x1813 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x1813 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813): activation_x1813 = {
val act: activation_x1813 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813,start:Long,end:Long): activation_x1813 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x1813 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813,x3:Int,isEmpty:Boolean): activation_x1813 = {
if (!isEmpty) {
process(resourceInfo,__act,x3)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813,x3:Int): Unit = {
val x4 = {
FixedPoint[Signed,B32,B0](x3)
}
val x6 = {
x4 == x5
}
val x7 = {
x6
}
val x80 = {
def x80thenb(): FixedPoint[Signed,B32,B0] = {
x8
}
def x80elseb(): FixedPoint[Signed,B32,B0] = {
val x10 = {
x4 == x9
}
val x11 = {
x10
}
val x79 = {
def x79thenb(): FixedPoint[Signed,B32,B0] = {
x12
}
def x79elseb(): FixedPoint[Signed,B32,B0] = {
val x14 = {
x4 == x13
}
val x15 = {
x14
}
val x78 = {
def x78thenb(): FixedPoint[Signed,B32,B0] = {
x16
}
def x78elseb(): FixedPoint[Signed,B32,B0] = {
val x18 = {
x4 == x17
}
val x19 = {
x18
}
val x77 = {
def x77thenb(): FixedPoint[Signed,B32,B0] = {
x20
}
def x77elseb(): FixedPoint[Signed,B32,B0] = {
val x22 = {
x4 == x21
}
val x23 = {
x22
}
val x76 = {
def x76thenb(): FixedPoint[Signed,B32,B0] = {
x24
}
def x76elseb(): FixedPoint[Signed,B32,B0] = {
val x26 = {
x4 == x25
}
val x27 = {
x26
}
val x75 = {
def x75thenb(): FixedPoint[Signed,B32,B0] = {
x28
}
def x75elseb(): FixedPoint[Signed,B32,B0] = {
val x30 = {
x4 == x29
}
val x31 = {
x30
}
val x74 = {
def x74thenb(): FixedPoint[Signed,B32,B0] = {
x32
}
def x74elseb(): FixedPoint[Signed,B32,B0] = {
val x34 = {
x4 == x33
}
val x35 = {
x34
}
val x73 = {
def x73thenb(): FixedPoint[Signed,B32,B0] = {
x36
}
def x73elseb(): FixedPoint[Signed,B32,B0] = {
val x38 = {
x4 == x37
}
val x39 = {
x38
}
val x72 = {
def x72thenb(): FixedPoint[Signed,B32,B0] = {
x40
}
def x72elseb(): FixedPoint[Signed,B32,B0] = {
val x42 = {
x4 == x41
}
val x43 = {
x42
}
val x71 = {
def x71thenb(): FixedPoint[Signed,B32,B0] = {
x44
}
def x71elseb(): FixedPoint[Signed,B32,B0] = {
val x46 = {
x4 == x45
}
val x47 = {
x46
}
val x70 = {
def x70thenb(): FixedPoint[Signed,B32,B0] = {
x48
}
def x70elseb(): FixedPoint[Signed,B32,B0] = {
val x50 = {
x4 == x49
}
val x51 = {
x50
}
val x69 = {
def x69thenb(): FixedPoint[Signed,B32,B0] = {
x52
}
def x69elseb(): FixedPoint[Signed,B32,B0] = {
val x54 = {
x4 == x53
}
val x55 = {
x54
}
val x68 = {
def x68thenb(): FixedPoint[Signed,B32,B0] = {
x56
}
def x68elseb(): FixedPoint[Signed,B32,B0] = {
val x58 = {
x4 == x57
}
val x59 = {
x58
}
val x67 = {
def x67thenb(): FixedPoint[Signed,B32,B0] = {
x20
}
def x67elseb(): FixedPoint[Signed,B32,B0] = {
val x61 = {
x4 == x60
}
val x62 = {
x61
}
val x66 = {
def x66thenb(): FixedPoint[Signed,B32,B0] = {
x63
}
def x66elseb(): FixedPoint[Signed,B32,B0] = {
val x65 = {
x4 * x64
}
x65
}
if (x62) {
x66thenb()
} else { 
x66elseb()
}
}
x66
}
if (x59) {
x67thenb()
} else { 
x67elseb()
}
}
x67
}
if (x55) {
x68thenb()
} else { 
x68elseb()
}
}
x68
}
if (x51) {
x69thenb()
} else { 
x69elseb()
}
}
x69
}
if (x47) {
x70thenb()
} else { 
x70elseb()
}
}
x70
}
if (x43) {
x71thenb()
} else { 
x71elseb()
}
}
x71
}
if (x39) {
x72thenb()
} else { 
x72elseb()
}
}
x72
}
if (x35) {
x73thenb()
} else { 
x73elseb()
}
}
x73
}
if (x31) {
x74thenb()
} else { 
x74elseb()
}
}
x74
}
if (x27) {
x75thenb()
} else { 
x75elseb()
}
}
x75
}
if (x23) {
x76thenb()
} else { 
x76elseb()
}
}
x76
}
if (x19) {
x77thenb()
} else { 
x77elseb()
}
}
x77
}
if (x15) {
x78thenb()
} else { 
x78elseb()
}
}
x78
}
if (x11) {
x79thenb()
} else { 
x79elseb()
}
}
x79
}
if (x7) {
x80thenb()
} else { 
x80elseb()
}
}
val x82 = x80
val x81 = __act.x1813_data
val x1781 = x81(x3.toInt) = x82
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813,rhs:activation_x1813): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813,lhs:activation_x1813): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x1813): Unit = {
var x81: Array[FixedPoint[Signed,B32,B0]] = __act.x1813_data
__act.x1813_data = null
__act.x1813 = x81
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x1813 = {
val act: activation_x1813 = new activation_x1813
act
}

}
x1813_closure.loopStart = 0
x1813_closure.loopSize = x2
val alloc: activation_x1813 = x1813_closure.alloc(resourceInfo)
var x1813: activation_x1813 = null
if (resourceInfo.availableThreads <= 1) {
x1813 = x1813_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x1813] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x1813](x1813_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x1813_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x1813 = x1813_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x1813
}}

/**********/

