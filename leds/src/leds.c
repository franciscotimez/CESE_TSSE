#include "leds.h"

#define LEDS_ALL_OFF 0x0000

static uint16_t * direccion;

void Leds_Create(uint16_t * puerto){
    direccion = puerto;
    *direccion = LEDS_ALL_OFF;
}

void Leds_On(uint8_t led){
    *direccion = 1;
}

void Leds_Off(uint8_t led){
    *direccion = 0;
}