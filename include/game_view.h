#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"

#include "config.h"
#include "gfx_graphics.h"
#include "graphics.h"
#include "utils.h"

typedef struct {
    Graphics* graphics;
    int counter;
} GameView;

volatile GameView* view_init();
void view_update(volatile GameView* view, int counter);
void view_show(volatile GameView* view);

#endif
