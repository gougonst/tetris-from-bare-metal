#ifndef LABEL_H
#define LABEL_H

#include <stdlib.h>

#include "graphics.h"
#include "shape.h"

typedef struct {
    Shape base;
    char* text;
    uint16_t size;
} Label;

Label* init_label(uint16_t x, uint16_t y, char text[], uint16_t size, uint16_t color);

#endif
