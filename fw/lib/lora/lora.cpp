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


