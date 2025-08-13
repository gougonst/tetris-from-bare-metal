#ifndef LABEL_H
#define LABEL_H

#include <stdlib.h>

#include "graphics.h"
#include "pair.h"
#include "shape.h"

typedef struct Label {
    Shape base;
    char* text;
    uint16_t size;
} Label;

Label* init_label(UInt16Pair pixel, char text[], uint16_t size, uint16_t color);

#endif
