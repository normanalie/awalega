#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"
#include "graphic_lib/shapes.h"

int main(void)
{
    graphic_init();
    create_window(1280, 720, "Awaléga");

    Background background;

    background.menu_background=NULL;
    background.menu_background=loadImage("images/fondecran.bmp");
    Rect menu_back;
    menu_back.topleft.x=0; menu_back.topleft.y=0; menu_back.w=1280; menu_back.h=720;
    present_image(background.menu_background,menu_back);

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

    SDL_DestroyTexture(background.menu_background);
    destroy_window();

    return 0;
}