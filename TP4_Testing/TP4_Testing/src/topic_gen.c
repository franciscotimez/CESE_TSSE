#include "topic_gen.h"

// La estructura del topico deberia ser: [NODO_ID]/[sensor_t.id]/[sensor_t.tipo]/[sensor_t.label]
void genTopic(sensor_t *sensor)
{
    char label_l[LABEL_LENGTH];
    char id_label_l[ERROR_LENGTH];

    uint8_t index_end;

    strcpy(label_l, sensor->label);
    index_end = strlen(label_l);

    if (index_end != 0)
    {
        for (uint8_t i = 0; i < index_end; i++)
        {
            if (label_l[i] >= 'A' && label_l[i] <= 'Z' || label_l[i] == '#' || label_l[i] == '$' || label_l[i] == '+')
            {
                strcpy(label_l, ERROR_MSG);
                break;
            }
        }
    }
    else
        strcpy(label_l, ERROR_MSG);

    if (sensor->id == 0)
        strcpy(id_label_l, ERROR_MSG);
    else
        sprintf(id_label_l, "%d", sensor->id);

    if ((strlen(NODO_ID) + strlen(id_label_l) + strlen(etiqueta_point[sensor->tipo]) + strlen(label_l) + 3) > TOPIC_LENGTH)
        sprintf(sensor->topic, "%s/%s/e/l", NODO_ID, id_label_l);
    else
        sprintf(sensor->topic, "%s/%s/%s/%s", NODO_ID, id_label_l, etiqueta_point[sensor->tipo], label_l);

    printf("TopicGen--> %s, length: %d", sensor->topic, index_end);
}