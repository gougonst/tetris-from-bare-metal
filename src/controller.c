#include "controller.h"

Button *BUTTONS = NULL;

void controller_init() {
    ButtonID btn_ids[NUM_BTN] = {BTN_RIGHT_ID, BTN_LEFT_ID, BTN_ROTATE_ID, BTN_FUNC_ID};
    void (*callbacks[NUM_BTN])(void) = {handle_right, handle_left, handle_rotate, handle_func};
    for (int i = 0; i < NUM_BTN; i++) {
        ButtonID id = btn_ids[i];
        Button *btn = malloc(sizeof(Button));
        btn->id = id;
        btn->callback = callbacks[i];
        HASH_ADD_INT(BUTTONS, id, btn);

        update_button_record(id, RELEASED);
    }

    Button *cur, *tmp;
    HASH_ITER(hh, BUTTONS, cur, tmp) {
        ButtonID id = cur->id;
        gpio_init(id);
        gpio_set_dir(id, GPIO_IN);
        gpio_pull_up(id);
    }
}

void controller_poll() {
    Button *cur, *tmp;
    HASH_ITER(hh, BUTTONS, cur, tmp) {
        ButtonID id = cur->id;
        ButtonState cur_state = (ButtonState)gpio_get(id);
        ButtonState last_state = get_button_record(id);

        // Update when the state changed to avoid rapid clicks.
        if (last_state == RELEASED && cur_state == PRESSED) {
            cur->callback();
            update_button_record(id, PRESSED);
        }
        else if (last_state == PRESSED && cur_state == RELEASED) {
            update_button_record(id, RELEASED);
        }
    }
}

void controller_teardown() {
    release_button_records();
}
