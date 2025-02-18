#ifndef POWER_H
#define POWER_H
#include <stdint.h>
#include "global_defines.h"

void setupHSEclock();




uint16_t getVrefVoltage();
uint16_t getTempMCU();
uint16_t getSupercapVolt();


uint16_t getActualVref();

//Enable/Disable power to LORA chip while acting as a backup for the MCU, in case power dies
void LoraPower(bool turnOn);


void supercapChargeControl(Supercap *chrg_res);
bool checkVDDAWithinlimits(uint32_t *currentTime, uint32_t vddaMillisecondCheckTime);







#endif