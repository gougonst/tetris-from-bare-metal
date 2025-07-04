#include "game_controller.h"

volatile GameController* controller_init(volatile GameModel* model, volatile GameView* view) {
    volatile GameController* controller = malloc(sizeof(GameController));
    controller->_model = model;
    controller->_view = view;
    return controller;
}

void game_loop(volatile GameController* controller) {
    volatile GameView* view = controller->_view;
    volatile GameModel* model = controller->_model;

    while (true) {
        Event event = button_poll();
        model_update(model, event);
        int counter = get_data(model);
        if (counter % 20 == 0) {
            int counter = get_data(model);
            view_update(view, counter / 20);
        }
        sleep_ms(INPUT_DELAY);
    }
}
