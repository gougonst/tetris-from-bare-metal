#include "utils.h"

uint16_t rgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8 |
            (g & 0xFC) << 3|
            (b & 0xF8) >> 3);
}

UInt16Pair coord2Pixel(UInt16Pair coord) {
    return (UInt16Pair) {
        .first = GAMEBOARD_START_X + coord.first * TETROMINO_CELL_SIZE,
        .second = GAMEBOARD_START_Y + coord.second * TETROMINO_CELL_SIZE
    };
}
