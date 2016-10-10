package generated.scala
object kernel_x5033 {
def apply(resourceInfo:generated.scala.ResourceInfo,x4578:Array[FixedPoint[Signed,B32,B0]],x4579:Array[FixedPoint[Signed,B32,B0]],x285:FixedPoint[Signed,B32,B0],x3194:FixedPoint[Signed,B32,B0],x3195:FixedPoint[Signed,B32,B0],x4580:Array[FixedPoint[Signed,B32,B0]],x3197:FixedPoint[Signed,B32,B0],x3199:FixedPoint[Signed,B32,B0],x333:FixedPoint[Signed,B32,B0],x11:FixedPoint[Signed,B32,B0],x4585:FixedPoint[Signed,B32,B0],x422:Boolean,x4587:Array[FixedPoint[Signed,B32,B0]],x4588:FixedPoint[Signed,B32,B0],x4590:Array[FixedPoint[Signed,B32,B0]],x4592:Array[FixedPoint[Signed,B32,B0]]): Unit = {
val x5033 = {
{ 
val x4819 = {
x4578.apply(0)
}
val x4820 = {
x4579.apply(0)
}
val x4821 = x285 until x4819 by x3194 par 1
val x4822 = x285 until x4820 by x3195 par 2
val x4823 = Array(x4821, x4822)
for( x4823_vec0 <- x4823.apply(0.toInt)) {
  val x3901 = x4823_vec0.apply(0.toInt)
for( x4823_vec1 <- x4823.apply(1.toInt)) {
  val x3902 = x4823_vec1.apply(0.toInt)
  val x3903 = x4823_vec1.apply(1.toInt)
val x4824 = {
x4580.apply(0)
}
val x4825 = {
x4580.apply(0)
}
val x4826 = x285 until x4824 by x3195 par 1
val x4827 = x285 until x4825 by x3195 par 1
val x4828 = Array(x4826)
val x4829 = Array(x4827)
val x5029 = {
{ 
for( x4828_vec0 <- x4828.apply(0.toInt)) {
  val x3910 = x4828_vec0.apply(0.toInt)
val x4830 = {
Array.fill(x3197.toInt)(x285)
}
val x4831 = {
Array.fill(x3199.toInt)(x285)
}
val x4832 = {
Array.fill(x3197.toInt)(x285)
}
val x4876 = {
{ 
val x4833 = {
scala.collection.mutable.Queue.fill(0.toInt)(x285)
}
val x4834 = x285 until x3194 by x11 par 1
val x4835 = Array(x4834)
for( x4835_vec0 <- x4835.apply(0.toInt)) {
  val x3917 = x4835_vec0.apply(0.toInt)
val x4836 = {
Array(x285)
}
val x4841 = {
{ 
val x3919 = {
x3901 + x3917
}
val x4837 = {
x3919 * x4585
}
val x4838 = {
x4837 + x3910
}
val x4839 = {
if (x422) x4836.update(0, x4838)
}
()
 }
 
()
}
val x4842 = {
x4836.apply(0)
}
val x4843 = {
for (i <- 0 until x3195.toInt) { if (i + x4842.toInt < x4587.length) x4833.enqueue( x4587(i + x4842.toInt) ) else x4833.enqueue(x4587(0)) }
}
val x4844 = x285 until x3195 by x11 par 1
val x4845 = Array(x4844)
for( x4845_vec0 <- x4845.apply(0.toInt)) {
  val x3929 = x4845_vec0.apply(0.toInt)
val x4846 = {
if (1 < x4833.length) {

val first = x4833.front
Array.tabulate(1){i => if (x4833.nonEmpty) x4833.dequeue() else first }
}
else {
Array.tabulate(1){i => x4833.dequeue() }
}
}
val x3932 = {
x3917 * x3195
}
val x3933 = {
x3932 + x3929
}
val x3935 = Array(x3933)
val x4847 = {
x4846.apply(0)
}
val x4848 = Array(x4847)
val x4849 = {
x4848.zip(x3935).foreach{ case (v,a) => if (a.toInt < x4830.length) x4830(a.toInt) = v }
}
}
val x4851 = ()
}
val x4853 = ()
val x4854 = {
scala.collection.mutable.Queue.fill(0.toInt)(x285)
}
val x4855 = x285 until x3195 by x11 par 1
val x4856 = Array(x4855)
for( x4856_vec0 <- x4856.apply(0.toInt)) {
  val x3945 = x4856_vec0.apply(0.toInt)
val x4857 = {
Array(x285)
}
val x4862 = {
{ 
val x3947 = {
x3910 + x3945
}
val x4858 = {
x3947 * x4588
}
val x4859 = {
x4858 + x3902
}
val x4860 = {
if (x422) x4857.update(0, x4859)
}
()
 }
 
()
}
val x4863 = {
x4857.apply(0)
}
val x4864 = {
for (i <- 0 until x3195.toInt) { if (i + x4863.toInt < x4590.length) x4854.enqueue( x4590(i + x4863.toInt) ) else x4854.enqueue(x4590(0)) }
}
val x4865 = x285 until x3195 by x11 par 1
val x4866 = Array(x4865)
for( x4866_vec0 <- x4866.apply(0.toInt)) {
  val x3957 = x4866_vec0.apply(0.toInt)
val x4867 = {
if (1 < x4854.length) {

val first = x4854.front
Array.tabulate(1){i => if (x4854.nonEmpty) x4854.dequeue() else first }
}
else {
Array.tabulate(1){i => x4854.dequeue() }
}
}
val x3960 = {
x3945 * x3195
}
val x3961 = {
x3960 + x3957
}
val x3963 = Array(x3961)
val x4868 = {
x4867.apply(0)
}
val x4869 = Array(x4868)
val x4870 = {
x4869.zip(x3963).foreach{ case (v,a) => if (a.toInt < x4831.length) x4831(a.toInt) = v }
}
}
val x4872 = ()
}
val x4874 = ()
()
 }
 
()
}
val x4877 = x285 until x3194 by x11 par 1
val x4878 = x285 until x3195 by x11 par 1
val x4879 = Array(x4877, x4878)
for( x4879_vec0 <- x4879.apply(0.toInt)) {
  val x3975 = x4879_vec0.apply(0.toInt)
for( x4879_vec1 <- x4879.apply(1.toInt)) {
  val x3976 = x4879_vec1.apply(0.toInt)
val x4880 = {
Array(x285)
}
val x4881 = x285 until x3195 by x11 par 2
val x4882 = Array(x4881)
val x3980 = x4880
for( x4882_vec0 <- x4882.apply(0.toInt)) {
  val x3988 = x4882_vec0.apply(0.toInt)
  val x3989 = x4882_vec0.apply(1.toInt)
val x3990 = {
x3975 * x3195
}
val x3991 = {
x3990 + x3988
}
val x3992 = {
x3990 + x3989
}
val x3993 = Array(x3991,x3992)
val x4883 = {
x3993.map{addr => if (addr.toInt < x4830.length) x4830(addr.toInt) else x4830(0) }
}
val x3998 = {
x3988 * x3195
}
val x4000 = {
x3998 + x3976
}
val x3999 = {
x3989 * x3195
}
val x4001 = {
x3999 + x3976
}
val x4002 = Array(x4000,x4001)
val x4884 = {
x4002.map{addr => if (addr.toInt < x4831.length) x4831(addr.toInt) else x4831(0) }
}
val x4885 = {
x3980.apply(0)
}
val x4886 = {
x4883.apply(0)
}
val x4887 = {
x4884.apply(0)
}
val x4888 = {
x4886 * x4887
}
val x4889 = {
x4883.apply(1)
}
val x4890 = {
x4884.apply(1)
}
val x4891 = {
x4889 * x4890
}
val x4892 = {
x4888 + x4891
}
val x4893 = {
x4892 + x4885
}
val x4894 = {
if (x422) x3980.update(0, x4893)
}
}
val x4896 = ()
val x4903 = {
{ 
val x3990 = {
x3975 * x3195
}
val x4022 = {
x3990 + x3976
}
val x4897 = {
x4832.apply(x4022.toInt)
}
val x4898 = {
x4880.apply(0)
}
val x4025 = {
x3910 == x285
}
val x4899 = {
if (x4025) x285 else x4897
}
val x4900 = {
x4899 + x4898
}
val x4901 = {
x4832.update(x4022.toInt, x4900)
}
()
 }
 
()
}
}}
val x4905 = ()
val x4906 = {
scala.collection.mutable.Queue.fill(0.toInt)(x285)
}
val x4907 = x285 until x3194 by x11 par 1
val x4908 = Array(x4907)
for( x4908_vec0 <- x4908.apply(0.toInt)) {
  val x4037 = x4908_vec0.apply(0.toInt)
val x4909 = x285 until x3195 by x11 par 1
val x4910 = Array(x4909)
for( x4910_vec0 <- x4910.apply(0.toInt)) {
  val x4040 = x4910_vec0.apply(0.toInt)
val x4041 = {
x4037 * x3195
}
val x4042 = {
x4041 + x4040
}
val x4043 = Array(x4042)
val x4911 = {
x4043.map{addr => if (addr.toInt < x4832.length) x4832(addr.toInt) else x4832(0) }
}
val x4047 = {
x4040 < x3195
}
val x4048 = Array(x4047)
val x4912 = {
x4911.apply(0)
}
val x4913 = Array(x4912)
val x4914 = {
x4913.zip(x4048).foreach{ case (v,e) => if (e) x4906.enqueue(v) }
}
}
val x4916 = ()
val x4917 = {
Array(x285)
}
val x4922 = {
{ 
val x4054 = {
x3901 + x4037
}
val x4918 = {
x4054 * x4588
}
val x4919 = {
x4918 + x3902
}
val x4920 = {
if (x422) x4917.update(0, x4919)
}
()
 }
 
()
}
val x4923 = {
x4917.apply(0)
}
val x4924 = {
for (i <- 0 until x3195.toInt) { if (i + x4923.toInt < x4592.length) x4592(i + x4923.toInt) = x4906.dequeue() }
}
}
val x4926 = ()
}
val x4928 = ()
for( x4829_vec0 <- x4829.apply(0.toInt)) {
  val x4068 = x4829_vec0.apply(0.toInt)
val x4929 = {
Array.fill(x3197.toInt)(x285)
}
val x4930 = {
Array.fill(x3199.toInt)(x285)
}
val x4931 = {
Array.fill(x3197.toInt)(x285)
}
val x4975 = {
{ 
val x4932 = {
scala.collection.mutable.Queue.fill(0.toInt)(x285)
}
val x4933 = x285 until x3194 by x11 par 1
val x4934 = Array(x4933)
for( x4934_vec0 <- x4934.apply(0.toInt)) {
  val x4075 = x4934_vec0.apply(0.toInt)
val x4935 = {
Array(x285)
}
val x4940 = {
{ 
val x4077 = {
x3901 + x4075
}
val x4936 = {
x4077 * x4585
}
val x4937 = {
x4936 + x4068
}
val x4938 = {
if (x422) x4935.update(0, x4937)
}
()
 }
 
()
}
val x4941 = {
x4935.apply(0)
}
val x4942 = {
for (i <- 0 until x3195.toInt) { if (i + x4941.toInt < x4587.length) x4932.enqueue( x4587(i + x4941.toInt) ) else x4932.enqueue(x4587(0)) }
}
val x4943 = x285 until x3195 by x11 par 1
val x4944 = Array(x4943)
for( x4944_vec0 <- x4944.apply(0.toInt)) {
  val x4087 = x4944_vec0.apply(0.toInt)
val x4945 = {
if (1 < x4932.length) {

val first = x4932.front
Array.tabulate(1){i => if (x4932.nonEmpty) x4932.dequeue() else first }
}
else {
Array.tabulate(1){i => x4932.dequeue() }
}
}
val x4090 = {
x4075 * x3195
}
val x4091 = {
x4090 + x4087
}
val x4093 = Array(x4091)
val x4946 = {
x4945.apply(0)
}
val x4947 = Array(x4946)
val x4948 = {
x4947.zip(x4093).foreach{ case (v,a) => if (a.toInt < x4929.length) x4929(a.toInt) = v }
}
}
val x4950 = ()
}
val x4952 = ()
val x4953 = {
scala.collection.mutable.Queue.fill(0.toInt)(x285)
}
val x4954 = x285 until x3195 by x11 par 1
val x4955 = Array(x4954)
for( x4955_vec0 <- x4955.apply(0.toInt)) {
  val x4103 = x4955_vec0.apply(0.toInt)
val x4956 = {
Array(x285)
}
val x4961 = {
{ 
val x4105 = {
x4068 + x4103
}
val x4957 = {
x4105 * x4588
}
val x4958 = {
x4957 + x3903
}
val x4959 = {
if (x422) x4956.update(0, x4958)
}
()
 }
 
()
}
val x4962 = {
x4956.apply(0)
}
val x4963 = {
for (i <- 0 until x3195.toInt) { if (i + x4962.toInt < x4590.length) x4953.enqueue( x4590(i + x4962.toInt) ) else x4953.enqueue(x4590(0)) }
}
val x4964 = x285 until x3195 by x11 par 1
val x4965 = Array(x4964)
for( x4965_vec0 <- x4965.apply(0.toInt)) {
  val x4115 = x4965_vec0.apply(0.toInt)
val x4966 = {
if (1 < x4953.length) {

val first = x4953.front
Array.tabulate(1){i => if (x4953.nonEmpty) x4953.dequeue() else first }
}
else {
Array.tabulate(1){i => x4953.dequeue() }
}
}
val x4118 = {
x4103 * x3195
}
val x4119 = {
x4118 + x4115
}
val x4121 = Array(x4119)
val x4967 = {
x4966.apply(0)
}
val x4968 = Array(x4967)
val x4969 = {
x4968.zip(x4121).foreach{ case (v,a) => if (a.toInt < x4930.length) x4930(a.toInt) = v }
}
}
val x4971 = ()
}
val x4973 = ()
()
 }
 
()
}
val x4976 = x285 until x3194 by x11 par 1
val x4977 = x285 until x3195 by x11 par 1
val x4978 = Array(x4976, x4977)
for( x4978_vec0 <- x4978.apply(0.toInt)) {
  val x4133 = x4978_vec0.apply(0.toInt)
for( x4978_vec1 <- x4978.apply(1.toInt)) {
  val x4134 = x4978_vec1.apply(0.toInt)
val x4979 = {
Array(x285)
}
val x4980 = x285 until x3195 by x11 par 2
val x4981 = Array(x4980)
val x4138 = x4979
for( x4981_vec0 <- x4981.apply(0.toInt)) {
  val x4146 = x4981_vec0.apply(0.toInt)
  val x4147 = x4981_vec0.apply(1.toInt)
val x4148 = {
x4133 * x3195
}
val x4149 = {
x4148 + x4146
}
val x4150 = {
x4148 + x4147
}
val x4151 = Array(x4149,x4150)
val x4982 = {
x4151.map{addr => if (addr.toInt < x4929.length) x4929(addr.toInt) else x4929(0) }
}
val x4155 = {
x4146 * x3195
}
val x4157 = {
x4155 + x4134
}
val x4156 = {
x4147 * x3195
}
val x4158 = {
x4156 + x4134
}
val x4159 = Array(x4157,x4158)
val x4983 = {
x4159.map{addr => if (addr.toInt < x4930.length) x4930(addr.toInt) else x4930(0) }
}
val x4984 = {
x4138.apply(0)
}
val x4985 = {
x4982.apply(0)
}
val x4986 = {
x4983.apply(0)
}
val x4987 = {
x4985 * x4986
}
val x4988 = {
x4982.apply(1)
}
val x4989 = {
x4983.apply(1)
}
val x4990 = {
x4988 * x4989
}
val x4991 = {
x4987 + x4990
}
val x4992 = {
x4991 + x4984
}
val x4993 = {
if (x422) x4138.update(0, x4992)
}
}
val x4995 = ()
val x5002 = {
{ 
val x4148 = {
x4133 * x3195
}
val x4179 = {
x4148 + x4134
}
val x4996 = {
x4931.apply(x4179.toInt)
}
val x4997 = {
x4979.apply(0)
}
val x4182 = {
x4068 == x285
}
val x4998 = {
if (x4182) x285 else x4996
}
val x4999 = {
x4998 + x4997
}
val x5000 = {
x4931.update(x4179.toInt, x4999)
}
()
 }
 
()
}
}}
val x5004 = ()
val x5005 = {
scala.collection.mutable.Queue.fill(0.toInt)(x285)
}
val x5006 = x285 until x3194 by x11 par 1
val x5007 = Array(x5006)
for( x5007_vec0 <- x5007.apply(0.toInt)) {
  val x4194 = x5007_vec0.apply(0.toInt)
val x5008 = x285 until x3195 by x11 par 1
val x5009 = Array(x5008)
for( x5009_vec0 <- x5009.apply(0.toInt)) {
  val x4197 = x5009_vec0.apply(0.toInt)
val x4198 = {
x4194 * x3195
}
val x4199 = {
x4198 + x4197
}
val x4200 = Array(x4199)
val x5010 = {
x4200.map{addr => if (addr.toInt < x4931.length) x4931(addr.toInt) else x4931(0) }
}
val x4204 = {
x4197 < x3195
}
val x4205 = Array(x4204)
val x5011 = {
x5010.apply(0)
}
val x5012 = Array(x5011)
val x5013 = {
x5012.zip(x4205).foreach{ case (v,e) => if (e) x5005.enqueue(v) }
}
}
val x5015 = ()
val x5016 = {
Array(x285)
}
val x5021 = {
{ 
val x4211 = {
x3901 + x4194
}
val x5017 = {
x4211 * x4588
}
val x5018 = {
x5017 + x3903
}
val x5019 = {
if (x422) x5016.update(0, x5018)
}
()
 }
 
()
}
val x5022 = {
x5016.apply(0)
}
val x5023 = {
for (i <- 0 until x3195.toInt) { if (i + x5022.toInt < x4592.length) x4592(i + x5022.toInt) = x5005.dequeue() }
}
}
val x5025 = ()
}
val x5027 = ()
()
 }
 
()
}
}}
val x5031 = ()
()
 }
 
()
}

x5033
}}

/**********/

