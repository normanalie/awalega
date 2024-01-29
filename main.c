#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"

int main(void)
{
    graphic_init();
    create_window(480, 600, "Awaléga");
    Point center = {100, 100};
    Rect r = rect_by_center(center, 100, 200, Lavender);

    draw_rect(r);

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