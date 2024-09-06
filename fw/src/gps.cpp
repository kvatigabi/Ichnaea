#include "gps.h"
#include "pinout.h"
#include <Arduino.h>

#ifdef ICHNAE_V1 //v1 needs SoftSerial as it's gps pins are wrong
#include <SoftwareSerial.h>
SoftwareSerial gpsSerial(GPS_RX_USART1, GPS_TX_USART1);
#else
HardwareSerial gpsSerial(GPS_RX_USART1, GPS_TX_USART1);
#endif


void gps_setup(){
    pinMode(GPS_EN_PIN, OUTPUT);
    pinMode(GPS_RESET_SIGNAL, OUTPUT);
    gps_enable(true);
    gpsSerial.begin(9600);

}

void gps_enable(bool turnOn){
    if(turnOn){
        digitalWrite(GPS_EN_PIN, HIGH);
    }else{
     digitalWrite(GPS_EN_PIN, LOW);   
    }    
}

bool gps_reset(unsigned long currentTime){
    currentTime = 0; 
    digitalWrite(GPS_RESET_SIGNAL, HIGH); 
    if(currentTime>= 50){
        digitalWrite(GPS_RESET_SIGNAL, LOW);
    }
}