#include "shapes.h"

Rect rect_by_center(Point center, int w, int h, Color color)
{
    Rect r;
    r.topleft.x = center.x - (w / 2);
    r.topleft.y = center.y - (h / 2);
    r.w = w;
    r.h = h;
    r.fill = color;
    return r;
}

Point center_of_rect(Rect rectangle)
{
    Point p;
    p.x = rectangle.topleft.x + (rectangle.w / 2);
    p.y = rectangle.topleft.y + (rectangle.h / 2);
    return p;
}