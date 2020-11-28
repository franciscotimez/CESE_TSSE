#include "leds.h"

#define LEDS_ALL_OFF    0x0000
#define LEDS_ALL_ON     0xFFFF

#define LED_OFFSET      1
#define LSB             1

static uint16_t * direccion;
static LedError_t RegistrarError;

uint16_t LedToMask(uint8_t x){
    if(x > 16){
        RegistrarError();
        return 0;
    }
    return (LSB << (x - LED_OFFSET));
}

void Leds_Create(uint16_t * puerto, LedError_t handler){
    direccion = puerto;
    RegistrarError = handler;
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

void Leds_Off_All(void){
    *direccion = LEDS_ALL_OFF;
}

bool Leds_State(uint8_t led){
    return *direccion & LedToMask(led);
}