#include "game_controller.h"

GameController* controller_init(GameModel* model, GameView* view) {
    GameController* controller = malloc(sizeof(GameController));
    controller->_model = model;
    controller->_view = view;
    return controller;
}

void game_loop(GameController* controller) {
    GameView* view = controller->_view;
    GameModel* model = controller->_model;

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
