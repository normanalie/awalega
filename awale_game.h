#ifndef AWALE_GAME
#define AWALE_GAME


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "awale_game_macros_structs.h"
#include "utilities.h"

// Menu
int menuSelector(void);    // Choix de la section lorsq'on est dans le manu principal 

//  Game Init
int gameModeSelector (void);         // Sélection du mode de jeu (Solo OU PvP) & Enregistrement des paramètres
void initPlayers (PlayerInfo * P1, PlayerInfo * P2, int gameMode);    // Initialisation de joueurs (Nom, Scores, etc.)

// Game
void switchPlayer(int * playerTurn);                      // Changer de joueur pour le tour
void waitBeforeBotPlay(PlayerInfo P2, int playerTurn);    // Attendre quelques instants avant que le bot ne joue pour que le joueur vois le résultat de ses actions 
int holeSelector (PlayerInfo P1, PlayerInfo P2, int playerTurn);   // Sélection du trou à jouer
int isActionValid(PlayerInfo Player, int selectedHole);            // Vérifie si le numéro de case choisi par le joueur est possible ou non
void sowAndHarvestSeeds(PlayerInfo * P1, PlayerInfo * P2, int playerTurn, int originalHole);         // Semer et récolter les graines après sélection de la case
int hasNumberHarvestedSeedsChanged(PlayerInfo P1, PlayerInfo P2, int oldP1Seeds, int oldP2Seeds);    // Vérifie si le nombre de graine a changé. Permet de réinit. le nombre de coup totaux
int areEveryHolesEmpty(PlayerInfo Player);                                          // Vérifie si tous les trous sont vides pour un joueur
int canPlayerFillEmptyHoles(PlayerInfo Player, int playerTurn, int validHoles[]);   // Vérifie si un joueur peur remplir au moins l'un des trou du joueur adverse et renvoie les cases permettant cela
void forcePlayerToPlay(PlayerInfo Player, int validHoles[], int * holeToUse);       // Force un joueur à jouer lorsque les trous du joueur adverse sont vides
int isForcedActionValid(PlayerInfo Player, int selectedHole, int validHoles[]);     // Fonctionne comme "isActionValid()" mais vérifie avec un tableau si le trou choisi permet de remplir au moins un trou du joueur adverse 
void endgameManager(int endgameType, PlayerInfo endingPlayer, int* selectedMenu);   // Vérifie pour quelle raison la partie s'est finie et fait une action en fonction


#endif /* AWALE_GAME */