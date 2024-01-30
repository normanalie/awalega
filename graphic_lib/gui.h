#ifndef GUIH
#define GUIH

#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "graphic_lib.h"
#include "../awale_game_macros_structs.h"
#include "../score_handler.h"

void showMenu(Image Images, Rectangle Rectangles);
void showAwale(Image Images, Rectangle Rectangles, PlayerInfo P1, PlayerInfo P2, GameStatusVar GameStatus);
void showLeaderboard(Image Images, Rectangle Rectangles, GameStatusVar GameStatus);
void showAbout(Image Images, Rectangle Rectangles, int currentPage);
void showGameModeSelection(Image Images, Rectangle Rectangles);

#endif