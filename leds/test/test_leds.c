#include "unity.h"
#include "leds.h"

/* Test para saber que todo funciona al inicio
void test_inicializacion(void){
    TEST_FAIL_MESSAGE("Empezamos");
}
*/

/*
Se deben completar las siguientes pruebas

*/

void setUp(void){

}

void tearDown(void){

}

// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

// Se puede prender un LED individual.
void test_prender_led_individual(void){
    uint16_t ledsVirtuales;
    Leds_Create(&ledsVirtuales);
    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(1, ledsVirtuales);
}

// Se puede apagar un LED individual.
void test_apagar_led_individual(void){
    uint16_t ledsVirtuales;
    Leds_Create(&ledsVirtuales);
    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED’s.
// Se pueden prender todos los LEDs de una vez.
// Se pueden apagar todos los LEDs de una vez.
// Se puede consultar el estado de un LED.