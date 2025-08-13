#include "label.h"

Label* init_label(UInt16Pair pixel, char text[], uint16_t size, uint16_t color) {
    Label* label = (Label*)malloc(sizeof(Label));
    label->base.shape_type = LABEL;
    label->base.pixel = pixel;
    label->text = text;
    label->size = size;
    label->base.color = color;
}
