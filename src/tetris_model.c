#include "tetris_model.h"

void handle_left() {
    uart_puts(UART_ID, "Click Left\r\n");
}

void handle_right() {
    uart_puts(UART_ID, "Click Right\r\n");
}

void handle_rotate() {
    uart_puts(UART_ID, "Click Rotate\r\n");
}

void handle_func() {
    uart_puts(UART_ID, "Click Function\r\n");
}
