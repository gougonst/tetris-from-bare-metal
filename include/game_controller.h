#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <stdlib.h>
#include "hardware/uart.h"

#include "button.h"

#include "game_model.h"
#include "game_view.h"

typedef struct {
    volatile GameModel* _model;
    volatile GameView* _view;
} GameController;

volatile GameController* controller_init(volatile GameModel* model, volatile GameView* view);
void game_loop(volatile GameController* controller);

#endif
