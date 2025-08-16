#ifndef GFX_INTERFACE_H
#define GFX_INTERFACE_H

#include <stdlib.h>

#include "gfx.h"

#include "graphics.h"
#include "pair.h"

typedef struct GFXGraphics {
    Graphics base;
} GFXGraphics;

GFXGraphics* init_gfx_graphics();
void free_gfx_graphics(GFXGraphics* graphics);
void gfx_clear();
void gfx_flush();
void gfx_draw_rect(Int16Pair pixel, Int16Pair size, int16_t color);
void gfx_draw_label(Int16Pair pixel, const char *text);

#endif
