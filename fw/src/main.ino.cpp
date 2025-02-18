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
Supercap supercapState;


void setup(){

//gps_setup();
//gpsSerial.begin(9600);
setupHSEclock();
supercapState = DISABLE_CHARGE;
craftState = STARTUP;


supercapChargeControl(&supercapState);

}

void loop(){
static uint32_t currentTime = millis();


switch (craftState){
    case STARTUP:
        //proceed after VDD is above MINIMUM_VDDA_STARTUP
        if(checkVDDAWithinlimits(&currentTime, VDDA_CHECK_DELAY)){
            craftState = RUNNING;
        }

    case RUNNING:
    //must make sure supercap is ready before we proceed with NAV_SEARCH


    case NAV_SEARCH:


    case DATA_SEND:


    default:
        break;
    
    
    }



}