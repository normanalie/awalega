#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"
#include "graphic_lib/shapes.h"
#include "graphic_lib/gui.h"

int main(void)
{
    graphic_init();
    create_window(1280, 720, "Awaléga");

    Image Images;
    init_Images(&Images);

    Rectangle Rectangles;
    init_Rectangle(&Rectangles);
    
    showMenu(Images, Rectangles);

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

    destroy_Images(&Images);
    destroy_window();

    return 0;
}