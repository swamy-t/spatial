package generated.scala
//activation record for fat loop
final class activation_x3043 {
var left_act: activation_x3043 = _
var x3043: Array[Boolean] = _
var x3043_data: Array[Boolean] = _
}
object activation_x3043 {
}
object kernel_x3043 {
def apply(resourceInfo:generated.scala.ResourceInfo,x3:Int,x2631:Array[FixedPoint[Unsign,B32,B0]],x221:FixedPoint[Unsign,B32,B0],x295:FixedPoint[Unsign,B32,B0],x2670:Array[FixedPoint[Unsign,B32,B0]],x303:FixedPoint[Unsign,B32,B0],x2710:Array[FixedPoint[Signed,B32,B0]],x195:FixedPoint[Signed,B32,B0],x300:FixedPoint[Signed,B32,B0]): activation_x3043 = {
val x3043_closure = new generated.scala.DeliteOpMultiLoop[activation_x3043] {
def size(resourceInfo:generated.scala.ResourceInfo): Long = {
x3
}

var loopStart: Long = _
var loopSize: Long = _
def alloc(resourceInfo:generated.scala.ResourceInfo): activation_x3043 = {
val __act: activation_x3043 = new activation_x3043()
val x360 = (loopSize).asInstanceOf[Int]
if (x360 > Int.MaxValue) throw new RuntimeException("Allocation size too large for 32-bit runtime")
val x3007 = new Array[Boolean](x360.toInt)
__act.x3043_data = x3007
__act
}

def main_par(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043,sync:ppl.delite.runtime.sync.MultiLoopSync[activation_x3043]): activation_x3043 = {
val tid: Int = resourceInfo.groupId
val numThreads: Int = resourceInfo.groupSize
//process local
val numChunks: Int = sync.numChunks
var dIdx: Int = tid
while (dIdx < numChunks) {
val start: Long = loopStart + loopSize*dIdx/numChunks
val end: Long = loopStart + loopSize*(dIdx+1)/numChunks
val act: activation_x3043 = processRange(resourceInfo,__act,start,end)
sync.set(dIdx,act)
dIdx = sync.getNextChunkIdx
}
val localStart: Int = tid*numChunks/numThreads
val localEnd: Int = (tid+1)*numChunks/numThreads
val act: activation_x3043 = sync.get(localStart)
sync.awaitBarrier
if (tid == 0) {
finalize(resourceInfo,act)
}
act
}

def main_seq(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043): activation_x3043 = {
val act: activation_x3043 = processRange(resourceInfo,__act,loopStart,loopStart+loopSize)
finalize(resourceInfo,act)
act
}

def processRange(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043,start:Long,end:Long): activation_x3043 = {
val isEmpty: Boolean = end-start <= 0
var idx: Int = (start).asInstanceOf[Int]
val __act2: activation_x3043 = init(resourceInfo,__act,idx,isEmpty)
idx = idx + 1
while (idx < end) {
process(resourceInfo,__act2,idx)
idx = idx + 1
}
__act2
}

def init(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043,x343:Int,isEmpty:Boolean): activation_x3043 = {
if (!isEmpty) {
process(resourceInfo,__act,x343)
}
__act
}

def process(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043,x343:Int): Unit = {
val x344 = {
FixedPoint[Signed,B32,B0](x343)
}
val x345 = {
x344.toInt
}
val x2995 = x2631(x345.toInt)
val x2996 = {
x221 < x2995
}
val x2997 = {
x2995 < x295
}
val x2998 = {
x2996 && x2997
}
val x2999 = x2670(x345.toInt)
val x3000 = {
x2999 < x303
}
val x3001 = {
x2998 && x3000
}
val x3002 = x2710(x345.toInt)
val x3003 = {
x195 <= x3002
}
val x3004 = {
x3001 && x3003
}
val x3005 = {
x3002 <= x300
}
val x3006 = {
x3004 && x3005
}
val x359 = x3006
val x358 = __act.x3043_data
val x3011 = x358(x343.toInt) = x359
}

def combine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043,rhs:activation_x3043): Unit = {
}

def postCombine(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043,lhs:activation_x3043): Unit = {
__act.left_act = lhs
}

def postProcInit(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043): Unit = {
}

def postProcess(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043): Unit = {
}

def finalize(resourceInfo:generated.scala.ResourceInfo,__act:activation_x3043): Unit = {
var x358: Array[Boolean] = __act.x3043_data
__act.x3043_data = null
__act.x3043 = x358
}

def initAct(resourceInfo:generated.scala.ResourceInfo): activation_x3043 = {
val act: activation_x3043 = new activation_x3043
act
}

}
x3043_closure.loopStart = 0
x3043_closure.loopSize = x3
val alloc: activation_x3043 = x3043_closure.alloc(resourceInfo)
var x3043: activation_x3043 = null
if (resourceInfo.availableThreads <= 1) {
x3043 = x3043_closure.main_seq(resourceInfo,alloc)
} else {
val sync: ppl.delite.runtime.sync.MultiLoopSync[activation_x3043] = new ppl.delite.runtime.sync.MultiLoopSync[activation_x3043](x3043_closure.loopSize,0,resourceInfo)
var i: Int = 1
while (i < sync.numThreads) {
val r: generated.scala.ResourceInfo = sync.getThreadResource(i)
val executable = new ppl.delite.runtime.executor.DeliteExecutable {
      def run() = x3043_closure.main_par(r,alloc,sync)
    }
    ppl.delite.runtime.Delite.executor.runOne(r.threadId, executable)
i = i+1
}
x3043 = x3043_closure.main_par(sync.getThreadResource(0),alloc,sync)
}

x3043
}}

/**********/

