#include "game_model.h"

volatile GameModel* init_model() {
    volatile GameModel *model = malloc(sizeof(GameModel));

    init_tetromino_shapes();
    init_tetromino_colors();

    CompositeShape* background = init_composite_shape();
    // Game board area
    add_shape(background, (Shape*)init_rect(
        (Int16Pair) { GAMEBOARD_START_X, GAMEBOARD_START_Y },
        (Int16Pair) { GAMEBOARD_WIDTH, GAMEBOARD_HEIGHT},
        rgb565(136, 136, 136))
    );
    // Next tetris area
    add_shape(background, (Shape*)init_label(
        (Int16Pair) { NEXT_TETROMINO_LABEL_START_X, NEXT_TETROMINO_LABEL_START_Y },
        "Next", 1,
        rgb565(255, 255, 255))
    );
    // Hold tetris area
    add_shape(background, (Shape*)init_label(
        (Int16Pair) { HOLD_TETROMINO_LABEL_START_X, HOLD_TETROMINO_LABEL_START_Y },
        "Hold",
        1,
        rgb565(255, 255, 255))
    );
    // Score area
    add_shape(background, (Shape*)init_label(
        (Int16Pair) { SCORE_LABEL_START_X, SCORE_LABEL_START_Y },
        "Score",
        1,
        rgb565(255, 255, 255))
    );
    add_shape(background, (Shape*)init_label(
        (Int16Pair) { SCORE_VALUE_START_X, SCORE_VALUE_START_Y },
        "0",
        1,
        rgb565(255, 255, 255))
    );

    Int16Pair tetromino_pixel;
    if (coord2Pixel((Int16Pair) { 3, 0 }, &tetromino_pixel) != EOK) {
        // Handle coord2Pixel error
    }
    Tetromino* tetromino = init_tetromino(TETROMINO_I, tetromino_pixel);

    model->background = background;
    model->score = 0;
    model->tetrominos = create_stack();
    push(model->tetrominos, tetromino);

    for (int i = 0; i < GAMEBOARD_ROWS; i++) {
        for (int j = 0; j < GAMEBOARD_COLS; j++) {
            model->game_board[i][j] = false;
        }
    }
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
    // Num of shapes = 1 (background) + num of tetrominos
    int num_shapes = 1 + model->tetrominos->size;

    CompositeShape** comp_shapes = malloc(sizeof(CompositeShape*) * num_shapes);
    // The first shape needs to be the background, because it is the base layer
    comp_shapes[0] = model->background;
    // Iterate through the stack of tetrominos
    StackNode* node = model->tetrominos->top;
    for (int i = 1; i < num_shapes; i++) {
        comp_shapes[i] = ((Tetromino*) node->data)->shape;
        node = node->next;
    }

    CompositeShapeArray* comp_shape_arr = (CompositeShapeArray*)malloc(sizeof(CompositeShapeArray));
    comp_shape_arr->shapes = comp_shapes;
    comp_shape_arr->num_shapes = num_shapes;
    return comp_shape_arr;
}

void _handle_left(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Left\r\n");
    move((Tetromino*)top(model->tetrominos), ((GameModel*)model)->game_board, DIRECTION_LEFT);
}

void _handle_right(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Right\r\n");
    move((Tetromino*)top(model->tetrominos), ((GameModel*)model)->game_board, DIRECTION_RIGHT);
}

void _handle_func(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Func\r\n");
    rotate((Tetromino*)top(model->tetrominos), ((GameModel*)model)->game_board);
}

void _handle_start(volatile GameModel *model) {
    uart_puts(UART_ID, "Click Start\r\n");
}
