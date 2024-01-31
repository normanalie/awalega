#ifndef GUIH
#define GUIH

#include <stdio.h>
#include <stdlib.h>
#include "graphic_lib.h"
#include "../awale_game_macros_structs.h"
#include "../score_handler.h"

void initGui(Images *pImages, Containers *pRectangles);
void showMenu(Images Images, Containers Rectangles);
void menuClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu);
void awaleClickHandler(Containers Rectangles, Point cursor, int *pSelectedHander);
void leaderboardClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu);
void aboutClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu);
void guiClickHandler(Containers Rectangles, Point cursor, int *selectedMenu);
void showAwale(Images Images, Containers Rectangles, PlayerInfo P1, PlayerInfo P2, GameStatusVar GameStatus);
void showLeaderboard(Images Images, Containers Rectangles, GameStatusVar GameStatus);
void showAbout(Images Images, Containers Rectangles, int currentPage);
void showGameModeSelection(Images Images, Containers Rectangles);
void destroyGui(Images *pImages);

#endif