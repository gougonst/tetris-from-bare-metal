#ifndef GFX_INTERFACE_H
#define GFX_INTERFACE_H

#include <stdlib.h>

#include "gfx.h"

#include "graphics.h"

typedef struct {
    Graphics base;
} GFXGraphics;

GFXGraphics* init_gfx_graphics();
void free_gfx_graphics(GFXGraphics* graphics);
void gfx_clear();
void gfx_flush();
void gfx_draw_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void gfx_draw_label(int16_t x, int16_t y, const char *text);

#endif
