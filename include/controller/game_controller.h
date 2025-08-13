#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <stdlib.h>

#include "button.h"
#include "game_model.h"
#include "game_view.h"

typedef struct GameController {
    volatile GameModel* _model;
    volatile GameView* _view;
} GameController;

volatile GameController* init_controller(volatile GameModel* model, volatile GameView* view);
void free_controller(volatile GameController* controller);

void game_loop(volatile GameController* controller);

#endif
