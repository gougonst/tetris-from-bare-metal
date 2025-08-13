#include "tetromino.h"

const uint16_t TETROMINO_I_COLOR[3] = {0, 0, 255};
const uint16_t TETROMINO_I_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}}, // Rotation 0
    {{2, 0}, {2, 1}, {2, 2}, {2, 3}}, // Rotation 90
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}}, // Rotation 180
    {{1, 0}, {1, 1}, {1, 2}, {1, 3}}  // Rotation 270
};

const uint16_t TETROMINO_J_COLOR[3] = {255, 0, 0};
const uint16_t TETROMINO_J_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, // Rotation 0
    {{1, 0}, {2, 0}, {1, 1}, {1, 2}}, // Rotation 90
    {{0, 1}, {1, 1}, {2, 1}, {2, 2}}, // Rotation 180
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}}  // Rotation 270
};

const uint16_t TETROMINO_L_COLOR[3] = {0, 255, 0};
const uint16_t TETROMINO_L_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}}, // Rotation 0
    {{1, 0}, {1, 1}, {1, 2}, {2, 2}}, // Rotation 90
    {{0, 1}, {0, 2}, {1, 1}, {2, 1}}, // Rotation 180
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}}  // Rotation 270
};

const uint16_t TETROMINO_O_COLOR[3] = {255, 136, 0};
const uint16_t TETROMINO_O_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}, // Rotation 0
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}, // Rotation 90
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}, // Rotation 180
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}  // Rotation 270
};

const uint16_t TETROMINO_S_COLOR[3] = {255, 255, 0};
const uint16_t TETROMINO_S_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}}, // Rotation 0
    {{1, 0}, {1, 1}, {2, 1}, {2, 2}}, // Rotation 90
    {{0, 2}, {1, 2}, {1, 1}, {2, 1}}, // Rotation 180
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}}  // Rotation 270
};

const uint16_t TETROMINO_T_COLOR[3] = {255, 0, 255};
const uint16_t TETROMINO_T_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}}, // Rotation 0
    {{2, 1}, {1, 0}, {1, 1}, {1, 2}}, // Rotation 90
    {{1, 2}, {0, 1}, {1, 1}, {2, 1}}, // Rotation 180
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}}  // Rotation 270
};

const uint16_t TETROMINO_Z_COLOR[3] = {0, 255, 255};
const uint16_t TETROMINO_Z_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, // Rotation 0
    {{2, 0}, {2, 1}, {1, 1}, {1, 2}}, // Rotation 90
    {{0, 1}, {1, 1}, {1, 2}, {2, 2}}, // Rotation 180
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}}  // Rotation 270
};

TetrominoColor* tetromino_colors = NULL;
TetrominoShape* tetromino_shapes = NULL;

void init_tetromino_shapes() {
    TetrominoShape* t_shape;

    t_shape = malloc(sizeof(TetrominoShape));
    t_shape->type = TETROMINO_I;
    memcpy(t_shape->shapes, TETROMINO_I_SHAPE, sizeof(TETROMINO_I_SHAPE));
    HASH_ADD_INT(tetromino_shapes, type, t_shape);

    t_shape = malloc(sizeof(TetrominoShape));
    t_shape->type = TETROMINO_J;
    memcpy(t_shape->shapes, TETROMINO_J_SHAPE, sizeof(TETROMINO_J_SHAPE));
    HASH_ADD_INT(tetromino_shapes, type, t_shape);

    t_shape = malloc(sizeof(TetrominoShape));
    t_shape->type = TETROMINO_L;
    memcpy(t_shape->shapes, TETROMINO_L_SHAPE, sizeof(TETROMINO_L_SHAPE));
    HASH_ADD_INT(tetromino_shapes, type, t_shape);

    t_shape = malloc(sizeof(TetrominoShape));
    t_shape->type = TETROMINO_O;
    memcpy(t_shape->shapes, TETROMINO_O_SHAPE, sizeof(TETROMINO_O_SHAPE));
    HASH_ADD_INT(tetromino_shapes, type, t_shape);

    t_shape = malloc(sizeof(TetrominoShape));
    t_shape->type = TETROMINO_S;
    memcpy(t_shape->shapes, TETROMINO_S_SHAPE, sizeof(TETROMINO_S_SHAPE));
    HASH_ADD_INT(tetromino_shapes, type, t_shape);

    t_shape = malloc(sizeof(TetrominoShape));
    t_shape->type = TETROMINO_T;
    memcpy(t_shape->shapes, TETROMINO_T_SHAPE, sizeof(TETROMINO_T_SHAPE));
    HASH_ADD_INT(tetromino_shapes, type, t_shape);

    t_shape = malloc(sizeof(TetrominoShape));
    t_shape->type = TETROMINO_Z;
    memcpy(t_shape->shapes, TETROMINO_Z_SHAPE, sizeof(TETROMINO_Z_SHAPE));
    HASH_ADD_INT(tetromino_shapes, type, t_shape);
}

void init_tetromino_colors() {
    TetrominoColor* t_color;

    t_color = malloc(sizeof(TetrominoColor));
    t_color->type = TETROMINO_I;
    t_color->color = rgb565(TETROMINO_I_COLOR[0], TETROMINO_I_COLOR[1], TETROMINO_I_COLOR[2]);
    HASH_ADD_INT(tetromino_colors, type, t_color);

    t_color = malloc(sizeof(TetrominoColor));
    t_color->type = TETROMINO_J;
    t_color->color = rgb565(TETROMINO_J_COLOR[0], TETROMINO_J_COLOR[1], TETROMINO_J_COLOR[2]);
    HASH_ADD_INT(tetromino_colors, type, t_color);

    t_color = malloc(sizeof(TetrominoColor));
    t_color->type = TETROMINO_L;
    t_color->color = rgb565(TETROMINO_L_COLOR[0], TETROMINO_L_COLOR[1], TETROMINO_L_COLOR[2]);
    HASH_ADD_INT(tetromino_colors, type, t_color);

    t_color = malloc(sizeof(TetrominoColor));
    t_color->type = TETROMINO_O;
    t_color->color = rgb565(TETROMINO_O_COLOR[0], TETROMINO_O_COLOR[1], TETROMINO_O_COLOR[2]);
    HASH_ADD_INT(tetromino_colors, type, t_color);

    t_color = malloc(sizeof(TetrominoColor));
    t_color->type = TETROMINO_S;
    t_color->color = rgb565(TETROMINO_S_COLOR[0], TETROMINO_S_COLOR[1], TETROMINO_S_COLOR[2]);
    HASH_ADD_INT(tetromino_colors, type, t_color);

    t_color = malloc(sizeof(TetrominoColor));
    t_color->type = TETROMINO_T;
    t_color->color = rgb565(TETROMINO_T_COLOR[0], TETROMINO_T_COLOR[1], TETROMINO_T_COLOR[2]);
    HASH_ADD_INT(tetromino_colors, type, t_color);

    t_color = malloc(sizeof(TetrominoColor));
    t_color->type = TETROMINO_Z;
    t_color->color = rgb565(TETROMINO_Z_COLOR[0], TETROMINO_Z_COLOR[1], TETROMINO_Z_COLOR[2]);
    HASH_ADD_INT(tetromino_colors, type, t_color);
}

void free_tetromino_shapes() {
    TetrominoShape* cur_shape, *tmp;
    HASH_ITER(hh, tetromino_shapes, cur_shape, tmp) {
        HASH_DEL(tetromino_shapes, cur_shape);
        free(cur_shape);
    }
}

void free_tetromino_colors() {
    TetrominoColor* cur_color, *tmp;
    HASH_ITER(hh, tetromino_colors, cur_color, tmp) {
        HASH_DEL(tetromino_colors, cur_color);
        free(cur_color);
    }
}

Tetromino* init_tetromino(TetrominoType type, UInt16Pair pixel) {
    uint16_t x = pixel.first;
    uint16_t y = pixel.second;

    // Get the tetromino shape based on its type and rotation
    uint16_t tetromino_shape[TETROMINO_BLOCK_NUM][2];
    TetrominoShape* t_shape;
    HASH_FIND_INT(tetromino_shapes, &type, t_shape);
    memcpy(tetromino_shape, t_shape->shapes[ROTATION_0], sizeof(tetromino_shape));

    // Get the tetromino color based on its type
    uint16_t color;
    TetrominoColor* t_color;
    HASH_FIND_INT(tetromino_colors, &type, t_color);
    color = t_color->color;

    // Initialize the composite shape for the tetromino
    CompositeShape* shape = init_composite_shape();
    for (int i = 0; i < TETROMINO_BLOCK_NUM; i++) {
        uint16_t x_offset = tetromino_shape[i][0] * TETROMINO_CELL_SIZE;
        uint16_t y_offset = tetromino_shape[i][1] * TETROMINO_CELL_SIZE;
        Rect* rect = init_rect(
            (UInt16Pair) {
                .first = x + x_offset,
                .second = y + y_offset
            },
            (UInt16Pair) {
                .first = TETROMINO_CELL_SIZE,
                .second = TETROMINO_CELL_SIZE
            },
            color
        );
        add_shape(shape, (Shape*)rect);
    }

    Tetromino* tetromino = malloc(sizeof(Tetromino));
    tetromino->x = x;
    tetromino->y = y;
    tetromino->rotation = ROTATION_0;
    tetromino->type = type;
    tetromino->shape = shape;
    return tetromino;
}

void move(Tetromino* tetromino, Direction direction) {

}

void rotate(Tetromino* tetromino) {

}
