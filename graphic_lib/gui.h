#ifndef GUIH
#define GUIH

#include <stdio.h>
#include <stdlib.h>
#include "graphic_lib.h"
#include "../awale_game_macros_structs.h"
#include "../score_handler.h"
void initGui(Images *pImages, Containers *pRectangles);
void showMenu(Images Images, Containers Rectangles);
void showAwale(Images Images, Containers Rectangles, PlayerInfo P1, PlayerInfo P2);
void showLeaderboard(Images Images, Containers Rectangles, GameStatusVar GameStatus);
void destroyGui(Images *pImages);

#endif