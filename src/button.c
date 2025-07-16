#include "button.h"

ButtonRecord *BUTTON_RECORDS = NULL;
Button *BUTTONS = NULL;

void update_button_record(int id, ButtonState state) {
    ButtonRecord *button_record;
    HASH_FIND_INT(BUTTON_RECORDS, &id, button_record);
    if (button_record == NULL) {
        button_record = malloc(sizeof(ButtonRecord));
        button_record->id = id;
        button_record->state = state;
        HASH_ADD_INT(BUTTON_RECORDS, id, button_record);
    }
    else {
        button_record->state = state;
    }
}

ButtonState get_button_record(int id) {
    ButtonRecord *button_record;
    HASH_FIND_INT(BUTTON_RECORDS, &id, button_record);
    return button_record == NULL ? -1 : button_record->state;
}

void init_button() {
    int btn_ids[NUM_BTN] = {BTN_RIGHT_ID, BTN_LEFT_ID, BTN_FUNC_ID, BTN_START_ID};
    Event btn_events[NUM_BTN] = {EVENT_RIGHT, EVENT_LEFT, EVENT_FUNC, EVENT_START};
    for (int i = 0; i < NUM_BTN; i++) {
        int id = btn_ids[i];
        Button *btn = malloc(sizeof(Button));
        btn->id = id;
        btn->event = btn_events[i];
        HASH_ADD_INT(BUTTONS, id, btn);

        update_button_record(id, RELEASED);
    }

    Button *cur, *tmp;
    HASH_ITER(hh, BUTTONS, cur, tmp) {
        int id = cur->id;
        gpio_init(id);
        gpio_set_dir(id, GPIO_IN);
        gpio_pull_up(id);
    }
}

void free_button() {
    ButtonRecord *cur_btn_record, *tmp_btn_record;
    HASH_ITER(hh, BUTTON_RECORDS, cur_btn_record, tmp_btn_record) {
        HASH_DEL(BUTTON_RECORDS, cur_btn_record);
        free(cur_btn_record);
    }

    Button *cur_btn, *tmp_btn;
    HASH_ITER(hh, BUTTONS, cur_btn, tmp_btn) {
        HASH_DEL(BUTTONS, cur_btn);
        free(cur_btn);
    }
}

Event poll_button() {
    Button *cur, *tmp;
    HASH_ITER(hh, BUTTONS, cur, tmp) {
        int id = cur->id;
        ButtonState cur_state = (ButtonState)gpio_get(id);
        ButtonState last_state = get_button_record(id);

        // Update when the state changed to avoid rapid clicks.
        if (last_state == RELEASED && cur_state == PRESSED) {
            update_button_record(id, PRESSED);
            return cur->event;
        }
        else if (last_state == PRESSED && cur_state == RELEASED) {
            update_button_record(id, RELEASED);
        }
    }
    return EVENT_NONE;
}
