#include "game_model.h"

volatile GameModel* init_model() {
    volatile GameModel *model = malloc(sizeof(GameModel));

    init_tetromino_shapes();
    init_tetromino_colors();

    CompositeShape* background = init_composite_shape();
    // Game board area
    add_shape(background, (Shape*)init_rect(
        (UInt16Pair) { GAMEBOARD_START_X, GAMEBOARD_START_Y },
        (UInt16Pair) { GAMEBOARD_WIDTH, GAMEBOARD_HEIGHT},
        rgb565(136, 136, 136))
    );
    // Next tetris area
    add_shape(background, (Shape*)init_label(
        (UInt16Pair) { NEXT_TETROMINO_LABEL_START_X, NEXT_TETROMINO_LABEL_START_Y },
        "Next", 1,
        rgb565(255, 255, 255))
    );
    // Hold tetris area
    add_shape(background, (Shape*)init_label(
        (UInt16Pair) { HOLD_TETROMINO_LABEL_START_X, HOLD_TETROMINO_LABEL_START_Y },
        "Hold",
        1,
        rgb565(255, 255, 255))
    );
    // Score area
    add_shape(background, (Shape*)init_label(
        (UInt16Pair) { SCORE_LABEL_START_X, SCORE_LABEL_START_Y },
        "Score",
        1,
        rgb565(255, 255, 255))
    );
    add_shape(background, (Shape*)init_label(
        (UInt16Pair) { SCORE_VALUE_START_X, SCORE_VALUE_START_Y },
        "0",
        1,
        rgb565(255, 255, 255))
    );

    Tetromino* cur_tetromino = init_tetromino(TETROMINO_I, coord2Pixel((UInt16Pair) { 3, 0 }));

    model->background = background;
    model->cur_tetromino = cur_tetromino;
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
    int num_shapes = 2;

    CompositeShape** comp_shapes = malloc(sizeof(CompositeShape*) * num_shapes);
    comp_shapes[0] = model->background;
    comp_shapes[1] = model->cur_tetromino->shape;

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
