#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory>
#include <float.h>
#include <jni.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include "cpptypes.h"
#include "cppactRecords.h"
#include "DeliteCpp.h"
int32_t  kernel_x3(resourceInfo_t *resourceInfo);
int32_t  * kernel_x4026(resourceInfo_t *resourceInfo,int32_t  x3);
string  kernel_x1(resourceInfo_t *resourceInfo,cppDeliteArraystring  *x0);
int32_t  kernel_x2(resourceInfo_t *resourceInfo,string  x1);
void  kernel_x4027(resourceInfo_t *resourceInfo,int32_t   *x4026, int32_t  x2);
int32_t  kernel_x4028(resourceInfo_t *resourceInfo,int32_t   *x4026);
maxjLmem * kernel_x4029(resourceInfo_t *resourceInfo,int32_t  x4028);
maxjLmem * kernel_x4030(resourceInfo_t *resourceInfo,int32_t  x4028);
maxjLmem * kernel_x4031(resourceInfo_t *resourceInfo,int32_t  x4028);
maxjLmem * kernel_x4032(resourceInfo_t *resourceInfo,int32_t  x4028);
maxjLmem * kernel_x4033(resourceInfo_t *resourceInfo,int32_t  x4028);
maxjLmem * kernel_x4034(resourceInfo_t *resourceInfo,int32_t  x4028);
maxjLmem * kernel_x4035(resourceInfo_t *resourceInfo,int32_t  x4028);
int32_t  kernel_x14(resourceInfo_t *resourceInfo,int32_t  x2);
uint32_t  kernel_x16(resourceInfo_t *resourceInfo);
activation_x4074 * kernel_x4074(resourceInfo_t *resourceInfo,int32_t  x14, uint32_t  x16);
activation_x4113 * kernel_x4113(resourceInfo_t *resourceInfo,int32_t  x14);
activation_x4152 * kernel_x4152(resourceInfo_t *resourceInfo,int32_t  x14);
activation_x4191 * kernel_x4191(resourceInfo_t *resourceInfo,int32_t  x14);
activation_x4230 * kernel_x4230(resourceInfo_t *resourceInfo,int32_t  x14);
activation_x4269 * kernel_x4269(resourceInfo_t *resourceInfo,int32_t  x14);
void  kernel_x4270(resourceInfo_t *resourceInfo,maxjLmem  *x4029, cppDeliteArrayuint32_t  *x4074);
void  kernel_x4271(resourceInfo_t *resourceInfo,maxjLmem  *x4030, cppDeliteArrayfloat  *x4113);
void  kernel_x4272(resourceInfo_t *resourceInfo,maxjLmem  *x4031, cppDeliteArrayfloat  *x4152);
void  kernel_x4273(resourceInfo_t *resourceInfo,maxjLmem  *x4032, cppDeliteArrayfloat  *x4191);
void  kernel_x4274(resourceInfo_t *resourceInfo,maxjLmem  *x4033, cppDeliteArrayfloat  *x4230);
void  kernel_x4275(resourceInfo_t *resourceInfo,maxjLmem  *x4034, cppDeliteArrayfloat  *x4269);
int32_t  kernel_x2868(resourceInfo_t *resourceInfo);
uint32_t  kernel_x305(resourceInfo_t *resourceInfo);
float  kernel_x307(resourceInfo_t *resourceInfo);
int32_t  kernel_x316(resourceInfo_t *resourceInfo);
int32_t  kernel_x319(resourceInfo_t *resourceInfo);
float  kernel_x426(resourceInfo_t *resourceInfo);
float  kernel_x423(resourceInfo_t *resourceInfo);
float  kernel_x412(resourceInfo_t *resourceInfo);
float  kernel_x437(resourceInfo_t *resourceInfo);
float  kernel_x428(resourceInfo_t *resourceInfo);
float  kernel_x429(resourceInfo_t *resourceInfo);
float  kernel_x445(resourceInfo_t *resourceInfo);
float  kernel_x443(resourceInfo_t *resourceInfo);
float  kernel_x439(resourceInfo_t *resourceInfo);
float  kernel_x441(resourceInfo_t *resourceInfo);
void  kernel_x4566(resourceInfo_t *resourceInfo,int32_t   *x4026, int32_t  x3, int32_t  x2868, uint32_t  x305, float  x307, int32_t  x316, maxjLmem  *x4029, int32_t  x319, maxjLmem  *x4030, maxjLmem  *x4031, maxjLmem  *x4032, maxjLmem  *x4033, maxjLmem  *x4034, float  x412, float  x423, float  x426, float  x429, float  x428, float  x437, float  x445, float  x443, float  x439, float  x441, maxjLmem  *x4035);
int32_t  kernel_x4567(resourceInfo_t *resourceInfo,int32_t  x4028);
cppDeliteArrayfloat * kernel_x4568(resourceInfo_t *resourceInfo,int32_t  x4567);
void  kernel_x4569(resourceInfo_t *resourceInfo,maxjLmem  *x4035, cppDeliteArrayfloat  *x4568);
void  kernel_x4570(resourceInfo_t *resourceInfo);
int32_t  kernel_x656(resourceInfo_t *resourceInfo,int32_t  x14);
activation_x4693 * kernel_x4693(resourceInfo_t *resourceInfo,int32_t  x14, cppDeliteArrayfloat  *x4113, cppDeliteArrayfloat  *x4152, cppDeliteArrayfloat  *x4269, cppDeliteArrayfloat  *x4191, cppDeliteArrayfloat  *x4230, float  x412, float  x423, float  x426, float  x429, float  x428, float  x437, float  x445, float  x443, float  x439, float  x441, float  x307, cppDeliteArrayuint32_t  *x4074, uint32_t  x305);
void  kernel_x4698(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x656, int32_t  x319, cppDeliteArrayfloat  *x4693);
void  kernel_x4699(resourceInfo_t *resourceInfo);
void  kernel_x4700(resourceInfo_t *resourceInfo);
int32_t  kernel_x4701(resourceInfo_t *resourceInfo,cppDeliteArrayfloat  *x4568);
int32_t  kernel_x4702(resourceInfo_t *resourceInfo,int32_t  x4701);
void  kernel_x4707(resourceInfo_t *resourceInfo,int32_t  x3, int32_t  x4702, int32_t  x319, cppDeliteArrayfloat  *x4568);
void  kernel_x4708(resourceInfo_t *resourceInfo);
activation_x4753 * kernel_x4753(resourceInfo_t *resourceInfo,int32_t  x4701, cppDeliteArrayfloat  *x4568, float  x412, cppDeliteArrayfloat  *x4693);
int32_t  kernel_x4754(resourceInfo_t *resourceInfo,cppDeliteArraybool  *x4753);
bool  kernel_x730(resourceInfo_t *resourceInfo);
activation_x4759 * kernel_x4759(resourceInfo_t *resourceInfo,int32_t  x4754, bool  x730, cppDeliteArraybool  *x4753);
string  kernel_x4760(resourceInfo_t *resourceInfo,bool  x4759);
string  kernel_x4761(resourceInfo_t *resourceInfo,string  x4760);
void  kernel_x4762(resourceInfo_t *resourceInfo,string  x4761);
