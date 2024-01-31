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

    bool redraw = true;
    int aboutCurrentPage = 0;
    SDL_Event event;
    do
    {
        switch (GameStatus.selectedMenu)
        {
        case SECTION_HOME:
            if (redraw)
            {
                redraw = false;
                showMenu(images, imgsContainers);
            }
            GameStatus.isGameJustEnded = 0;
            break;

        case SECTION_NEW_GAME:
            initGameStatus(&GameStatus);
            initPlayers(&P1, &P2, GameStatus);
            GameStatus.gameMode = 2; // gameModeSelector();
            GameStatus.selectedMenu = SECTION_GAME;
            break;

        case SECTION_GAME:
            if (redraw)
            {
                redraw = false;
                showAwale(images, imgsContainers, P1, P2, GameStatus);
            }

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
            if (redraw)
            {
                redraw = false;
                showLeaderboard(images, imgsContainers, GameStatus);
            }
            // showScoreSectionMenuSelection(&GameStatus);
            break;

        case SECTION_ABOUT: // Affichage "A propos du jeu"
            if (redraw)
            {
                redraw = false;
                showAbout(images, imgsContainers, aboutCurrentPage);
            }
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
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                redraw = true;
                Point cursor = {event.button.x, event.button.y};
                switch (GameStatus.selectedMenu)
                {
                case SECTION_GAME:
                    inGameClickHandler(imgsContainers, cursor, &P1, &P2, &GameStatus);
                    break;
                case SECTION_ABOUT:
                    aboutClickHandler(imgsContainers, cursor, &GameStatus.selectedMenu, &aboutCurrentPage);
                    break;

                default:
                    guiClickHandler(imgsContainers, cursor, &GameStatus.selectedMenu);
                    break;
                }
            }
            break;
        }

    } while (GameStatus.selectedMenu != SECTION_EXIT);

    return 0;
}
