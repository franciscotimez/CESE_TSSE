#include "topic_gen.h"
#include <string.h>

void genTopic(sensor_t *sensor)
{
    strcpy(sensor->topic, "0123456789AB/123/DHT22/Sens1");
}