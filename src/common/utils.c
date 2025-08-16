#include "utils.h"

int16_t rgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8 |
            (g & 0xFC) << 3|
            (b & 0xF8) >> 3);
}

int coord2Pixel(Int16Pair coord, Int16Pair* pixel) {
    if (coord.first >= GAMEBOARD_COLS || coord.second >= GAMEBOARD_ROWS) {
        return EINVAL;
    }

    pixel->first = GAMEBOARD_START_X + coord.first * TETROMINO_CELL_SIZE;
    pixel->second = GAMEBOARD_START_Y + coord.second * TETROMINO_CELL_SIZE;
    return EOK;
}

int pixel2Coord(Int16Pair pixel, Int16Pair* coord) {
    int16_t x_offset = pixel.first - GAMEBOARD_START_X;
    int16_t y_offset = pixel.second - GAMEBOARD_START_Y;
    if (x_offset < 0 || x_offset % TETROMINO_CELL_SIZE != 0 ||
        y_offset < 0 || y_offset % TETROMINO_CELL_SIZE != 0) {
        return EINVAL;
    }

    coord->first = x_offset / TETROMINO_CELL_SIZE;
    coord->second = y_offset / TETROMINO_CELL_SIZE;
    if (coord->first >= GAMEBOARD_COLS || coord->second >= GAMEBOARD_ROWS) {
        return EINVAL;
    }
    return EOK;
}
