#ifndef pinout_h
#define pinout_h
#include <Arduino.h>


//POWER PINS
#define HighPowCapChrg PD0 //High power cap charging circuit (low value resistor). must be open-drain
#define LowPowCapChrg PD1 //Low power cap charging circuit (high value resistor). must be open-drain
#ifdef ICHNAE_V1
#define CAP_CHRG_V_PIN PB1 // ADC_IN9 Cap voltage
#define CAP_CHRG_READ_EN // Enable Cap voltage readout
#else
#define CAP_CHRG_V_PIN AVBAT
#endif



#define DC_EN PB10 //PUSH_PULL enable lora power
#define LORA_RESET PD9 // LORA reset pin
#define GPS_RESET_SIGNAL PC7
#define GPS_EN_PIN PC8 // GPS enable



//LORA
#define LORA_SPI1_NSS PA0 //LORA chipselect
#define LORA_SPI1_MOSI PA2
#define LORA_SPI1_MISO PA6
#define DIO1_pin PB13 //LORA DIO1
#define DIO2_pin PA3 //LORA DIO2
#define DIO0_pin PA7 //LORA DIO0


//COMMS
#define UART2_TX PD5
#define UART2_RX PA15
#define USART3_RX PC11
#define USART3_TX PA5

#ifdef ICHNAE_V1 //V1 board had wrong TX/RX GPS wiring..
#define GPS_RX_USART1 PC5 // GPS Receive (WIRED WRONG FOR VER.1)
#define GPS_TX_USART1 PC4 // GPS transmit (WIRED WRONG FOR VER.1)
//#else if ICHNAE_V2
#else
#define GPS_RX_USART1 PC4 // GPS Receive
#define GPS_TX_USART1 PC5 // GPS transmit
#endif

#define SWDIO PA13
#define SWCLK PA14



//MISC
#define MISC2_pin1 PD6
#define MISC2_pin2 PB3
#define MISC2_pin3 PB4
#define MISC2_pin4 PB5


#define MISC1_pin4 PC12
#define MISC1_pin3 PC13
#define MISC1_pin2 PC14
#define MISC1_pin1 PC15

#define MISC3_pin2 PB11

#define DHT11_DAT PB15 //DHT 11 data pin

//PROBEPOINTS
#define OK_FLAG PB6


#endif