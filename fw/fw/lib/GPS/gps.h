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



#endif