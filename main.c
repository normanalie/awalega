#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "awale_game_macros_structs.h"
#include "awale_game.h"
#include "score_handler.h"
#include "utilities.h"
#include "graphic_lib/gui.h"

void initGameStatus(GameStatusVar *pGameStatus)
{
    pGameStatus->isGameJustEnded = 0;
    pGameStatus->moveCountdown = 20;
    pGameStatus->playerTurn = randInt(1, 2);
    pGameStatus->endgameType = NO_ENDGAME;          // Voir Macros "Endgame Types"
    pGameStatus->totalMoves = 0;                    // Nombre de coups totaux
    pGameStatus->moveCountdown = MOVES_BEFORE_STOP; // Décompte le nombre de coup avant l'arrêt du jeu
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {
        pGameStatus->validHoles[i] = 1;
    }
}

int main(void)
{

    srand(time(NULL));

    GameStatusVar GameStatus;
    initGameStatus(&GameStatus);
    GameStatus.selectedMenu = SECTION_HOME;

    PlayerInfo P1;
    PlayerInfo P2;
    initPlayers(&P1, &P2, GameStatus);

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
            break;
        case SECTION_NEW_GAME:
            initGameStatus(&GameStatus);
            initPlayers(&P1, &P2, GameStatus);
            GameStatus.gameMode = 2; // gameModeSelector();
            GameStatus.selectedMenu = SECTION_GAME;
            break;

        case SECTION_GAME:
            showAwale(images, imgsContainers, P1, P2, GameStatus);

            if (GameStatus.endgameType != NO_ENDGAME) // Fin de partie
            {
                // Afficher le tablier et les infos du jeu une dernière fois avant de quitter afin que les joueurs puisse voir ce qu'il s'est passé
                showAwale(images, imgsContainers, P1, P2, GameStatus);
                sleep(3);

                // Gestionnaire de fin de jeu + Afficher message correspondant
                GameStatus.isGameJustEnded = 1;
                endgameManager(&GameStatus);
                whoWon(&P1, &P2, &GameStatus);

                // Ecriture des scores
                if (GameStatus.selectedMenu == SECTION_SCORE)
                {
                    saveScores(P1, P2);
                }
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

        event = graphic_get_event();

        switch (event.type)
        {
        case SDL_QUIT:
            GameStatus.selectedMenu = SECTION_EXIT;
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
        default:
            graphic_update();
            break;
        }

    } while (GameStatus.selectedMenu != SECTION_EXIT);

    return 0;
}
