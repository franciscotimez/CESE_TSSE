#include "unity.h"
#include <stdint.h>
#include <stdbool.h>
#include "leds.h"

/* Test para saber que todo funciona al inicio
void test_inicializacion(void){
    TEST_FAIL_MESSAGE("Empezamos");
}
*/

uint16_t ledsVirtuales;
bool error_informado = false;

void  RegistrarError(void){
    error_informado = true;
}

void setUp(void){
    Leds_Create(&ledsVirtuales, RegistrarError);
}

void tearDown(void){

}

// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void){
    ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales, RegistrarError);
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
void test_apagar_todos(void){
    Leds_On_All();
    Leds_Off_All();
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede consultar el estado de un LED.
void test_consultar_uno_apagado(void){
    TEST_ASSERT_FALSE(Leds_State(15));
}

// Se puede consultar el estado de un LED.
void test_consultar_uno_encendido(void){
    Leds_On(4);
    TEST_ASSERT_TRUE(Leds_State(4));
}