#include "power.h"
#include "pinout.h"
#include <Arduino.h>
#include "global_defines.h"





//Setup HSE clock
void setupHSEclock(){

  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


uint16_t getVrefVoltage(){
  return analogRead(AVREF);
}

uint16_t getTempMCU(){
  return analogRead(ATEMP);
}


//Connected to VDD
uint16_t getActualVref(){

  return VREFINT_CAL_VREF*((*VREFINT_CAL_ADDR)/(getVrefVoltage()));

}

uint16_t getSupercapVolt(){
  //multiply by 3 since VBAT has a voltage divider
  return analogRead(CAP_CHRG_V_PIN)*3;

}

void LoraPower(bool turnOn){
  //set pinmode if not set
  static bool isModuleTurnedOn = false;
  if(!isModuleTurnedOn){
    pinMode(DC_EN, OUTPUT_PP);
    isModuleTurnedOn = true;
  }

turnOn == true ? digitalWrite(DC_EN, HIGH) : digitalWrite(DC_EN, LOW);
}


void supercapChargeControl(Supercap *chrg_res){

  static bool arePinsInitialized = false;
  if(!arePinsInitialized){
    pinMode(HighPowCapChrg, OUTPUT);
    pinMode(LowPowCapChrg, OUTPUT);
    arePinsInitialized = true;
  }
switch (*chrg_res)
{
case LOW_RES_HIGHPOW:
  digitalWrite(HighPowCapChrg, HIGH);
  digitalWrite(LowPowCapChrg, LOW);
  break;
case HIGH_RES_LOWPOW:
  digitalWrite(HighPowCapChrg, LOW);
  digitalWrite(LowPowCapChrg, HIGH);
  break;
case DISABLE_CHARGE:
  digitalWrite(HighPowCapChrg, LOW);
  digitalWrite(LowPowCapChrg, LOW);
  break;
default:
  digitalWrite(HighPowCapChrg, LOW);
  digitalWrite(LowPowCapChrg, LOW);
  break;
}

}

//Check every vddaMillisecondCheckTime the voltage on VDDA
//Returns True if getActualVref>=MINIMUM_VDDA_STARTUP
bool checkVDDAWithinlimits(uint32_t *currentTime, uint32_t vddaMillisecondCheckTime){
  static uint32_t prevTime = 0;
  if(*currentTime - prevTime >= vddaMillisecondCheckTime){
    if(getActualVref()>=MINIMUM_VDDA_STARTUP){
      return true;
    } 
  }
  prevTime = *currentTime;
  return false;
}
