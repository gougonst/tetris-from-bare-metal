#include "rect.h"

Rect* rect_init(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
    Rect* rect = (Rect*)malloc(sizeof(Rect));
    rect->base.x = x;
    rect->base.y = y;
    rect->w = w;
    rect->h = h;
    rect->base.color = color;
    rect->base.draw = draw_rect;
    return rect;
}

void draw_rect(Shape* shape, Graphics* graphics) {
    Rect* rect = (Rect*)shape;
    graphics->draw_rect(
        rect->base.x,
        rect->base.y,
        rect->w,
        rect->h,
        rect->base.color
    );
}
