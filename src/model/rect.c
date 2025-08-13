#include "rect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "hardware/uart.h"

Rect* init_rect(UInt16Pair pixel, UInt16Pair size, uint16_t color) {
    Rect* rect = (Rect*)malloc(sizeof(Rect));
    rect->base.shape_type = RECT;
    rect->base.pixel = pixel;
    rect->size = size;
    rect->base.color = color;
    return rect;
}
