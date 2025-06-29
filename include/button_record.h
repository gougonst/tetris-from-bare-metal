#ifndef BUTTON_RECORD_H
#define BUTTON_RECORD_H

#include "uthash.h"

#define NUM_BTN 4

typedef enum {
    BTN_RIGHT_ID = 14,
    BTN_LEFT_ID = 15,
    BTN_ROTATE_ID = 16,
    BTN_FUNC_ID = 17
} ButtonID;

typedef struct {
    int id;
    int state;
    UT_hash_handle hh;
} ButtonRecord;

typedef enum {
    PRESSED = 0,
    RELEASED = 1
} ButtonState;

extern ButtonRecord *BUTTON_RECORDS;

void update_button_record(ButtonID id, ButtonState state);
ButtonState get_button_record(ButtonID id);
void release_button_records();

#endif
