#include "pinout.h"
#include "global_defines.h"
#include <Arduino.h>
#include "gps.h"
#include "lora.h"
#include "power.h"
#include <NMEAGPS.h>


#ifdef ICHNAE_V1 //v1 needs SoftSerial as it's gps pins are wrong
#include <SoftwareSerial.h>
SoftwareSerial gpsSerial(GPS_RX_USART1, GPS_TX_USART1);
#else
HardwareSerial gpsSerial(GPS_RX_USART1, GPS_TX_USART1);
#endif

enum STATE{
    STARTUP,
    RUNNING,
    NAV_SEARCH,
    DATA_SEND
    
};

NMEAGPS gps;
gps_fix currentFix;

STATE craftState;
supercap supercap;


void setup(){
gps_setup();
gpsSerial.begin(9600);
supercapChargeControl(DISABLE_CHARGE);

craftState = STARTUP;
}

void loop(){





switch (craftState)
{
case STARTUP:
    /* code */
    
    break;

default:
    break;
}



}