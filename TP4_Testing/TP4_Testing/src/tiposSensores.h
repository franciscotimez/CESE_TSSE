
#ifndef TIPOS_SENSORES__H
#define TIPOS_SENSORES__H

#include <stdint.h>

#define TOPIC_MIN_LENGTH 21 // NO EDITAR!
#define TOPIC_LENGTH 40
#define LABEL_LENGTH 20
#define NODO_ID "0123456789ab"
#define ERROR_MSG "error"
#define ERROR_LENGTH 6

// Tipos de sensores admitidos en el sistema
typedef enum
{
    error,
    DHT22,
    DHT11,
    MAX6675,
    D_O,  // Digital Output
    D_I_P // Digital Input Pull-up
} tipo_t;

static char etiqueta_error[] = "error";
static char etiqueta_DHT22[] = "dht22";
static char etiqueta_DHT11[] = "dht11";
static char etiqueta_MAX6675[] = "max6675";
static char etiqueta_D_O[] = "d_o";
static char etiqueta_D_I_P[] = "d_i_p";

static char *etiqueta_point[] = {etiqueta_error,
                                 etiqueta_DHT22,
                                 etiqueta_DHT11,
                                 etiqueta_MAX6675,
                                 etiqueta_D_O,
                                 etiqueta_D_I_P};

// Estructura de condiguracion del sensor
typedef struct
{
    uint8_t id;
    tipo_t tipo;
    uint8_t pin;              // pin asociado al sensor (en caso del MAX6675 no aplica)
    uint32_t periodo;         // Periodo de muestreo del sensor
    char label[LABEL_LENGTH];           // Etiqueta para el sensor
    char topic[TOPIC_LENGTH]; // Topico al que se envian los datos (esto deberia generarse de acuerdo a los datos anteriores)
} sensor_t;

// La estructura del topico deberia ser: [NODO_ID]/[sensor_t.id]/[sensor_t.tipo]/[sensor_t.label]
#endif