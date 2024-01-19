#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"

int main(void)
{

    Point center;
    center.x = 100;
    center.y = 100;
    Rect r = rect_by_center(center, 50, 50);
    Point calculatedCenter = center_of_rect(r);
    printf("<Rectangle: x=%d, y=%d, w=%d, h=%d>\n", r.topleft.x, r.topleft.y, r.w, r.h);
    printf("<Point: x=%d, y=%d>\n", calculatedCenter.x, calculatedCenter.y);

    return 0;
}