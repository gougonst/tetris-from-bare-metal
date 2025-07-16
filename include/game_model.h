#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <stdlib.h>
#include "hardware/uart.h"

#include "composite_shape.h"
#include "config.h"
#include "event.h"
#include "label.h"
#include "rect.h"
#include "shape.h"
#include "utils.h"

typedef struct {
    CompositeShape* background;
    int score;
} GameModel;

volatile GameModel* init_model();
void free_model(volatile GameModel *model);

void update_model(volatile GameModel *model, Event e);
CompositeShapeArray* get_shapes(volatile GameModel *model);

void _handle_left(volatile GameModel *model);
void _handle_right(volatile GameModel *model);
void _handle_func(volatile GameModel *model);
void _handle_start(volatile GameModel *model);

#endif
