#include "leds.h"

#define LEDS_ALL_OFF 0x0000

void Leds_Create(uint16_t * puerto){
    *puerto = LEDS_ALL_OFF;
}