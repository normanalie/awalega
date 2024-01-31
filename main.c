#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "awale_game_macros_structs.h"
#include "awale_game.h"
#include "score_handler.h"
#include "utilities.h"
#include "graphic_lib/gui.h"

int main(void)
{

    srand(time(NULL));

    GameStatusVar GameStatus;
    PlayerInfo P1;
    PlayerInfo P2;

    GameStatus.selectedMenu = SECTION_HOME;
    GameStatus.isGameJustEnded = 0;
    
    for (int i=0; i<HOLES_PER_PLAYER; i++) {
        GameStatus.validHoles[i] = 0;
    }


    refreshTerminal(); // Init GUI (SDL)
    Images images;
    Containers imgsContainers;
    initGui(&images, &imgsContainers);

    SDL_Event event;
    do
    {

        switch (GameStatus.selectedMenu)
        {

        case SECTION_HOME:
            showMenu(images, imgsContainers);
            GameStatus.isGameJustEnded = 0;
            GameStatus.selectedMenu = menuSelector();
            break;

        case SECTION_GAME: // Lancement d'une partie
            GameStatus.totalMoves = 0;
            GameStatus.moveCountdown = 20;

            // Selection du mode de jeu (Solo ou PvP) & Enregistrement des noms (+ selection difficulté Bot)
            GameStatus.gameMode = 2; // gameModeSelector();

            // Initialisation de joueurs (Nom, Scores, etc.)
            initPlayers(&P1, &P2, GameStatus);

            // Initialisation du jeu & Init du jeu sur CLI (ou GUI) (plateau, jetons, score, etc...)
            GameStatus.playerTurn = randInt(1, 2);
            GameStatus.endgameType = NO_ENDGAME;          // Voir Macros "Endgame Types"
            GameStatus.totalMoves = 0;                    // Nombre de coups totaux
            GameStatus.moveCountdown = MOVES_BEFORE_STOP; // Décompte le nombre de coup avant l'arrêt du jeu
            PlayerInfo *endingPlayer = NULL;              // Joueur qui cause la fin du jeu

            showAwale(images, imgsContainers, P1, P2, GameStatus);

            do
            { // Boucle de jeu

                // Afficher le jeu

                // Changer de joueur  (Mis au début exprès pour réutiliser la var "playerTurn" tel quel pour les autres fonction)
                switchPlayer(&GameStatus);

                /*
                // Attendre quelques instants pour donner le temps à J1 de voir le résultat lorsqu'il joue contre le bot
                waitBeforeBotPlay(P2, GameStatus);

                // Sélection du trou à jouer & Vérification de la légalité
                // holeSelector(P1, P2, &GameStatus);
                GameStatus.totalMoves++;
                GameStatus.moveCountdown--;

                // Sauvegardes de l'ancien nombre de graine pour voir s'il faut réinit "TotalMoves"
                int oldP1Seeds = P1.harvestedSeeds;
                int oldP2Seeds = P2.harvestedSeeds;

                // Déplacement des graines dans le bon sens
                sowAndHarvestSeeds(&P1, &P2, GameStatus);

                // Vérifier si les scores ont changés pour réinitialiser le compteur
                if (hasNumberHarvestedSeedsChanged(P1, P2, oldP1Seeds, oldP2Seeds))
                {
                    GameStatus.moveCountdown = MOVES_BEFORE_STOP;
                }
                */
                // Changer la valuer de "endgameType" permettant de sortir de la boucle si le joueur perd OU veut quitter en pleine partie
                if (P1.harvestedSeeds >= SEEDS_TO_WIN || P2.harvestedSeeds >= SEEDS_TO_WIN)
                { // 1 : Si l'un des joueur a plus de la moitié des graines
                    GameStatus.endgameType = ENDGAME_SEED_COUNT;

                    if (P1.harvestedSeeds >= SEEDS_TO_WIN)
                    {
                        endingPlayer = &P1;
                    }
                    else
                    {
                        endingPlayer = &P2;
                    }
                }
                else if (GameStatus.moveCountdown == 0)
                { // 2 : Pas de récolte sur les 20 derniers coups
                    GameStatus.endgameType = ENDGAME_MOVE_LIMIT;
                    endingPlayer = &P1; // Pour éviter de renvoyer un pointeur "NULL" à la fonction "endgameManager()" un peu plus bas
                }
                else
                { // 3 : Un joueur peut (ou peut pas) remplir les cases vides d'un joueur adverse

                    int validHoles[HOLES_PER_PLAYER] = {0}; // Au cas où on veut forcer un joueur à jouer sur des cases spécifiques pour remplir les trous de l'adversaire
                    PlayerInfo *selectedUser = NULL;

                    if (areEveryHolesEmpty(P1))
                    {
                        if (canPlayerFillEmptyHoles(P2, 2, validHoles))
                        {
                            selectedUser = &P2;
                            GameStatus.playerTurn = 2;
                        }
                        else
                        {
                            GameStatus.endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                            endingPlayer = &P2;
                        }
                    }
                    else if (areEveryHolesEmpty(P2))
                    {
                        if (canPlayerFillEmptyHoles(P1, 1, validHoles))
                        {
                            selectedUser = &P1;
                            GameStatus.playerTurn = 1;
                        }
                        else
                        {
                            GameStatus.endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                            endingPlayer = &P1;
                        }
                    }

                    if (selectedUser != NULL)
                    {
                        // Attendre quelques instants pour donner le temps à J1 de voir le résultat lorsqu'il joue contre le bot
                        waitBeforeBotPlay(P2, GameStatus);

                        forcePlayerToPlay(*selectedUser, validHoles, &GameStatus);
                        sowAndHarvestSeeds(&P1, &P2, GameStatus);
                    }
                }

            } while (GameStatus.endgameType == NO_ENDGAME);

            // Afficher le tablier et les infos du jeu une dernière fois avant de quitter afin que les joueurs puisse voir ce qu'il s'est passé
            showAwale(images, imgsContainers, P1, P2, GameStatus);
            sleep(3);

            // Gestionnaire de fin de jeu + Afficher message correspondant
            GameStatus.isGameJustEnded = 1;
            endgameManager(&GameStatus, *endingPlayer);
            whoWon(&P1, &P2, &GameStatus);

            // Ecriture des scores
            if (GameStatus.selectedMenu == SECTION_SCORE)
            {
                saveScores(P1, P2);
            }

            break;

        case SECTION_SCORE: // Affichage Score
            showLeaderboard(images, imgsContainers, GameStatus);
            // showScoreSectionMenuSelection(&GameStatus);
            break;

        case SECTION_ABOUT: // Affichage "A propos du jeu"
            showAbout(images, imgsContainers, GameStatus.playerTurn);
            break;

        case SECTION_EXIT_SCREEN: // Quitter le jeu
            GameStatus.selectedMenu = SECTION_EXIT;
            break;
        }

        graphic_update();
        event = graphic_get_event();

        switch (event.type)
        {
        case SDL_QUIT:
            GameStatus.selectedMenu = SECTION_EXIT;
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                Point cursor = {event.button.x, event.button.y};
                if (GameStatus.selectedMenu == SECTION_GAME)
                {
                    inGameClickHandler(imgsContainers, cursor, &P1, &P2, &GameStatus);
                }
                else
                {

                    guiClickHandler(imgsContainers, cursor, &GameStatus.selectedMenu);
                }
            }
        }

    } while (GameStatus.selectedMenu != SECTION_EXIT);

    return 0;
}


/*
PROTO: playMove(Player1, Player2, trouID, GameStatus) -> nextPlayer{
    Si illegal{
        retourne GamesStatus.currentPlayer -> besoin de rejouer
    } [OK]
    Modifier GameStatus [OK]
    Modifie le plateau  [OK]
    Si p2 est bot{
        attend
        fais jouer p2
    }
    Verifie le plateau
    Calcule nextplayer
    retourne nextplayer
}
*/

void playMove(PlayerInfo * P1, PlayerInfo * P2, GameStatusVar * GameStatus, int playableHoles[]) {

    PlayerInfo * pCurrentPlayer;

    if (GameStatus->playerTurn == 1) {
        pCurrentPlayer = P1;
    } else {
        pCurrentPlayer = P2;
    }

    if (!isActionValid(*pCurrentPlayer, *GameStatus)) {
        return; // GameStatus->playerTurn;
    }

    // Attendre quelques instants pour donner le temps à J1 de voir le résultat lorsqu'il joue contre le bot
    waitBeforeBotPlay(*P2, *GameStatus);


    // Sélection du trou à jouer & Vérification de la légalité
    // holeSelector(P1, P2, &GameStatus);
    GameStatus->totalMoves++;
    GameStatus->moveCountdown--;


    // Sauvegardes de l'ancien nombre de graine pour voir s'il faut réinit "TotalMoves"
    int oldP1Seeds = P1->harvestedSeeds;
    int oldP2Seeds = P2->harvestedSeeds;

    // Déplacement des graines dans le bon sens
    sowAndHarvestSeeds(P1, P2, *GameStatus);

    // Vérifier si les scores ont changés pour réinitialiser le compteur
    if (hasNumberHarvestedSeedsChanged(*P1, *P2, oldP1Seeds, oldP2Seeds))
    {
        GameStatus->moveCountdown = MOVES_BEFORE_STOP;
    }


    // Vérification condition de fin du jeu
    if (P1->harvestedSeeds >= SEEDS_TO_WIN || P2->harvestedSeeds >= SEEDS_TO_WIN)
    { // 1 : Si l'un des joueur a plus de la moitié des graines
        GameStatus->endgameType = ENDGAME_SEED_COUNT;

        if (P1->harvestedSeeds >= SEEDS_TO_WIN)
        {
            GameStatus->endingPlayer = P1;
        }
        else
        {
            GameStatus->endingPlayer = P2;
        }
    }
    else if (GameStatus->moveCountdown == 0)
    { // 2 : Pas de récolte sur les 20 derniers coups
        GameStatus->endgameType = ENDGAME_MOVE_LIMIT;
        GameStatus->endingPlayer = P1; // Pour éviter de renvoyer un pointeur "NULL" à la fonction "endgameManager()" un peu plus bas
    }
    else
    { // 3 : Un joueur peut (ou peut pas) remplir les cases vides d'un joueur adverse

        //int validHoles[HOLES_PER_PLAYER] = {0}; // Au cas où on veut forcer un joueur à jouer sur des cases spécifiques pour remplir les trous de l'adversaire
        PlayerInfo *selectedUser = NULL;

        if (areEveryHolesEmpty(*P1))
        {
            if (canPlayerFillEmptyHoles(*P2, 2, GameStatus->validHoles))
            {
                selectedUser = &P2;
                GameStatus->playerTurn = 2;
            }
            else
            {
                GameStatus->endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                GameStatus->endingPlayer = P2;
            }
        }
        else if (areEveryHolesEmpty(*P2))
        {
            if (canPlayerFillEmptyHoles(*P1, 1, GameStatus->validHoles))
            {
                selectedUser = &P1;
                GameStatus->playerTurn = 1;
            }
            else
            {
                GameStatus->endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                GameStatus->endingPlayer = P1;
            }
        }


        if (selectedUser == NULL)
        {
            switchPlayer(GameStatus);

            for (int i=0; i<HOLES_PER_PLAYER; i++) {
                GameStatus->validHoles[i] = 1;
            }
        }
    }

    return;
}