#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <stdlib.h>
#include "gfx.h"

typedef struct {
    int temp_data;
} GameView;

GameView* view_init();
void view_update(GameView* view, int counter);

#endif
