#include "cpphelperFuncs.h"
void  kernel_x4792(resourceInfo_t *resourceInfo,int32_t  x286, int32_t  x4, int32_t  x303, cppDeliteArraycppDeliteArrayint32_t  *x4279, cppDeliteArrayint32_t  *x4493, int32_t  x4326, cppDeliteArrayint32_t  *x4533, cppDeliteArrayint32_t  *x4318, int32_t  x6, int32_t  x2, int32_t  x5) {
for(int32_t i=x286; i<x4; i+=x303) {
int32_t x472 = i;
int32_t  x538 = x4326;
assert(x538 < (size_t)-1);
cppDeliteArrayint32_t *x4584 = new (resourceInfo) cppDeliteArrayint32_t(x538, resourceInfo);
cppDeliteArrayint32_t * x4620_data = x4584;
int32_t  x4620_size = 0;
int32_t  x4620_conditionals = 0;
int32_t  x473 = 0;
while (x473 < x4326) {  // begin fat loop x4620
cppDeliteArrayint32_t *x4534 = x4279->apply(x473);
int32_t x4535 = x4534->length;
int32_t  x484 = x4535;
assert(x484 < (size_t)-1);
cppDeliteArrayint32_t *x4540 = new (resourceInfo) cppDeliteArrayint32_t(x484, resourceInfo);
cppDeliteArrayint32_t * x4576_data = x4540;
int32_t  x4576_size = 0;
int32_t  x4576_conditionals = 0;
int32_t  x477 = 0;
while (x477 < x4535) {  // begin fat loop x4576
int32_t x4536 = x4493->apply(x477);
int32_t x4537 = x4534->apply(x477);
int32_t  x4538 = x4537 * x4536;
int32_t x483 = x4538;
cppDeliteArrayint32_t *x482 = x4576_data;
x482->update(x477, x483);
x477 = x477 + 1;
} // end fat loop x4576
cppDeliteArrayint32_t *x482 = x4576_data;
cppDeliteArrayint32_t *x4576 = x482;
int32_t x4577 = x4576->length;
int32_t  x4582_zero = x286;
int32_t  x4582 = x4582_zero;
int32_t  x526 = 0;
if (x4577 > 0) { // prerun fat loop x4582
int32_t x4578 = x4576->apply(x526);
x4582 = x4578;
}
x526 = 1;
while (x526 < x4577) {  // begin fat loop x4582
int32_t x4578 = x4576->apply(x526);
int32_t x531 = x4582;
int32_t x532 = x4578;
int32_t  x533 = x531 + x532;
x4582 = x533;
x526 = x526 + 1;
} // end fat loop x4582
int32_t x537 = x4582;
cppDeliteArrayint32_t *x536 = x4620_data;
x536->update(x473, x537);
x473 = x473 + 1;
} // end fat loop x4620
cppDeliteArrayint32_t *x536 = x4620_data;
cppDeliteArrayint32_t *x4620 = x536;
int32_t x4621 = x4620->length;
int32_t  x586 = x4621;
assert(x586 < (size_t)-1);
cppDeliteArrayint32_t *x4625 = new (resourceInfo) cppDeliteArrayint32_t(x586, resourceInfo);
cppDeliteArrayint32_t * x4661_data = x4625;
int32_t  x4661_size = 0;
int32_t  x4661_conditionals = 0;
int32_t  x580 = 0;
while (x580 < x4621) {  // begin fat loop x4661
int32_t x4622 = x4620->apply(x580);
int32_t x4623 = x4318->apply(x580);
int32_t  x4624 = x4622 - x4623;
int32_t x585 = x4624;
cppDeliteArrayint32_t *x584 = x4661_data;
x584->update(x580, x585);
x580 = x580 + 1;
} // end fat loop x4661
cppDeliteArrayint32_t *x584 = x4661_data;
cppDeliteArrayint32_t *x4661 = x584;
int32_t  x733 = x6;
assert(x733 < (size_t)-1);
cppDeliteArrayint32_t *x4747 = new (resourceInfo) cppDeliteArrayint32_t(x733, resourceInfo);
cppDeliteArrayint32_t * x4783_data = x4747;
int32_t  x4783_size = 0;
int32_t  x4783_conditionals = 0;
int32_t  x627 = 0;
while (x627 < x6) {  // begin fat loop x4783
int32_t x4662 = x4533->apply(x627);
int32_t  x4663 = (int32_t) x4662;
int32_t  x635 = x4326;
assert(x635 < (size_t)-1);
cppDeliteArrayint32_t *x4666 = new (resourceInfo) cppDeliteArrayint32_t(x635, resourceInfo);
cppDeliteArrayint32_t * x4702_data = x4666;
int32_t  x4702_size = 0;
int32_t  x4702_conditionals = 0;
int32_t  x629 = 0;
while (x629 < x4326) {  // begin fat loop x4702
cppDeliteArrayint32_t *x4664 = x4279->apply(x629);
int32_t x4665 = x4664->apply(x4663);
int32_t x634 = x4665;
cppDeliteArrayint32_t *x633 = x4702_data;
x633->update(x629, x634);
x629 = x629 + 1;
} // end fat loop x4702
cppDeliteArrayint32_t *x633 = x4702_data;
cppDeliteArrayint32_t *x4702 = x633;
int32_t  x682 = x4326;
assert(x682 < (size_t)-1);
cppDeliteArrayint32_t *x4706 = new (resourceInfo) cppDeliteArrayint32_t(x682, resourceInfo);
cppDeliteArrayint32_t * x4742_data = x4706;
int32_t  x4742_size = 0;
int32_t  x4742_conditionals = 0;
int32_t  x676 = 0;
while (x676 < x4326) {  // begin fat loop x4742
int32_t x4703 = x4702->apply(x676);
int32_t x4704 = x4661->apply(x676);
int32_t  x4705 = x4703 * x4704;
int32_t x681 = x4705;
cppDeliteArrayint32_t *x680 = x4742_data;
x680->update(x676, x681);
x676 = x676 + 1;
} // end fat loop x4742
cppDeliteArrayint32_t *x680 = x4742_data;
cppDeliteArrayint32_t *x4742 = x680;
int32_t  x4746_zero = x286;
int32_t  x4746 = x4746_zero;
int32_t  x723 = 0;
if (x4326 > 0) { // prerun fat loop x4746
int32_t x4743 = x4742->apply(x723);
x4746 = x4743;
}
x723 = 1;
while (x723 < x4326) {  // begin fat loop x4746
int32_t x4743 = x4742->apply(x723);
int32_t x727 = x4746;
int32_t x728 = x4743;
int32_t  x729 = x727 + x728;
x4746 = x729;
x723 = x723 + 1;
} // end fat loop x4746
int32_t x732 = x4746;
cppDeliteArrayint32_t *x731 = x4783_data;
x731->update(x627, x732);
x627 = x627 + 1;
} // end fat loop x4783
cppDeliteArrayint32_t *x731 = x4783_data;
cppDeliteArrayint32_t *x4783 = x731;
for(int32_t i=x286; i<x5; i+=x303) {
int32_t x774 = i;
int32_t  x775 = (int32_t) x774;
int32_t x4784 = x4493->apply(x775);
int32_t x4785 = x4783->apply(x775);
int32_t  x4786 = x4785 * x2;
int32_t  x4787 = x4786 + x4784;
x4493->update(x775, x4787);
}
}

}

/**********/

