#include "gps.h"
#include "pinout.h" //fix this pls
#include "global_defines.h"
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


}



void gps_power(bool turnOn){
    if(turnOn){
        digitalWrite(GPS_EN_PIN, HIGH);
		gpsSerial.begin(9600);
    }else{
     digitalWrite(GPS_EN_PIN, LOW);   
    }    
}


bool gps_reset(unsigned long millisTime){
    static unsigned long currentTime = millisTime;
    static bool isResetting = false;

    if(!isResetting){
        digitalWrite(GPS_RESET_SIGNAL, HIGH);
        currentTime = millisTime;
        isResetting = true;
        return false;
    }
    if(millisTime-currentTime >= GPS_RESET_MS){
        digitalWrite(GPS_RESET_SIGNAL, LOW);
        isResetting = false;
        return true;
    }
    
}



bool isPointInPolygon(float (&a2darr)[2][50], float pointX, float pointY, uint8_t nVertices)
{
uint8_t minXinPoly = 0; //randomly 
uint8_t minYinPoly = 0;
uint8_t maxYinPoly = 0;
uint8_t maxXinPoly = 0;
//find min/max points
//loop through x. 
for (uint8_t x = 0; x < sizeof(a2darr) / sizeof(a2darr[0]); x++) {
	if (a2darr[0][x] < minXinPoly) {
		minXinPoly = a2darr[0][x];
	}
	if (a2darr[0][x] > maxXinPoly) {
		maxXinPoly = a2darr[0][x];
	}
}
//loop through y.
for (uint8_t y = 0; y < sizeof(a2darr[0]) / sizeof(float); y++) {
	if (a2darr[1][y] < minYinPoly) {
		minYinPoly = a2darr[1][y];
	}
	if (a2darr[1][y] > maxYinPoly) {
		maxYinPoly = a2darr[1][y];
	}
}
uint8_t counter = 0;

 //check if it's even worth calculating the position
if ((!(pointX < minXinPoly && pointY < minYinPoly)) && (!(pointX <minXinPoly && pointY > maxYinPoly)) && (!(pointX > maxXinPoly && pointY < minYinPoly)) && (!(pointX > maxXinPoly && pointY > maxYinPoly)) ){
	//j will be prev vert. i current
	//0 DOES count as a vertice. so true verts are nvert-1
	//this is already dealt with since arrays start with 0. e.g a2darr[nverts-1] is the last vert
	for (uint8_t i = 0, j = nVertices - 1; i < nVertices; j = i++) {
		
		if (a2darr[1][i] != a2darr[1][j]) {
			float lamda = (float)(a2darr[1][j] - a2darr[1][i]) / (float)(a2darr[0][j] - a2darr[0][i]);
			float xIntercept = (pointY - a2darr[1][i]) / lamda + a2darr[0][i];
			if (pointX < xIntercept || a2darr[0][i]==a2darr[0][j]) {
				//CHECK if pointY is between the the i and j vertices, otherwise it will increment the counter for every line it passes along the way
				if ((pointY < a2darr[1][j] && pointY > a2darr[1][i])  || (pointY > a2darr[1][j] && pointY < a2darr[1][i])) {
					counter++;
				}
			}
		} 
	}

}

    if (!counter%2){
        return false; //point is IN poly if we get odd result
    }
    return true; //even result = point NOT in poly
}


