#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

#include "graphics.h"

typedef struct Shape {
    uint16_t color;
    uint16_t x;
    uint16_t y;

    void (*draw)(struct Shape*, Graphics*);
} Shape;

#endif
