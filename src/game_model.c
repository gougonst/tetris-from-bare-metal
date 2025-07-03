#include "game_model.h"

GameModel* model_init() {
    GameModel *model = malloc(sizeof(GameModel));
    model->counter = 0;
    return model;
}

void model_update(GameModel *model, Event e) {
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
        model->counter++;
        break;
    }
}

int get_data(GameModel *model) {
    return model->counter;
}

void _handle_left(GameModel *model) {
    uart_puts(UART_ID, "Click Left\r\n");
}

void _handle_right(GameModel *model) {
    uart_puts(UART_ID, "Click Right\r\n");
}

void _handle_func(GameModel *model) {
    uart_puts(UART_ID, "Click Func\r\n");
}

void _handle_start(GameModel *model) {
    uart_puts(UART_ID, "Click Start\r\n");
}
