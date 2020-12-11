#include "topic_gen.h"
#include <string.h>
#include <stdio.h>

// La estructura del topico deberia ser: [NODO_ID]/[sensor_t.id]/[sensor_t.tipo]/[sensor_t.label]
void genTopic(sensor_t *sensor)
{
    char label_l[10];
    uint8_t index_end;

    strcpy(label_l, sensor->label);
    index_end = strlen(label_l);

    for (uint8_t i = 0; i < index_end; i++)
    {
        if (label_l[i] >= 'A' && label_l[i] <= 'Z' || label_l[i] == '#' || label_l[i] == '$' || label_l[i] == '+')
        {
            strcpy(label_l, "error");
            break;
        }
    }

    sprintf(sensor->topic, "%s/%d/%d/%s", NODO_ID, sensor->id, sensor->tipo, label_l);
    printf(sensor->topic);
}