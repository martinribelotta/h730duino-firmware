#include "version.h"

#ifndef __COMPILER_VERSION__
#ifdef __GNUC__
#define __COMPILER_VERSION__ "GCC " __VERSION__
#elif defined(__clang__)
#define __COMPILER_VERSION__ __VERSION__
#elif defined(__ARMCC_VERSION)
#define STR(x) _STR(x)
#define _STR(x) #x
#define __COMPILER_VERSION__ "ARMCC " STR((__ARMCC_VERSION / 1000000)) "." STR(((__ARMCC_VERSION / 100000) % 100)) "." STR((__ARMCC_VERSION % 10000))
#else
#ifdef __VERSION__
#define __COMPILER_VERSION__ __VERSION__
#else
#define __COMPILER_VERSION__ "Unknown"
#endif
#endif
#endif

const char VERSION_STRING[] = "Compiled on " __DATE__ " " __TIME__ " with " __COMPILER_VERSION__;
