#include "power.h"
#include "pinout.h"
#include <Arduino.h>
#include "global_defines.h"





//Setut HSE clock
//return false if failed
bool setupHSEclock(){


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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    return false;
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

 if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK){
    return false;
 }

}

uint16_t getVrefVoltage(){
  return analogRead(AVREF);
}

uint16_t getTempMCU(){
  return analogRead(ATEMP);
}

void calculateActualVref(uint16_t (&vref), uint16_t (&actualVref)){

  actualVref = VREFINT_CAL_VREF*((*VREFINT_CAL_ADDR)/(vref));

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


void supercapChargeControl(supercap chrg_res){

  static bool arePinsInitialized = false;
  if(!arePinsInitialized){
    pinMode(HighPowCapChrg, OUTPUT);
    pinMode(LowPowCapChrg, OUTPUT);
    arePinsInitialized = true;
  }
switch (chrg_res)
{
case LOW_RES_HIGHPOW:
  digitalWrite(HighPowCapChrg, HIGH);
  digitalWrite(LowPowCapChrg, LOW);
  break;
case HIGH_RES_LOWPOW:
  digitalWrite(HighPowCapChrg, LOW);
  digitalWrite(LowPowCapChrg, HIGH);
case DISABLE_CHARGE:
  digitalWrite(HighPowCapChrg, LOW);
  digitalWrite(LowPowCapChrg, LOW);
default:
  digitalWrite(HighPowCapChrg, LOW);
  digitalWrite(LowPowCapChrg, LOW);
  break;
}

}

