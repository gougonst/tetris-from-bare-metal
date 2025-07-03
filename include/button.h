#ifndef BUTTON_H
#define BUTTON_H

#include "pico/stdlib.h"
#include "uthash.h"
#include "config.h"
#include "event.h"

typedef enum {
    PRESSED = 0,
    RELEASED = 1
} ButtonState;

typedef struct {
    int id;
    ButtonState state;
    UT_hash_handle hh;
} ButtonRecord;

extern ButtonRecord *BUTTON_RECORDS;

void update_button_record(int id, ButtonState state);
ButtonState get_button_record(int id);

typedef struct {
    int id;
    Event event;
    UT_hash_handle hh;
} Button;

extern Button *BUTTONS;

void button_init();
void button_teardown();
Event button_poll();

#endif
