#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

typedef struct {
    void (*clear)();
    void (*flush)();
    void (*draw_rect)(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void (*draw_label)(int16_t x, int16_t y, const char *text);
} Graphics;

#endif
