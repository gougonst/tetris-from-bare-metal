#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#include "constants.h"
#include "errno.h"
#include "pair.h"

int16_t rgb565(uint8_t r, uint8_t g, uint8_t b);
int coord2Pixel(Int16Pair coord, Int16Pair* pixel);
int pixel2Coord(Int16Pair pixel, Int16Pair* coord);

#endif
