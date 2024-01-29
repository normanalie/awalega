#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"
#include "graphic_lib/shapes.h"
#include "graphic_lib/images_struct.h"

int main(void)
{
    graphic_init();
    create_window(1280, 720, "Awaléga");

    Image Images;

    Images.background.menu=NULL;
    Images.background.menu=loadImage("images/fondecran.bmp");
    Images.button.play=loadImage("images/play.bmp");

    Rect menu_rect; Rect play_rect;
    menu_rect.topleft.x=0; menu_rect.topleft.y=0; menu_rect.w=1280; menu_rect.h=720;
    play_rect.topleft.x=400; play_rect.topleft.y=300; play_rect.w=500; play_rect.h=200;
    present_image(Images.background.menu,menu_rect);
    present_image(Images.button.play,play_rect);

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

    SDL_DestroyTexture(Images.background.menu);
    SDL_DestroyTexture(Images.button.play);
    destroy_window();

    return 0;
}