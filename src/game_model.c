#include "game_model.h"

volatile GameModel* model_init() {
    volatile GameModel *model = malloc(sizeof(GameModel));
    model->counter = 0;
    return model;
}

void model_update(volatile GameModel *model, Event e) {
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

int get_data(volatile GameModel *model) {
    return model->counter;
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
