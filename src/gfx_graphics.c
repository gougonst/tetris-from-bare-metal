#include "gfx_graphics.h"

GFXGraphics* init_gfx_graphics() {
    GFXGraphics* graphics = (GFXGraphics*)malloc(sizeof(GFXGraphics));
    graphics->base.clear = gfx_clear;
    graphics->base.flush = gfx_flush;
    graphics->base.draw_rect = gfx_draw_rect;
    graphics->base.draw_label = gfx_draw_label;
    return graphics;
}

void gfx_clear() {
    GFX_clearScreen();
}

void gfx_flush() {
    GFX_flush();
}

void gfx_draw_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    GFX_fillRect(x, y, w, h, color);
}

void gfx_draw_label(int16_t x, int16_t y, const char *text) {
    GFX_setCursor(x, y);
    GFX_printf(text);
}
