#include "button_record.h"

ButtonRecord *BUTTON_RECORDS = NULL;

void update_button_record(ButtonID id, ButtonState state) {
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

ButtonState get_button_record(ButtonID id) {
    ButtonRecord *button_record;
    HASH_FIND_INT(BUTTON_RECORDS, &id, button_record);
    return button_record == NULL ? -1 : button_record->state;
}

void release_button_records() {
    ButtonRecord *cur, *tmp;
    HASH_ITER(hh, BUTTON_RECORDS, cur, tmp) {
        HASH_DEL(BUTTON_RECORDS, cur);
        free(cur);
    }
}
