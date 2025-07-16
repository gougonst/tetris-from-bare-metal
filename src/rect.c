#include "rect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "hardware/uart.h"

Rect* init_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
    Rect* rect = (Rect*)malloc(sizeof(Rect));
    rect->base.shape_type = RECT;
    rect->base.x = x;
    rect->base.y = y;
    rect->w = w;
    rect->h = h;
    rect->base.color = color;
    return rect;
}
