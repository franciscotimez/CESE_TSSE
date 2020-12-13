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
    Sensor3.id = 15;
    Sensor3.tipo = MAX6675;
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
    Sensor4.id = 77;
    Sensor4.tipo = D_I_P;
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
    uint8_t index_end;
    sensor_t Sensor5;
    Sensor5.id = 1;
    Sensor5.tipo = D_O;
    Sensor5.pin = 5;
    Sensor5.periodo = 60;
    strcpy(Sensor5.label, "Sensor5");

    genTopic(&Sensor5);

    index_end = strlen(Sensor5.topic);

    for (uint8_t i = 0; i < index_end; i++)
    {
        if (Sensor5.topic[i] >= 'A' && Sensor5.topic[i] <= 'Z')
            TEST_FAIL_MESSAGE("SE ENCONTRARON MAYUSCULAS");
    }
}

// Generar topicos con la palabra 'error' si falta algun parametro
void test_case_6()
{
    uint8_t index_end;
    sensor_t Sensor6;
    Sensor6.id = 0;
    Sensor6.tipo = error;
    Sensor6.pin = 0;
    Sensor6.periodo = 0;
    strcpy(Sensor6.label, "");

    genTopic(&Sensor6);

    char topicEsperado[] = "0123456789ab/error/error/error";

    TEST_ASSERT_EQUAL_STRING(topicEsperado, Sensor6.topic);
}

// Generar topicos con 12 caracteres en el parametro [NODO_ID] (puede que tenga '0' como primer caracter y se este ignorando)
void test_case_7()
{
    sensor_t Sensor7;
    Sensor7.id = 7;
    Sensor7.tipo = D_I_P;
    Sensor7.pin = 11;
    Sensor7.periodo = 200;
    strcpy(Sensor7.label, "Sensor7");

    genTopic(&Sensor7);

    if (Sensor7.topic[12] != '/')
        TEST_FAIL_MESSAGE("FALLA EN EL CAMPO NODO_ID");
}

// Generar topicos con [NODO_ID]/[sensor_t.id]/e/l en caso que el topico exceda el tamanho del buffer
void test_case_8()
{
    sensor_t Sensor8;
    Sensor8.id = 128;
    Sensor8.tipo = D_O;
    Sensor8.pin = 5;
    Sensor8.periodo = 60;
    strcpy(Sensor8.label, "temp_horno_secado");

    genTopic(&Sensor8);

    char topicEsperado[22] = "0123456789ab/128/e/l";

    TEST_ASSERT_EQUAL_STRING(topicEsperado, Sensor8.topic);
}