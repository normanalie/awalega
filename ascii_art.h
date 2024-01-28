#ifndef ASCII_ART_H
#define ASCII_ART_H


#include <string.h>
#include "awale_game_macros_structs.h"
#include "score_handler.h"

void showMenu(void);
void showGameTable(PlayerInfo P1, PlayerInfo P2, int totalMoves, int moveCountdown);
void showScore(void);
void showScoreSectionMenuSelection(int * isGameJustEnded, int * selectedMenu);   // Donner la bonne sélection de choix possible lorsquon est sur l'écran des scores ( (Rejouer OU Menu) OU Menu)
void showAboutGame(void);
void showByeBye(void);


#endif /* ASCII_ART_H */