#include "label.h"

Label* init_label(Int16Pair pixel, char text[], int16_t size, int16_t color) {
    Label* label = (Label*)malloc(sizeof(Label));
    label->base.shape_type = LABEL;
    label->base.pixel = pixel;
    label->text = text;
    label->size = size;
    label->base.color = color;
}
