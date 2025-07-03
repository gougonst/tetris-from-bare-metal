#ifndef CONFIG_H
#define CONFIG_H

// Button GPIO ID
#define NUM_BTN 4

#define BTN_LEFT_ID 14
#define BTN_RIGHT_ID 15
#define BTN_FUNC_ID 16
#define BTN_START_ID 17

// Monitor GPIO ID
#define MONITOR_DC_ID 11
#define MONITOR_CS_ID 13
#define MONITOR_RST_ID 10
#define MONITOR_SCK_ID 6
#define MONITOR_MOSI_ID 7

// UART setting
#define UART_ID uart0
#define BAUD_RATE 115200

#define UART_TX_PIN 0
#define UART_RX_PIN 1

// Game setting
#define INPUT_DELAY 50

#endif
