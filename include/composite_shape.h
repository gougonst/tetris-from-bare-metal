#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hardware/uart.h"

#include "config.h"
#include "graphics.h"
#include "shape.h"

#define INIT_NUM_SHAPES 5

typedef struct {
    int num_shapes;
    int max_shapes;
    Shape** shapes;
} CompositeShape;

typedef struct {
    int num_shapes;
    CompositeShape** shapes;
} CompositeShapeArray;

CompositeShape* init_composite_shape();
void add_shape(CompositeShape* comp_shape, Shape* new_shape);
void draw_composite_shape(CompositeShape* comp_shape, Graphics* graphics);
void free_composite_shape(CompositeShape* comp_shape);
void free_composite_shape_array(CompositeShapeArray* comp_shape);


#endif
