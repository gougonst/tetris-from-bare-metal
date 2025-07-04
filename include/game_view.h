#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <stdlib.h>
#include "gfx.h"

#include "config.h"

typedef struct {
    int counter;
} GameView;

volatile GameView* view_init();
void view_update(volatile GameView* view, int counter);
void view_show(volatile GameView* view);

#endif
