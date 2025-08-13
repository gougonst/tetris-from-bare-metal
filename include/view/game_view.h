#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <stdio.h>
#include <stdlib.h>

#include "gfx.h"

#include "config.h"
#include "composite_shape.h"
#include "gfx_graphics.h"
#include "graphics.h"
#include "label.h"
#include "pair.h"
#include "rect.h"
#include "shape.h"
#include "utils.h"

typedef struct GameView {
    Graphics* graphics;
    CompositeShapeArray* shapes;
    int counter;
} GameView;

volatile GameView* init_view();
void free_view(volatile GameView* view);

void update_view(volatile GameView* view, CompositeShapeArray* shapes, int counter);
void show_view(volatile GameView* view);

void _draw_composite_shape_array(volatile GameView* view);
void _draw_shape(volatile GameView* view, Shape* shape);
void _draw_rect(volatile GameView* view, Shape* shape);
void _draw_label(volatile GameView* view, Shape* shape);

#endif
