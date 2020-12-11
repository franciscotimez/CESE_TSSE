#include "unity.h"
#include "topic_gen.h"
#include <string.h>
#include "../src/tiposSensores.h"

#define TOPIC_LEVELS 4

// La estructura del topico deberia ser: [NODO_ID]/[sensor_t.id]/[sensor_t.tipo]/[sensor_t.label]
sensor_t sensor1;

// Generar topicos sin caracteres '+' '$' '#'
void test_case_1()
{
    char char_exclude[] = "+$#";
    char message[20];
    uint8_t i;

    sensor_t Sensor1;
    Sensor1.id = 123;
    Sensor1.tipo = DHT22;
    Sensor1.pin = 3;
    Sensor1.periodo = 60;
    strcpy(Sensor1.label, "#S+ens$1");

    genTopic(&Sensor1);

    i = 0;
    while (char_exclude[i] != '\0')
    {
        if (strchr(Sensor1.topic, char_exclude[i]) != NULL)
        {
            sprintf(message, "Se encontro %c", char_exclude[i]);
            TEST_FAIL_MESSAGE(message);
        }
        i++;
    }
}

// Generar topicos sin '/' al inicio
void test_case_2()
{
    sensor_t Sensor2;
    Sensor2.id = 46;
    Sensor2.tipo = DHT11;
    Sensor2.pin = 5;
    Sensor2.periodo = 60;
    strcpy(Sensor2.label, "Sensor2");

    genTopic(&Sensor2);

    if (Sensor2.topic[0] == '/')
        TEST_FAIL_MESSAGE("Se enconctro '/' al inicio");
}

// Generar topicos sin '/' al final 0123456789AB/46/1/Sensor3/
void test_case_3()
{
    uint8_t index;
    sensor_t Sensor3;
    Sensor3.id = 46;
    Sensor3.tipo = DHT11;
    Sensor3.pin = 5;
    Sensor3.periodo = 60;
    strcpy(Sensor3.label, "Sensor3");

    genTopic(&Sensor3);

    index = strlen(Sensor3.topic);

    if (Sensor3.topic[index - 1] == '/')
        TEST_FAIL_MESSAGE("Se enconctro '/' al final");
}

// Generar topicos con 4 niveles
void test_case_4()
{
    char *point_char;
    sensor_t Sensor4;
    Sensor4.id = 46;
    Sensor4.tipo = DHT11;
    Sensor4.pin = 5;
    Sensor4.periodo = 60;
    strcpy(Sensor4.label, "Sensor3");

    genTopic(&Sensor4);

    point_char = Sensor4.topic;

    for (uint8_t i = 0; i < TOPIC_LEVELS - 1; i++)
    {
        point_char = strchr(point_char, '/');
        if (point_char == NULL)
            TEST_FAIL_MESSAGE("NO TIENE 4 NIVELES");
        point_char++;
    }
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