#include "composite_shape.h"

CompositeShape* init_composite_shape() {
    CompositeShape* comp_shape = (CompositeShape*)malloc(sizeof(CompositeShape));
    comp_shape->num_shapes = 0;
    comp_shape->max_shapes = INIT_NUM_SHAPES;

    comp_shape->shapes = malloc(sizeof(Shape*) * INIT_NUM_SHAPES);
    memset(comp_shape->shapes, 0, sizeof(Shape*) * INIT_NUM_SHAPES);
    return comp_shape;
}

// Dynamic array
void add_shape(CompositeShape* comp_shape, Shape* new_shape) {
    int num_shapes = comp_shape->num_shapes;
    int max_shapes = comp_shape->max_shapes;

    if (num_shapes < max_shapes) {
        comp_shape->shapes[num_shapes] = new_shape;
    }
    else {
        Shape** append_shapes = malloc(sizeof(Shape*) * (max_shapes * 2));
        for (int i = 0; i < max_shapes; i++)
            append_shapes[i] = comp_shape->shapes[i];
        append_shapes[max_shapes] = new_shape;
        memset(comp_shape->shapes + max_shapes + 1, 0, sizeof(Shape*) * (max_shapes * 2 - 1));
        free(comp_shape->shapes);

        comp_shape->shapes = append_shapes;
        comp_shape->max_shapes = max_shapes * 2;
    }
    comp_shape->num_shapes++;
}

void free_composite_shape(CompositeShape* comp_shape) {
    for (int i = 0; i < comp_shape->num_shapes; i++)
        free(comp_shape->shapes[i]);
    free(comp_shape->shapes);
    free(comp_shape);
}

// If you need to free all shapes, you need to call free_composite_shape() first
void free_composite_shape_array(CompositeShapeArray* comp_shape) {
    free(comp_shape->shapes);
    free(comp_shape);
}
