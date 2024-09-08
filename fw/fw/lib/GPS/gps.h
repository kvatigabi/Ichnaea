#ifndef gps_h
#define gps_h

//#define GPS_RESET_MS 100 // milliseconds need to reset GPS
//Initialize GPS and comms
extern void gps_setup();

//control GPS power
//true: Enable power
//false: Disable power
extern void gps_power(bool turnOn);

//GPS reset. millis input
bool gps_reset(unsigned long currentTime);

//algorithm to check if a point (our coordinates) are in a polygon
//needed to know if we can transmit from our current positon
//polygon must be 2x50 
bool isPointInPolygon(float(&a2darr)[2][50], float pointX, float pointY, int nVertices);


#endif