#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"
#include "graphic_lib/shapes.h"

int main(void)
{
    graphic_init();
    create_window(1280, 720, "Awaléga");

    Image Menu;

    Menu.background=NULL;
    Menu.background=loadImage("images/fondecran.bmp");

    Rect menu_rect;
    menu_rect.topleft.x=0; menu_rect.topleft.y=0; menu_rect.w=1280; menu_rect.h=720;
    present_image(Menu.background,menu_rect);

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

    SDL_DestroyTexture(Menu.background);
    destroy_window();

    return 0;
}