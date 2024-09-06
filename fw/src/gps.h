#ifndef gps_h
#define gps_h

//Initialize GPS
extern void gps_setup();

//control GPS power 
extern void gps_power(bool turnOn);

//GPS reset
bool gps_reset(unsigned long currentTime);


#endif