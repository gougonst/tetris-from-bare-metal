#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <stdlib.h>
#include "hardware/uart.h"

#include "button.h"

#include "game_model.h"
#include "game_view.h"

typedef struct {
    GameModel* _model;
    GameView* _view;
} GameController;

GameController* controller_init(GameModel* model, GameView* view);
void game_loop(GameController* controller);

#endif
