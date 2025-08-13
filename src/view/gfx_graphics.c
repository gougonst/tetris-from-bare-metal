#include "gfx_graphics.h"

GFXGraphics* init_gfx_graphics() {
    GFXGraphics* graphics = (GFXGraphics*)malloc(sizeof(GFXGraphics));
    graphics->base.clear = gfx_clear;
    graphics->base.flush = gfx_flush;
    graphics->base.draw_rect = gfx_draw_rect;
    graphics->base.draw_label = gfx_draw_label;
    return graphics;
}

void free_gfx_graphics(GFXGraphics* graphics) {
    free(graphics);
}

void gfx_clear() {
    GFX_clearScreen();
}

void gfx_flush() {
    GFX_flush();
}

void gfx_draw_rect(UInt16Pair pixel, UInt16Pair size, uint16_t color) {
    GFX_fillRect(pixel.first, pixel.second, size.first, size.second, color);
}

void gfx_draw_label(UInt16Pair pixel, const char *text) {
    GFX_setCursor(pixel.first, pixel.second);
    GFX_printf(text);
}
