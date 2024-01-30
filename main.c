#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"
#include "graphic_lib/shapes.h"
#include "graphic_lib/gui.h"
#include "score_handler.h"

int main(void)
{
    Images images;
    Containers imgsContainers;
    initGui(&images, &imgsContainers);

    PlayerInfo P1;
    PlayerInfo P2;
    P1.harvestedSeeds = 0;
    P2.harvestedSeeds = 0;

    GameStatusVar GameStatus;
    GameStatus.isGameJustEnded = 0;
    GameStatus.totalMoves = 0;
    GameStatus.moveCountdown = 20;

    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {
        P1.seeds[i] = SEEDS_PER_HOLE;
        P2.seeds[i] = SEEDS_PER_HOLE;
    }

    showMenu(images, imgsContainers);
    // showAwale(images, imgsContainers, P1, P2, GameStatus);
    // showLeaderboard(images, imgsContainers, GameStatus);

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
    destroyGui(&images);
    return 0;
}