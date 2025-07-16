#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

#include "graphics.h"

typedef enum {
    RECT,
    LABEL
} ShapeType;

typedef struct {
    ShapeType shape_type;
    uint16_t color;
    uint16_t x;
    uint16_t y;
} Shape;

#endif
