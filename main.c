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

    PlayerInfo P1;
    PlayerInfo P2;

    for(int i=0; i<HOLES_PER_PLAYER; i++){
        P1.seeds[i]=SEEDS_PER_HOLE;
        P2.seeds[i]=SEEDS_PER_HOLE;
    }
    
    showMenu(Images, Rectangles);
    showAwale(Images, Rectangles, P1, P2);
    
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