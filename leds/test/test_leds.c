#include "unity.h"
#include "leds.h"

/* Test para saber que todo funciona al inicio
void test_inicializacion(void){
    TEST_FAIL_MESSAGE("Empezamos");
}
*/

void setUp(void){

}

void tearDown(void){

}

void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}
