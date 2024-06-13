#pragma once
#include "gps.h"
#include "pinout.h"
#include <NMEAGPS.h>

#ifdef ICHNAE_V1 //v1 needs SoftSerial as it's gps pins are wrong
#include <SoftwareSerial.h>
SoftwareSerial gpsSerial(GPS_RX_USART1, GPS_TX_USART1);
#else
HardwareSerial gpsSerial(GPS_RX_USART1, GPS_TX_USART1);
#endif

gps_fix fix;

void gps_setup(){
    gpsSerial.begin(9600);
    

}