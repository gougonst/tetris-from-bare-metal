#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

#include "pair.h"

typedef struct Graphics {
    void (*clear)();
    void (*flush)();
    void (*draw_rect)(UInt16Pair pixel, UInt16Pair size, uint16_t color);
    void (*draw_label)(UInt16Pair pixel, const char *text);
} Graphics;

#endif
