#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "pico/stdlib.h"
#include "uthash.h"
#include "button_record.h"
#include "tetris_model.h"

typedef struct {
    ButtonID id;
    void (*callback)(void);
    UT_hash_handle hh;
} Button;

extern Button *BUTTONS;

void controller_init();
void controller_poll();
void controller_teardown();

#endif
