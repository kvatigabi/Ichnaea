#ifndef global_defines_h
#define global_defines_h
#include "pinout.h"

enum Supercap{
    LOW_RES_HIGHPOW = HighPowCapChrg,
    HIGH_RES_LOWPOW = LowPowCapChrg,
    DISABLE_CHARGE
};




#define GPS_RESET_MS 100 // milliseconds need to reset GPS
#define MINIMUM_VDDA_STARTUP 3300UL //Minimum voltage needed for craft to exist startup
#define VDDA_CHECK_DELAY 500UL //delay to check VDDA voltage


#endif