#ifndef AWALE_GAME
#define AWALE_GAME

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "awale_game_macros_structs.h"
#include "utilities.h"


//  Game Init
int gameModeSelector(void);                                                 // Sélection du mode de jeu (Solo OU PvP) & Enregistrement des paramètres
void initPlayers(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar GameStatus); // Initialisation de joueurs (Nom, Scores, etc.)

// Game
void switchPlayer(GameStatusVar *GameStatus);                                                     // Changer de joueur pour le tour
void waitBeforeBotPlay(PlayerInfo P2, GameStatusVar GameStatus);                                  // Attendre quelques instants avant que le bot ne joue pour que le joueur vois le résultat de ses actions
int isActionValid(PlayerInfo Player, GameStatusVar GameStatus);                                   // Vérifie si le numéro de case choisi par le joueur est possible ou non
void sowAndHarvestSeeds(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar GameStatus);                // Semer et récolter les graines après sélection de la case
int hasNumberHarvestedSeedsChanged(PlayerInfo P1, PlayerInfo P2, int oldP1Seeds, int oldP2Seeds); // Vérifie si le nombre de graine a changé. Permet de réinit. le nombre de coup totaux
int areEveryHolesEmpty(PlayerInfo Player);                                                        // Vérifie si tous les trous sont vides pour un joueur
int canPlayerFillEmptyHoles(PlayerInfo Player, int playerTurn, int validHoles[]);                 // Vérifie si un joueur peur remplir au moins l'un des trou du joueur adverse et renvoie les cases permettant cela
void whoWon(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar *GameStatus);                           // Vérifie qui a gangé
void endgameManager(GameStatusVar *GameStatus);                          // Vérifie pour quelle raison la partie s'est finie et fait une action en fonction
void playMove(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar *GameStatus);

#endif /* AWALE_GAME */