#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"

int main(void)
{
    graphic_init();
    create_window(480, 600, "Awaléga");

    Point tl;
    tl.x = 100;
    tl.y = 100;
    Rect rectangle;
    rectangle.topleft = tl;
    rectangle.w = 100;
    rectangle.h = 100;
    rectangle.outline = Lavender;
    rectangle.fill = Lavender;

    Point b;
    b.x = 200;
    b.y = 200;
    Rect sqr;
    sqr.topleft = b;
    sqr.w = 60;
    sqr.h = 60;
    sqr.fill = Magenta;
    sqr.outline = Magenta;

    draw_rect(rectangle);
    draw_rect(sqr);

    char quit = 0;
    SDL_Event event;
    while (!quit)
    {
        graphic_update();
        event = graphic_get_event();

        switch (event.type)
        {
        case SDL_QUIT:
            quit = 1;
            break;
        }
    }

    destroy_window();

    return 0;
}