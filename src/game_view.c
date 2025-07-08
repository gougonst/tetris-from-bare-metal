#include "game_view.h"

volatile GameView* view_init() {
    volatile GameView* view = malloc(sizeof(GameView));
    view->graphics = (Graphics*)init_gfx_graphics();
    view->counter = 0;
    return view;
}

void view_update(volatile GameView* view, int counter) {
    view->counter = counter;
}

void view_show(volatile GameView* view) {
    uint8_t refresh_delay = 1000 / REFRESH_RATE;

    while (true) {
        char counter_str[50];
        snprintf(counter_str, sizeof(counter_str), "Hello GFX! %d\n", view->counter);

        view->graphics->clear();
        view->graphics->draw_label(100, 200, counter_str);
        view->graphics->draw_rect(0, 0, 30, 10, rgb565(255, 0, 0));
        view->graphics->flush();
        sleep_ms(refresh_delay);
    }
}
