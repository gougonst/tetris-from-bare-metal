#include "game_view.h"

GameView* view_init() {
    GameView* view = malloc(sizeof(GameView));
    return view;
}

void view_update(GameView* view, int counter) {
    GFX_clearScreen();
    GFX_setCursor(100, 200);
    GFX_printf("Hello GFX! %d\n", counter);
    GFX_flush();
}
