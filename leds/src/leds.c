#include "leds.h"

#define LEDS_ALL_OFF    0x0000
#define LEDS_ALL_ON     0xFFFF

#define LedToMask(x)    (1 << (x - 1))

static uint16_t * direccion;

void Leds_Create(uint16_t * puerto){
    direccion = puerto;
    *direccion = LEDS_ALL_OFF;
}

void Leds_On(uint8_t led){
    *direccion |= LedToMask(led);
}

void Leds_Off(uint8_t led){
    *direccion &= ~LedToMask(led);
}

void Leds_On_All(void){
    *direccion = LEDS_ALL_ON;
}