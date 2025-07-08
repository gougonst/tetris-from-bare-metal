#include "label.h"

Label* label_init(uint16_t x, uint16_t y, char text[], uint16_t size, uint16_t color) {
    Label* label = (Label*)malloc(sizeof(Label));
    label->base.x = x;
    label->base.y = y;
    label->text = text;
    label->size = size;
    label->base.color = color;
    label->base.draw = draw_label;
}

void draw_label(Shape* shape, Graphics* graphics) {
    // Currently, not support the textsize yet.
    Label* label = (Label*)shape;

    graphics->draw_label(
        label->base.x,
        label->base.y,
        label->text
    );
}
