#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct {
    void (*draw_rect)(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void (*draw_label)(const char *format, ...);
} Graphics;

#endif
