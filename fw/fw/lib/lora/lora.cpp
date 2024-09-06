#include "lora.h"
#include <lorawan.h>
#include "pinout.h"

const sRFM_pins rfm_pins = {
  .CS = LORA_SPI1_NSS,
  .RST = LORA_RESET,
  .DIO0 = DIO0_pin,
  .DIO1 = DIO1_pin,  
  .DIO2 = DIO2_pin,
   
};

void LoraPower(bool turnOn){
  //set pinmode if not set
  static bool isModuleTurnedOn = false;
  if(!isModuleTurnedOn){
    pinMode(DC_EN, OUTPUT_PP);
    isModuleTurnedOn = true;
  }

turnOn == true ? digitalWrite(DC_EN, HIGH) : digitalWrite(DC_EN, LOW);
}

