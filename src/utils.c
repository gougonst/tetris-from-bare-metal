#include "utils.h"

uint16_t rgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8 |
            (g & 0xFC) << 3|
            (b & 0xF8) >> 3);
}
