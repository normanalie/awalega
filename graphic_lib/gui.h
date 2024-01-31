#ifndef GUIH
#define GUIH

#include <stdio.h>
#include <stdlib.h>
#include "graphic_lib.h"
#include "../awale_game_macros_structs.h"
#include "../score_handler.h"
#include "../awale_game.h"
#include "../audio_lib/audio_lib.h"

void initGui(Images *pImages, Containers *pRectangles);
void showMenu(Images Images, Containers Rectangles, GameStatusVar GameStatus);
void showAwale(Images Images, Containers Rectangles, PlayerInfo P1, PlayerInfo P2, GameStatusVar GameStatus);
void showLeaderboard(Images Images, Containers Rectangles, GameStatusVar GameStatus);
void showAbout(Images Images, Containers Rectangles, GameStatusVar GameStatus, int currentPage);
void showGameModeSelection(Images Images, Containers Rectangles, GameStatusVar GameStatus);
void showInitPlayer(Images Images, Containers Rectangles, GameStatusVar GameStatus, int currentPlayer);

void showMenuButton(Images Images, Containers Rectangles);
void showVolumeButton(Images Images, Containers Rectangles, GameStatusVar GameStatus);
void showReplayButton(Images Images, Containers Rectangles);

void volumeButtonClickHandler(Containers Rectangles, Point cursor, GameStatusVar *pGameStatus);
void homeClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu);

void leaderboardClickHandler(Containers Rectangles, Point cursor, GameStatusVar *pGameStatus);
void newGameClickHandler(Containers Rectangles, Point cursor, GameStatusVar *pGameStatus, PlayerInfo *P2);
void nameFormClickHandler(Containers Rectangles, Point cursor, GameStatusVar *pGameStatus);
void addLetterToPseudo(PlayerInfo *Player, const char *letter);
void inGameClickHandler(Containers Rectangles, Point cursor, PlayerInfo *pP1, PlayerInfo *pP2, GameStatusVar *pGameStatus);
void aboutClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu, int *pCurrentPage);
void menuClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu);
void guiClickHandler(Containers Rectangles, Point cursor, GameStatusVar *pGameStatus);

void destroyGui(Images *pImages);

#endif