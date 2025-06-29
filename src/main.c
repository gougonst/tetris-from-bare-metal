#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "controller.h"
#include "uart.h"

#define INPUT_DELAY 10

void pico_led_init() {
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}

void pico_set_led(bool led_on) {
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
}

int main() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
    gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));

    pico_led_init();
    pico_set_led(true);
    uart_puts(UART_ID, "Pico led init finished.\r\n");

    controller_init();
    uart_puts(UART_ID, "Controller init finished.\r\n");

    while (true) {
        controller_poll();
        sleep_ms(INPUT_DELAY);
    }

    controller_teardown();
    uart_puts(UART_ID, "controller teardown finished.\r\n");
}
