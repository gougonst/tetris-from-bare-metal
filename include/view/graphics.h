#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

#include "pair.h"

typedef struct Graphics {
    void (*clear)();
    void (*flush)();
    void (*draw_rect)(Int16Pair pixel, Int16Pair size, int16_t color);
    void (*draw_label)(Int16Pair pixel, const char *text);
} Graphics;

#endif
