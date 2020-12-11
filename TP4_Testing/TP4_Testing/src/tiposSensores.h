#ifndef TIPOS_SENSORES__H
#define TIPOS_SENSORES__H

#include <stdint.h>
#define TOPIC_LENGTH 60
#define NODO_ID "0123456789ab"

// Tipos de sensores admitidos en el sistema
typedef enum{
    DHT22,
    DHT11,
    MAX6675,
    D_O,        // Digital Output
    D_I_P       // Digital Input Pull-up
}tipo_t;

// Estructura de condiguracion del sensor
typedef struct{
    uint8_t     id;
    tipo_t      tipo;
    uint8_t     pin;        // pin asociado al sensor (en caso del MAX6675 no aplica)
    uint32_t    periodo;    // Periodo de muestreo del sensor
    char        label[10];  // Etiqueta para el sensor
    char        topic[TOPIC_LENGTH];   // Topico al que se envian los datos (esto deberia generarse de acuerdo a los datos anteriores)
} sensor_t;

// La estructura del topico deberia ser: [NODO_ID]/[sensor_t.id]/[sensor_t.tipo]/[sensor_t.label]
#endif