#include <stdint.h>
#include <stdbool.h>

typedef void (*LedError_t)(void);

void Leds_Create(uint16_t * puerto, LedError_t handler);
void Leds_On(uint8_t led);
void Leds_Off(uint8_t led);
void Leds_On_All(void);
void Leds_Off_All(void);
bool Leds_State(uint8_t led);

