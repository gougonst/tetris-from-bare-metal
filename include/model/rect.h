#ifndef RECT_H
#define RECT_H

#include <stdlib.h>

#include "graphics.h"
#include "pair.h"
#include "shape.h"

typedef struct Rect {
    Shape base;
    UInt16Pair size;
} Rect;

Rect* init_rect(UInt16Pair pixel, UInt16Pair size, uint16_t color);

#endif
