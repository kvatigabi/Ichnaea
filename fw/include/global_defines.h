#ifndef global_defines_h
#define global_defines_h
#include "pinout.h"

enum supercap{
    LOW_RES_HIGHPOW = HighPowCapChrg,
    HIGH_RES_LOWPOW = LowPowCapChrg,
    DISABLE_CHARGE
};




#define GPS_RESET_MS 100 // milliseconds need to reset GPS

#endif