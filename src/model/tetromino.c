#include "tetromino.h"
#include "hardware/uart.h"

const int16_t TETROMINO_I_COLOR[3] = {0, 0, 255};
const int16_t TETROMINO_I_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}}, // Rotation 0
    {{2, 0}, {2, 1}, {2, 2}, {2, 3}}, // Rotation 90
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}}, // Rotation 180
    {{1, 0}, {1, 1}, {1, 2}, {1, 3}}  // Rotation 270
};

const int16_t TETROMINO_J_COLOR[3] = {255, 0, 0};
const int16_t TETROMINO_J_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, // Rotation 0
    {{1, 0}, {2, 0}, {1, 1}, {1, 2}}, // Rotation 90
    {{0, 1}, {1, 1}, {2, 1}, {2, 2}}, // Rotation 180
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}}  // Rotation 270
};

const int16_t TETROMINO_L_COLOR[3] = {0, 255, 0};
const int16_t TETROMINO_L_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}}, // Rotation 0
    {{1, 0}, {1, 1}, {1, 2}, {2, 2}}, // Rotation 90
    {{0, 1}, {0, 2}, {1, 1}, {2, 1}}, // Rotation 180
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}}  // Rotation 270
};

const int16_t TETROMINO_O_COLOR[3] = {255, 136, 0};
const int16_t TETROMINO_O_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}, // Rotation 0
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}, // Rotation 90
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}, // Rotation 180
    {{1, 0}, {2, 0}, {1, 1}, {2, 1}}  // Rotation 270
};

const int16_t TETROMINO_S_COLOR[3] = {255, 255, 0};
const int16_t TETROMINO_S_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}}, // Rotation 0
    {{1, 0}, {1, 1}, {2, 1}, {2, 2}}, // Rotation 90
    {{0, 2}, {1, 2}, {1, 1}, {2, 1}}, // Rotation 180
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}}  // Rotation 270
};

const int16_t TETROMINO_T_COLOR[3] = {255, 0, 255};
const int16_t TETROMINO_T_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}}, // Rotation 0
    {{2, 1}, {1, 0}, {1, 1}, {1, 2}}, // Rotation 90
    {{1, 2}, {0, 1}, {1, 1}, {2, 1}}, // Rotation 180
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}}  // Rotation 270
};

const int16_t TETROMINO_Z_COLOR[3] = {0, 255, 255};
const int16_t TETROMINO_Z_SHAPE[ROTATION_STATE_NUM][TETROMINO_BLOCK_NUM][2] = {
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

Tetromino* init_tetromino(TetrominoType type, Int16Pair pixel) {
    int16_t x = pixel.first;
    int16_t y = pixel.second;

    // Get the tetromino shape based on its type and rotation
    int16_t tetromino_shape[TETROMINO_BLOCK_NUM][2];
    TetrominoShape* t_shape;
    HASH_FIND_INT(tetromino_shapes, &type, t_shape);
    memcpy(tetromino_shape, t_shape->shapes[ROTATION_0], sizeof(tetromino_shape));

    // Get the tetromino color based on its type
    int16_t color;
    TetrominoColor* t_color;
    HASH_FIND_INT(tetromino_colors, &type, t_color);
    color = t_color->color;

    // Initialize the composite shape for the tetromino
    CompositeShape* shape = init_composite_shape();
    for (int i = 0; i < TETROMINO_BLOCK_NUM; i++) {
        int16_t x_offset = tetromino_shape[i][0] * TETROMINO_CELL_SIZE;
        int16_t y_offset = tetromino_shape[i][1] * TETROMINO_CELL_SIZE;
        Rect* rect = init_rect(
            (Int16Pair) {
                .first = x + x_offset,
                .second = y + y_offset
            },
            (Int16Pair) {
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

void move(Tetromino* tetromino, bool game_board[][GAMEBOARD_COLS], Direction direction) {
    // Detect colision for new coordinates
    int16_t x_offset = direction == DIRECTION_LEFT ? -TETROMINO_CELL_SIZE : TETROMINO_CELL_SIZE;
    Int16Pair new_coords[TETROMINO_BLOCK_NUM];
    for (int i = 0; i < TETROMINO_BLOCK_NUM; i++) {
        Shape* rect = tetromino->shape->shapes[i];
        Int16Pair new_pixel = { rect->pixel.first + x_offset, rect->pixel.second };
        pixel2Coord(new_pixel, &new_coords[i]);
    }
    if (is_colision(new_coords, game_board)) {
        return;
    }

    // Move the tetromino
    tetromino->x += x_offset;
    for (int i = 0; i < TETROMINO_BLOCK_NUM; i++) {
        Shape* rect = tetromino->shape->shapes[i];
        rect->pixel.first += x_offset;
    }
}

void rotate(Tetromino* tetromino, bool game_board[][GAMEBOARD_COLS]) {
    RotationState cur_rotation = tetromino->rotation;
    RotationState new_rotation = (cur_rotation + 1) % ROTATION_STATE_NUM;

    // Detect colision for new coordinates
    int16_t tetromino_shape[TETROMINO_BLOCK_NUM][2];
    TetrominoShape* t_shape;
    HASH_FIND_INT(tetromino_shapes, &tetromino->type, t_shape);
    memcpy(tetromino_shape, t_shape->shapes[new_rotation], sizeof(tetromino_shape));

    Int16Pair new_coords[TETROMINO_BLOCK_NUM];
    for (int i = 0; i < TETROMINO_BLOCK_NUM; i++) {
        Int16Pair cur_pixel = { tetromino->x, tetromino->y };
        pixel2Coord(cur_pixel , &new_coords[i]);
        new_coords[i].first += tetromino_shape[i][0];
        new_coords[i].second += tetromino_shape[i][1];
    }
    if (is_colision(new_coords, game_board)) {
        return;
    }

    tetromino->rotation = new_rotation;
    for (int i = 0; i < TETROMINO_BLOCK_NUM; i++) {
        int16_t x_offset = tetromino_shape[i][0] * TETROMINO_CELL_SIZE;
        int16_t y_offset = tetromino_shape[i][1] * TETROMINO_CELL_SIZE;

        Shape* rect = tetromino->shape->shapes[i];
        rect->pixel.first = tetromino->x + x_offset;
        rect->pixel.second = tetromino->y + y_offset;
    }
}

bool is_colision(Int16Pair* coords, bool game_board[][GAMEBOARD_COLS]) {
    for (int i = 0; i < TETROMINO_BLOCK_NUM; i++) {
        int16_t x = coords[i].first;
        int16_t y = coords[i].second;
        if (x >= GAMEBOARD_COLS || x < 0 ||
            y >= GAMEBOARD_ROWS || y < 0 ||
            game_board[y][x]) {
            return true;
        }
    }
    return false;
}
