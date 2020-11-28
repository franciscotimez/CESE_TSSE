#include "unity.h"
#include "leds.h"

/* Test para saber que todo funciona al inicio
void test_inicializacion(void){
    TEST_FAIL_MESSAGE("Empezamos");
}
*/

uint16_t ledsVirtuales;

void setUp(void){
    Leds_Create(&ledsVirtuales);
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
    
    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(1, ledsVirtuales);
}

// Se puede apagar un LED individual.
void test_apagar_led_individual(void){
     Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED’s.
void test_prender_apagar_multiples(void){
    Leds_On(3);
    Leds_On(4);
    Leds_Off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 3, ledsVirtuales);
}

// Se pueden prender todos los LEDs de una vez.
void test_prender_todos(void){
    Leds_On_All();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez.
// Se puede consultar el estado de un LED.