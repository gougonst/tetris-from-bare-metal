#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <stdlib.h>
#include "hardware/uart.h"

#include "config.h"
#include "event.h"

typedef struct {
    int counter;
} GameModel;

volatile GameModel* model_init();
void model_update(volatile GameModel *model, Event e);
int get_data(volatile GameModel *model);

void _handle_left(volatile GameModel *model);
void _handle_right(volatile GameModel *model);
void _handle_func(volatile GameModel *model);
void _handle_start(volatile GameModel *model);

#endif
