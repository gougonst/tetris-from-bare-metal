#include "pico/stdlib.h"
#include "hardware/uart.h"

#include "config.h"
#include "button.h"
#include "game_controller.h"
#include "game_model.h"
#include "game_view.h"
#include "monitor.h"

int main() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
    gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));
    uart_puts(UART_ID, "UART init finished.\r\n");

    monitor_init();
    uart_puts(UART_ID, "Monitor init finished.\r\n");

    button_init();
    uart_puts(UART_ID, "Button init finished.\r\n");

    GameModel *model = model_init();
    GameView *view = view_init();
    GameController* controller = controller_init(model, view);

    game_loop(controller);

    button_teardown();
    uart_puts(UART_ID, "Button teardown finished.\r\n");
}
