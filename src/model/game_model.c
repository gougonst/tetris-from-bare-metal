#include "game_model.h"

volatile GameModel* init_model() {
    volatile GameModel *model = malloc(sizeof(GameModel));

    CompositeShape* background = init_composite_shape();
    // Game board area
    add_shape(background, (Shape*)init_rect(10, 10, 150, 300, rgb565(136, 136, 136)));
    // Next tetris area
    add_shape(background, (Shape*)init_label(186, 13, "Next", 1, rgb565(255, 255, 255)));
    // Hold tetris area
    add_shape(background, (Shape*)init_label(186, 118, "Hold", 1, rgb565(255, 255, 255)));
    // Score area
    add_shape(background, (Shape*)init_label(183, 235, "Score", 1, rgb565(255, 255, 255)));
    add_shape(background, (Shape*)init_label(183, 250, "0", 1, rgb565(255, 255, 255)));

    model->background = background;
    model->score = 0;
    return model;
}

void free_model(volatile GameModel *model) {
    free_composite_shape(model->background);
    free((void *)model);
}

void update_model(volatile GameModel *model, Event e) {
    switch (e) {
    case EVENT_LEFT:
        _handle_left(model);
        break;
    case EVENT_RIGHT:
        _handle_right(model);
        break;
    case EVENT_FUNC:
        _handle_func(model);
        break;
    case EVENT_START:
        _handle_start(model);
        break;
    default:
        model->score++;
        break;
    }
}

CompositeShapeArray* get_shapes(volatile GameModel *model) {
    int num_shapes = 1;

    CompositeShape** comp_shapes = malloc(sizeof(CompositeShape*) * num_shapes);
    comp_shapes[0] = model->background;

    CompositeShapeArray* comp_shape_arr = (CompositeShapeArray*)malloc(sizeof(CompositeShapeArray));
    comp_shape_arr->shapes = comp_shapes;
    comp_shape_arr->num_shapes = num_shapes;
    return comp_shape_arr;
}

void _handle_left(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Left\r\n");
}

void _handle_right(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Right\r\n");
}

void _handle_func(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Func\r\n");
}

void _handle_start(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Start\r\n");
}
