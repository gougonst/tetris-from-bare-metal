#ifndef TETROMINO_H
#define TETROMINO_H

#include "uthash.h"

#include "composite_shape.h"
#include "constants.h"
#include "pair.h"
#include "rect.h"
#include "shape.h"
#include "utils.h"

#define TETROMINO_BLOCK_NUM 4
#define ROTATION_STATE_NUM 4

typedef enum RotationState {
    ROTATION_0,
    ROTATION_90,
    ROTATION_180,
    ROTATION_270,
} RotationState;

typedef enum TetrominoType {
    TETROMINO_I,
    TETROMINO_J,
    TETROMINO_L,
    TETROMINO_O,
    TETROMINO_S,
    TETROMINO_T,
    TETROMINO_Z,
} TetrominoType;

typedef enum Direction {
    DIRECTION_LEFT,
    DIRECTION_RIGHT
} Direction;

typedef struct TetrominoShape {
    TetrominoType type;
    // rotation state * tetromino block number * coordinates
    uint16_t shapes[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];
    UT_hash_handle hh;
} TetrominoShape;

typedef struct TetrominoColor {
    TetrominoType type;
    uint16_t color;
    UT_hash_handle hh;
} TetrominoColor;


typedef struct Tetromino {
    CompositeShape* shape;
    uint16_t x;
    uint16_t y;
    RotationState rotation;
    TetrominoType type;
} Tetromino;

extern const uint16_t TETROMINO_I_COLOR[3];
extern const uint16_t TETROMINO_I_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];

extern const uint16_t TETROMINO_J_COLOR[3];
extern const uint16_t TETROMINO_J_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];

extern const uint16_t TETROMINO_L_COLOR[3];
extern const uint16_t TETROMINO_L_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];

extern const uint16_t TETROMINO_O_COLOR[3];
extern const uint16_t TETROMINO_O_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];

extern const uint16_t TETROMINO_S_COLOR[3];
extern const uint16_t TETROMINO_S_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];

extern const uint16_t TETROMINO_T_COLOR[3];
extern const uint16_t TETROMINO_T_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];

extern const uint16_t TETROMINO_Z_COLOR[3];
extern const uint16_t TETROMINO_Z_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2];

extern TetrominoColor* tetromino_colors;
extern TetrominoShape* tetromino_shapes;

void init_tetromino_shapes();
void init_tetromino_colors();
void free_tetromino_shapes();
void free_tetromino_colors();

Tetromino* init_tetromino(TetrominoType type, UInt16Pair pixel);
void move(Tetromino* tetromino, Direction direction);
void rotate(Tetromino* tetromino);

#endif
