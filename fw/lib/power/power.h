#ifndef POWER_H
#define POWER_H
#include <stdint.h>
#include "global_defines.h"

bool setupHSEclock();

uint16_t getVrefVoltage();
uint16_t getTempMCU();
uint16_t getSupercapVolt();


void calculateActualVref(uint32_t (&vref), uint32_t(&actualVref));

//Enable/Disable power to LORA chip while acting as a backup for the MCU, in case power dies
void LoraPower(bool turnOn);


void supercapChargeControl(supercap chrg_res);








#endif