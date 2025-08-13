#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#include "constants.h"
#include "pair.h"

uint16_t rgb565(uint8_t r, uint8_t g, uint8_t b);
UInt16Pair coord2Pixel(UInt16Pair coord);

#endif
