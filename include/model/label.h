#ifndef LABEL_H
#define LABEL_H

#include <stdlib.h>

#include "graphics.h"
#include "pair.h"
#include "shape.h"

typedef struct Label {
    Shape base;
    char* text;
    int16_t size;
} Label;

Label* init_label(Int16Pair pixel, char text[], int16_t size, int16_t color);

#endif
