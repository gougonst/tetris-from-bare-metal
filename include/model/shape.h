#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

#include "graphics.h"
#include "pair.h"

typedef enum ShapeType {
    RECT,
    LABEL
} ShapeType;

typedef struct Shape {
    ShapeType shape_type;
    int16_t color;
    Int16Pair pixel;
} Shape;

#endif
