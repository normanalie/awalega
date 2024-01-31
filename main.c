#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "awale_game_macros_structs.h"
#include "awale_game.h"
#include "score_handler.h"
#include "utilities.h"
#include "graphic_lib/gui.h"
#include "audio_lib/audio_lib.h"

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
    GameStatus.isSoundON = 1;

    PlayerInfo P1;
    PlayerInfo P2;
    initPlayers(&P1, &P2);

    Images images;
    Containers imgsContainers;
    initGui(&images, &imgsContainers);

    audio Audio;
    openAudio();
    openSoundChannels(NUM_CHANNELS);

    loadAllMusics(&Audio);
    loadAllSounds(&Audio);
    initAudio();
    actualAudioVolume(GameStatus.isSoundON ? DEFAULT_VOLUME : 0);
    GameStatus.currentMusic = MUSIC_STRUCT.menuMusic;

    playAudio(GameStatus.currentMusic.music, REP_INF);

    bool redraw = true;
    int aboutCurrentPage = 0;
    SDL_Event event;
    do
    {
        actualAudioVolume(GameStatus.isSoundON ? DEFAULT_VOLUME : 0);
        soundVolumeUpdate(NUM_CHANNELS, GameStatus.isSoundON ? DEFAULT_VOLUME : 0);
        switch (GameStatus.selectedMenu)
        {
        case SECTION_HOME:
            if (redraw)
            {
                redraw = false;
                showMenu(images, imgsContainers, GameStatus);
                if (GameStatus.currentMusic.ID != MENU_MUSIC.ID)
                {
                    GameStatus.currentMusic = MENU_MUSIC;
                    playAudio(MUSIC_STRUCT.menuMusic.music, REP_INF);
                }
            }
            GameStatus.isGameJustEnded = 0;
            break;

        case SECTION_NEW_GAME:
            if (redraw)
            {
                redraw = false;
                showGameModeSelection(images, imgsContainers, GameStatus);
            }
            initGameStatus(&GameStatus);
            initPlayers(&P1, &P2);
            break;

        case SECTION_NAME_FORM1:
            if (redraw)
            {
                redraw = false;
                showInitPlayer(images, imgsContainers, GameStatus, 1);
                Point pseudoPos = {600, 300};
                draw_text(P1.name, pseudoPos, 52, White);
                graphic_update();
            }
            break;

        case SECTION_NAME_FORM2:
            if (redraw)
            {
                redraw = false;
                showInitPlayer(images, imgsContainers, GameStatus, 2);
                Point pseudoPos = {600, 300};
                draw_text(P2.name, pseudoPos, 52, White);
                graphic_update();
            }
            break;

        case SECTION_GAME:
            if (redraw)
            {
                redraw = false;
                showAwale(images, imgsContainers, P1, P2, GameStatus);
                if (GameStatus.currentMusic.ID != INGAME_MUSIC.ID)
                {
                    GameStatus.currentMusic = INGAME_MUSIC;
                    playAudio(MUSIC_STRUCT.inGameMusic.music, -1);
                }
            }

            if (GameStatus.endgameType != NO_ENDGAME) // Fin de partie
            {

                // Gestionnaire de fin de jeu + Afficher message correspondant
                GameStatus.isGameJustEnded = 1;
                endgameManager(&GameStatus);
                whoWon(&P1, &P2, &GameStatus);

                // Afficher le tablier et les infos du jeu une dernière fois avant de quitter afin que les joueurs puisse voir ce qu'il s'est passé
                showAwale(images, imgsContainers, P1, P2, GameStatus);
                // FCt() rajout texte par dessus pour donner le gagnant
                SDL_Delay(1000);

                // Ecriture des scores
                if (GameStatus.selectedMenu == SECTION_SCORE)
                {
                    saveScores(P1, P2);
                    redraw = true;
                }
            }

            break;

        case SECTION_SCORE: // Affichage Score
            if (redraw)
            {
                redraw = false;
                showLeaderboard(images, imgsContainers, GameStatus);
                if (GameStatus.currentMusic.ID != LEADERBOARD_MUSIC.ID)
                {
                    GameStatus.currentMusic = LEADERBOARD_MUSIC;
                    playAudio(MUSIC_STRUCT.leaderboardMusic.music, -1);
                }
            }
            if (GameStatus.isGameJustEnded)
            {
                showReplayButton(images, imgsContainers);
                graphic_update();
            }
            break;

        case SECTION_ABOUT: // Affichage "A propos du jeu"
            if (redraw)
            {
                redraw = false;
                showAbout(images, imgsContainers, GameStatus, aboutCurrentPage);
                if (GameStatus.currentMusic.ID != ABOUT_MUSIC.ID)
                {
                    GameStatus.currentMusic = ABOUT_MUSIC;
                    playAudio(MUSIC_STRUCT.aboutMusic.music, REP_INF);
                }
            }
            break;

        case SECTION_EXIT_SCREEN: // Quitter le jeu
            GameStatus.selectedMenu = SECTION_EXIT;
            break;
        }

        // Partie BOT
        if (P2.isBot && GameStatus.playerTurn == 2 && GameStatus.selectedMenu == SECTION_GAME)
        {
            GameStatus.selectedHole = randInt(1, HOLES_PER_PLAYER);
            playMove(&P1, &P2, &GameStatus);
            showAwale(images, imgsContainers, P1, P2, GameStatus);
        }

        // Partie SDL
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
                volumeButtonClickHandler(imgsContainers, cursor, &GameStatus);
                SOUND_EFFECTS sound = MOUSECLICK;
                soundPlayEffect(sound);
                switch (GameStatus.selectedMenu)
                {
                case SECTION_HOME:
                    guiClickHandler(imgsContainers, cursor, &GameStatus);
                    break;
                case SECTION_NEW_GAME:
                    newGameClickHandler(imgsContainers, cursor, &GameStatus, &P2);
                    break;
                case SECTION_NAME_FORM1:
                case SECTION_NAME_FORM2:
                    nameFormClickHandler(imgsContainers, cursor, &GameStatus);
                    break;
                case SECTION_GAME:
                    inGameClickHandler(imgsContainers, cursor, &P1, &P2, &GameStatus);
                    break;
                case SECTION_SCORE:
                    leaderboardClickHandler(imgsContainers, cursor, &GameStatus);
                    break;
                case SECTION_ABOUT:
                    aboutClickHandler(imgsContainers, cursor, &GameStatus.selectedMenu, &aboutCurrentPage);
                    break;

                default:
                    guiClickHandler(imgsContainers, cursor, &GameStatus);
                    break;
                }
            }
            break;

        case SDL_TEXTINPUT:

            if (GameStatus.selectedMenu == SECTION_NAME_FORM1)
            {
                playSound(SOUND_STRUCT.typing.numChannel, SOUND_STRUCT.typing.sound, 0);
                addLetterToPseudo(&P1, event.text.text);
                redraw = true;
            }
            else if (GameStatus.selectedMenu == SECTION_NAME_FORM2 && !P2.isBot)
            {
                playSound(SOUND_STRUCT.typing.numChannel, SOUND_STRUCT.typing.sound, 0);
                addLetterToPseudo(&P2, event.text.text);
                redraw = true;
            }
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_RETURN) // Si "Entrée" est pressé
            {
                if (GameStatus.selectedMenu == SECTION_NAME_FORM1 && !P2.isBot)
                {

                    if (strlen(P1.name) >= NAME_MIN_LEN)
                    {
                    case SECTION_NEW_GAME:
                        newGameClickHandler(imgsContainers, cursor, &GameStatus, &P2);
                        break;
                    case SECTION_NAME_FORM1:
                    case SECTION_NAME_FORM2:
                        nameFormClickHandler(imgsContainers, cursor, &GameStatus);
                        break;
                    case SECTION_GAME:
                        inGameClickHandler(imgsContainers, cursor, &P1, &P2, &GameStatus);
                        break;
                    case SECTION_SCORE:
                        leaderboardClickHandler(imgsContainers, cursor, &GameStatus);
                        break;
                    case SECTION_ABOUT:
                        aboutClickHandler(imgsContainers, cursor, &GameStatus.selectedMenu, &aboutCurrentPage);
                        break;

                    default:
                        guiClickHandler(imgsContainers, cursor, &GameStatus);
                        break;
                    }
                }
                else if (GameStatus.selectedMenu == SECTION_NAME_FORM1)
                {

                    if (strlen(P1.name) >= NAME_MIN_LEN)
                    {
                        GameStatus.selectedMenu = SECTION_GAME;
                        strcpy(P2.name, "Bot");
                        redraw = true;
                    }
                }
                else if (GameStatus.selectedMenu == SECTION_NAME_FORM2)
                {

                    if (strlen(P2.name) >= NAME_MIN_LEN)
                    {
                        GameStatus.selectedMenu = SECTION_GAME;
                        redraw = true;
                    }
                }
                printf("Entrée\n");
            }
            break;
        }

    } while (GameStatus.selectedMenu != SECTION_EXIT);

    freeAllSounds(&Audio);
    freeAllMusics(&Audio);
    return 0;
}
