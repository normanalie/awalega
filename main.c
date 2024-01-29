#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "awale_game_macros_structs.h"
#include "awale_game.h"
#include "score_handler.h"
#include "utilities.h"
#include "ascii_art.h"



int main (void) {

    srand(time(NULL));

    int selectedMenu = SECTION_HOME;
    int isGameJustEnded = 0;  // Utile quand on a besoin de savoir si dans le menu des scores, on vient de sortir d'une partie ou non pour avoir la possibilité d'en relancer une 
    
    PlayerInfo P1;
    PlayerInfo P2;

    refreshTerminal();    // Init GUI (SDL)

    do {
        
        switch (selectedMenu) {

        case SECTION_HOME:
            refreshTerminal();
            isGameJustEnded = 0;
            showMenu();
            selectedMenu = menuSelector();
        break;

        case SECTION_GAME:    // Lancement d'une partie

            refreshTerminal();

            // Selection du mode de jeu (Solo ou PvP) & Enregistrement des noms (+ selection difficulté Bot)
            int gameMode = gameModeSelector();
            refreshTerminal();

            // Initialisation de joueurs (Nom, Scores, etc.) 
            initPlayers(&P1, &P2, gameMode);
            refreshTerminal();

            // Initialisation du jeu & Init du jeu sur CLI (ou GUI) (plateau, jetons, score, etc...)
            int playerTurn = randInt(1, 2);           // Choix du 1er joueur à jouer
            int selectedHole;                         // Trou sélectionné à jouer
            int endgameType = NO_ENDGAME;             // Voir Macros "Endgame Types"
            int totalMoves = 0;                       // Nombre de coups totaux
            int moveCountdown = MOVES_BEFORE_STOP;    // Décompte le nombre de coup avant l'arrêt du jeu
            PlayerInfo * endingPlayer = NULL;         // Joueur qui cause la fin du jeu

            refreshTerminal();

            do {   // Boucle de jeu

                // Afficher le jeu
                showGameTable(P1, P2, totalMoves, moveCountdown);

                // Changer de joueur  (Mis au début exprès pour réutiliser la var "playerTurn" tel quel pour les autres fonction)
                switchPlayer(&playerTurn);

                // Attendre quelques instants pour donner le temps à J1 de voir le résultat lorsqu'il joue contre le bot
                waitBeforeBotPlay(P2, playerTurn);

                // Sélection du trou à jouer & Vérification de la légalité
                selectedHole = holeSelector(P1, P2, playerTurn);

                totalMoves++;
                moveCountdown--;

                // Sauvegardes de l'ancien nombre de graine pour voir s'il faut réinit "TotalMoves"
                int oldP1Seeds = P1.harvestedSeeds;
                int oldP2Seeds = P2.harvestedSeeds;
            
                // Déplacement des graines dans le bon sens
                sowAndHarvestSeeds(&P1, &P2, playerTurn, selectedHole-1);

                // Vérifier si les scores ont changés pour réinitialiser le compteur
                if  (hasNumberHarvestedSeedsChanged(P1, P2, oldP1Seeds, oldP2Seeds)) {
                    moveCountdown = MOVES_BEFORE_STOP;
                }

            
                // Changer la valuer de "endgameType" permettant de sortir de la boucle si le joueur perd OU veut quitter en pleine partie
                if (P1.harvestedSeeds >= SEEDS_TO_WIN || P2.harvestedSeeds >= SEEDS_TO_WIN) {   // 1 : Si l'un des joueur a plus de la moitié des graines 
                    endgameType = ENDGAME_SEED_COUNT;

                    if (P1.harvestedSeeds >= SEEDS_TO_WIN) {
                        endingPlayer = &P1;
                    } else {
                        endingPlayer = &P2;
                    }

                } else if (moveCountdown == 0) {              // 2 : Pas de récolte sur les 20 derniers coups 
                    endgameType = ENDGAME_MOVE_LIMIT;
                    endingPlayer = &P1; // Pour éviter de renvoyer un pointeur "NULL" à la fonction "endgameManager()" un peu plus bas
                } else {                                      // 3 : Un joueur peut (ou peut pas) remplir les cases vides d'un joueur adverse

                    int validHoles[HOLES_PER_PLAYER] = {0};   // Au cas où on veut forcer un joueur à jouer sur des cases spécifiques pour remplir les trous de l'adversaire
                    PlayerInfo * selectedUser = NULL;

                    if (areEveryHolesEmpty(P1)) {
                        if (canPlayerFillEmptyHoles(P2, 2, validHoles)) {
                            selectedUser = &P2;
                            playerTurn = 2;
                        } else {
                            endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                            endingPlayer = &P2;
                        }
                    } else if (areEveryHolesEmpty(P2)) {
                        if (canPlayerFillEmptyHoles(P1, 1, validHoles)) {
                            selectedUser = &P1;
                            playerTurn = 1;
                        } else {
                            endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                            endingPlayer = &P1;
                        }
                    }

                    if (selectedUser != NULL) {
                        refreshTerminal();
                        showGameTable(P1, P2, totalMoves, moveCountdown);

                        // Attendre quelques instants pour donner le temps à J1 de voir le résultat lorsqu'il joue contre le bot
                        waitBeforeBotPlay(P2, playerTurn);
                        
                        forcePlayerToPlay(*selectedUser, validHoles, &selectedHole);
                        sowAndHarvestSeeds(&P1, &P2, playerTurn, selectedHole-1);
                    }
                }
                

                // Mise à jour des élément sur le CLI (dans le GUI pour le projet final)
                refreshTerminal();

            } while (endgameType == NO_ENDGAME);


            // Afficher le tablier et les infos du jeu une dernière fois avant de quitter afin que les joueurs puisse voir ce qu'il s'est passé
            showGameTable(P1, P2, totalMoves, moveCountdown);
            sleep(3);
            refreshTerminal();

            // Gestionnaire de fin de jeu + Afficher message correspondant
            isGameJustEnded = 1;
            endgameManager(endgameType, *endingPlayer, &selectedMenu);

            // Ecriture des scores
            if (selectedMenu == SECTION_SCORE) {
                saveScores(P1, P2);
            }

        break;

        case SECTION_SCORE:    // Affichage Score
            refreshTerminal();
            showScore();
            showScoreSectionMenuSelection(&isGameJustEnded, &selectedMenu);
        break;

        case SECTION_ABOUT:    // Affichage "A propos du jeu"
            refreshTerminal();
            showAboutGame();
            selectedMenu = SECTION_HOME;
        break;

        case SECTION_EXIT_SCREEN:    // Quitter le jeu
            refreshTerminal();
            showByeBye();
            selectedMenu = SECTION_EXIT;
        break;

        }

    } while (selectedMenu != SECTION_EXIT);

    return 0;
}
