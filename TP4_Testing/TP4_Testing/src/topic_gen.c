#include "topic_gen.h"
#include <string.h>
#include <stdio.h>

// La estructura del topico deberia ser: [NODO_ID]/[sensor_t.id]/[sensor_t.tipo]/[sensor_t.label]
void genTopic(sensor_t *sensor)
{
    char label_l[10];
    char char_invalid[] = "+$#";
    uint8_t i;

    strcpy(label_l, sensor->label);
    i = 0;
    while (char_invalid[i] != '\0')
    {
        if (strchr(sensor->label, char_invalid[i]) != NULL)
        {
            strcpy(label_l, "ERROR");
            break;
        }
        i++;
    }
        
    sprintf(sensor->topic, "%s/%d/%d/%s", NODO_ID, sensor->id, sensor->tipo, label_l);
    printf(sensor->topic);
}