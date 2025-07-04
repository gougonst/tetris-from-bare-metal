#include "hardware/uart.h"
#include "pico/multicore.h"
#include "pico/stdlib.h"

#include "button.h"
#include "config.h"
#include "game_controller.h"
#include "game_model.h"
#include "game_view.h"
#include "monitor.h"

volatile GameModel* model = NULL;
volatile GameView* view = NULL;
volatile GameController* controller = NULL;

void view_thread_entry() {
    uart_puts(UART_ID, "Start view thread.\r\n");
    view_show(view);
}

int main() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
    gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));
    uart_puts(UART_ID, "UART init finished.\r\n");

    monitor_init();
    uart_puts(UART_ID, "Monitor init finished.\r\n");

    button_init();
    uart_puts(UART_ID, "Button init finished.\r\n");

    model = model_init();
    view = view_init();
    controller = controller_init(model, view);

    multicore_launch_core1(view_thread_entry);

    game_loop(controller);

    button_teardown();
    uart_puts(UART_ID, "Button teardown finished.\r\n");
}
