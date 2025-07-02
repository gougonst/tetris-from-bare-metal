#include "pico/stdlib.h"
#include "hardware/uart.h"

#include "ili9341.h"
#include "gfx.h"

#include "controller.h"
#include "uart.h"

#define INPUT_DELAY 1000

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

    LCD_setPins(11, 13, 10, 6, 7);
    LCD_initDisplay();
    LCD_setRotation(0);
    GFX_createFramebuf();
    uart_puts(UART_ID, "LCD init finished.\r\n");

    controller_init();
    uart_puts(UART_ID, "Controller init finished.\r\n");

    int counter = 0;
    while (true) {
        controller_poll();
        GFX_clearScreen();
        GFX_setCursor(100, 200);
        GFX_printf("Hello GFX! %d\n", counter++);
        GFX_flush();
        sleep_ms(INPUT_DELAY);
    }

    controller_teardown();
    uart_puts(UART_ID, "controller teardown finished.\r\n");
}
