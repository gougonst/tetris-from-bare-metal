#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

#include "graphics.h"

typedef struct {
    uint16_t color;
    uint16_t x;
    uint16_t y;

    void (*draw)(Shape*, Graphics*);
} Shape;

#endif
