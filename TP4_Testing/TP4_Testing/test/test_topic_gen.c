#include "unity.h"
#include "topic_gen.h"
#include "../src/tiposSensores.h"

// La estructura del topico deberia ser: [NODO_ID]/[sensor_t.id]/[sensor_t.tipo]/[sensor_t.label]
sensor_t sensor1;

// Generar topicos sin caracteres '+' '$' '#'
void test_case_1()
{
    TEST_FAIL_MESSAGE("FALLA CASO 1");
}

// Generar topicos sin '/' al inicio
void test_case_2()
{
    TEST_FAIL_MESSAGE("FALLA CASO 2");
}

// Generar topicos sin '/' al final
void test_case_3()
{
    TEST_FAIL_MESSAGE("FALLA CASO 3");
}

// Generar topicos con 4 niveles
void test_case_4()
{
    TEST_FAIL_MESSAGE("FALLA CASO 4");
}

// Generar topicos que contengan minusculas unicamente.
void test_case_5()
{
    TEST_FAIL_MESSAGE("FALLA CASO 5");
}

// Generar topicos con la palabra 'ERROR' si falta algun parametro
void test_case_6()
{
    TEST_FAIL_MESSAGE("FALLA CASO 6");
}

// Generar topicos con 12 caracteres en el parametro [NODO_ID] (puede que tenga '0' como primer caracter y se este ignorando)
void test_case_7()
{
    TEST_FAIL_MESSAGE("FALLA CASO 7");
}

// Generar topicos con [NODO_ID]/[sensor_t.id]/E/L en caso que el topico exceda el tamanho del buffer
void test_case_8()
{
    TEST_FAIL_MESSAGE("FALLA CASO 8");
}