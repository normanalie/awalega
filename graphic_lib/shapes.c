#include "shapes.h"

Rect rect_by_center(Point center, int w, int h, Color color)
{
    Rect r;
    r.topleft.x = center.x - (w / 2);
    r.topleft.y = center.y - (h / 2);
    r.w = w;
    r.h = h;
    r.fill = color;
    r.outline = 0;
    r.pImage = NULL;
    return r;
}

Point center_of_rect(Rect rectangle)
{
    Point p;
    p.x = rectangle.topleft.x + (rectangle.w / 2);
    p.y = rectangle.topleft.y + (rectangle.h / 2);
    return p;
}

void rect_destroy(Rect r)
{
    free(r.pImage);
    return;
}

/*float distance(Point a, Point b)
{
    return sqrt((abs(b.x - a.x) * abs(b.x - a.x) + abs(b.y - a.y) * abs(b.y - a.y)));
}*/

/*Bool is_in(Point point, Rect rectangle)
{
    Point topleft = rectangle.topleft;
    Point bottomright = {rectangle.topleft.x + rectangle.w, rectangle.topleft.y + rectangle.h};
    if (point.x >= topleft.x && point.x <= bottomright.x && point.y >= topleft.y && point.y <= bottomright.y)
    {
        return true;
    }
    return false;
}*/