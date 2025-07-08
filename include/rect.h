#ifndef RECT_H
#define RECT_H

#include <stdlib.h>

#include "graphics.h"
#include "shape.h"

typedef struct {
    Shape base;
    uint16_t w;
    uint16_t h;
} Rect;

Rect* rect_init(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void draw_rect(Shape* shape, Graphics* graphics);

#endif
