#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <stdlib.h>
#include "hardware/uart.h"

#include "config.h"
#include "event.h"

typedef struct {
    int counter;
} GameModel;

GameModel* model_init();
void model_update(GameModel *model, Event e);
int get_data(GameModel *model);

void _handle_left(GameModel *model);
void _handle_right(GameModel *model);
void _handle_func(GameModel *model);
void _handle_start(GameModel *model);

#endif
