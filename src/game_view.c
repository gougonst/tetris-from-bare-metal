#include "game_view.h"

volatile GameView* view_init() {
    volatile GameView* view = malloc(sizeof(GameView));
    view->counter = 0;
    return view;
}

void view_update(volatile GameView* view, int counter) {
    view->counter = counter;
}

void view_show(volatile GameView* view) {
    uint8_t refresh_delay = 1000 / REFRESH_RATE;

    while (true) {
        GFX_clearScreen();
        GFX_setCursor(100, 200);
        GFX_printf("Hello GFX! %d\n", view->counter);
        GFX_flush();
        sleep_ms(refresh_delay);
    }
}
