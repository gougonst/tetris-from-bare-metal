#include "game_view.h"

volatile GameView* init_view() {
    volatile GameView* view = malloc(sizeof(GameView));
    view->graphics = (Graphics*)init_gfx_graphics();
    view->counter = 0;
    view->shapes = NULL;
    return view;
}

void free_view(volatile GameView* view) {
    if (view->shapes != NULL)
        free(view->shapes);
    free(view->graphics);
    free((void *)view);
}

void update_view(volatile GameView* view, CompositeShapeArray* shapes, int counter) {
    // if (view->shapes != NULL)
    //     free_composite_shape_array(view->shapes);
    view->counter = counter;
    view->shapes = shapes;
}

void show_view(volatile GameView* view) {
    uint8_t refresh_delay = 1000 / REFRESH_RATE;

    while (true) {
        view->graphics->clear();
        if (view->shapes != NULL) {
            _draw_composite_shape_array(view);
        }
        view->graphics->flush();
        sleep_ms(refresh_delay);
    }
}

void _draw_composite_shape_array(volatile GameView* view) {
    CompositeShapeArray* shapes = view->shapes;

    // Loop all of CompositeShape
    for (int i = 0; i < shapes->num_shapes; i++) {
        // Loop all of Shape
        for (int j = 0; j < shapes->shapes[i]->num_shapes; j++) {
            _draw_shape(view, shapes->shapes[i]->shapes[j]);
        }
    }
}

void _draw_shape(volatile GameView* view, Shape* shape) {
    switch (shape->shape_type) {
    case RECT:
        _draw_rect(view, shape);
        break;
    case LABEL:
        _draw_label(view, shape);
        break;
    default:
        char log[50];
        snprintf(log, 50, "There is no such shape type: %d\r\n", shape->shape_type);
        uart_puts(UART_ID, log);
        break;
    }
}

void _draw_rect(volatile GameView* view, Shape* shape) {
    Graphics* graphics = view->graphics;
    Rect* rect = (Rect*)shape;
    graphics->draw_rect(
        rect->base.pixel,
        rect->size,
        rect->base.color
    );
}

void _draw_label(volatile GameView* view, Shape* shape) {
    // Currently, not support the textsize yet.
    Graphics* graphics = view->graphics;
    Label* label = (Label*)shape;
    graphics->draw_label(
        label->base.pixel,
        label->text
    );
}
