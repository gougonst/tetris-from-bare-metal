#ifndef RECT_H
#define RECT_H

#include <stdlib.h>

#include "graphics.h"
#include "pair.h"
#include "shape.h"

typedef struct Rect {
    Shape base;
    Int16Pair size;
} Rect;

Rect* init_rect(Int16Pair pixel, Int16Pair size, int16_t color);

#endif
