#include "label.h"

Label* init_label(uint16_t x, uint16_t y, char text[], uint16_t size, uint16_t color) {
    Label* label = (Label*)malloc(sizeof(Label));
    label->base.shape_type = LABEL;
    label->base.x = x;
    label->base.y = y;
    label->text = text;
    label->size = size;
    label->base.color = color;
}
