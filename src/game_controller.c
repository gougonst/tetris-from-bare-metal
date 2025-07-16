#include "game_controller.h"

volatile GameController* init_controller(volatile GameModel* model, volatile GameView* view) {
    volatile GameController* controller = malloc(sizeof(GameController));
    controller->_model = model;
    controller->_view = view;
    return controller;
}

void free_controller(volatile GameController* controller) {
    free((void *)controller);
}

void game_loop(volatile GameController* controller) {
    volatile GameView* view = controller->_view;
    volatile GameModel* model = controller->_model;

    while (true) {
        Event event = poll_button();
        update_model(model, event);
        CompositeShapeArray* shapes = get_shapes(model);
        update_view(view, shapes, 0);
        sleep_ms(INPUT_DELAY);
    }
}
