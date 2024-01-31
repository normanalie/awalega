#include "gui.h"

void initGui(Images *pImages, Containers *pRectangles)
{
    graphic_init();
    create_window(1280, 720, "Awaléga");
    init_Images(pImages);
    init_Images_Containers(pRectangles);
    return;
}

void showMenu(Images Images, Containers Rectangles)
{
    present_image(Images.background.menu, Rectangles.bg.menu);
    present_image(Images.button.play, Rectangles.button.play);
    present_image(Images.button.leaderboard, Rectangles.button.leaderboard);
    present_image(Images.button.about, Rectangles.button.about);
    present_image(Images.button.leave, Rectangles.button.leave);
    graphic_update();
}

void showAwale(Images Images, Containers Rectangles, PlayerInfo P1, PlayerInfo P2, GameStatusVar GameStatus)
{
    present_image(Images.background.game, Rectangles.bg.game);
    present_image(Images.awale.deck, Rectangles.awale.deck);

    // Signs Players
    present_image(Images.misc.pseudo_sign, Rectangles.awale.p1.pseudo_sign);
    present_image(Images.misc.pseudo_sign, Rectangles.awale.p2.pseudo_sign);
    present_image(Images.misc.seed_number_sign, Rectangles.awale.p1.seed_number_sign);
    present_image(Images.misc.seed_number_sign, Rectangles.awale.p2.seed_number_sign);
    present_image(Images.misc.square_sign, Rectangles.awale.p1.score_sign);
    present_image(Images.misc.square_sign, Rectangles.awale.p2.score_sign);
    present_image(Images.misc.square_sign, Rectangles.awale.p1.moves_sign);
    present_image(Images.misc.square_sign, Rectangles.awale.p2.moves_sign);

    // TEXTES
    present_image(Images.misc.moves_before_stop_text, Rectangles.awale.moves_before_stop_text);
    present_image(Images.misc.total_moves_text, Rectangles.awale.total_moves_text);

    // OTHERS SIGNS
    present_image(Images.misc.square_sign, Rectangles.awale.total_moves_sign);
    present_image(Images.misc.square_sign, Rectangles.awale.move_countdown_sign);
    Point total_moves;
    Point move_countdown;
    total_moves.x = 1103;
    total_moves.y = 350;
    move_countdown.x = 168;
    move_countdown.y = 350;

    char moves[3];
    char countdown[3];
    sprintf(moves, "%.2d", GameStatus.totalMoves);
    draw_text(moves, total_moves, 32, Black);
    sprintf(countdown, "%.2d", GameStatus.moveCountdown);
    draw_text(countdown, move_countdown, 32, Black);

    // TOUR DES JOUEURS
    if (GameStatus.playerTurn == 1)
    {
        present_image(Images.misc.player_turn_radio[0], Rectangles.awale.p1.player_turn_radio);
        present_image(Images.misc.player_turn_radio[1], Rectangles.awale.p2.player_turn_radio);
    }

    else
    {
        present_image(Images.misc.player_turn_radio[1], Rectangles.awale.p1.player_turn_radio);
        present_image(Images.misc.player_turn_radio[0], Rectangles.awale.p2.player_turn_radio);
    }

    // NOMBRE DE GRAINES PAR TROU
    Point Player1_lign;
    Point Player2_lign;
    Player2_lign.y = POS_Y_NUMBER_OF_SEED_PLAYER2;
    Player1_lign.y = POS_Y_NUMBER_OF_SEED_PLAYER1;
    for (int i = 0; i < 6; i++)
    {
        Player1_lign.x = POS_X_1ST_NUMBER_OF_SEED + SEPARATION_NUMBER_OF_SEED * i;
        Player2_lign.x = POS_X_1ST_NUMBER_OF_SEED + SEPARATION_NUMBER_OF_SEED * i;
        char seeds[3];
        sprintf(seeds, "%.2d", P1.seeds[i]);
        draw_text(seeds, Player1_lign, 32, Black);
        sprintf(seeds, "%.2d", P2.seeds[i]);
        draw_text(seeds, Player2_lign, 32, Black);
    }

    // NOMBRE DE COUPS DES JOUEURS
    Point Player1_moves;
    Point Player2_moves;
    Player1_moves.x = 860;
    Player2_moves.x = 860;
    Player2_moves.y = 68;
    Player1_moves.y = 618;
    char moves1[3];
    char moves2[3];
    sprintf(moves1, "%.2d", P1.moves);
    draw_text(moves1, Player1_moves, 36, Black);
    sprintf(moves2, "%.2d", P2.moves);
    draw_text(moves2, Player2_moves, 36, Black);

    // SCORE DES JOUEURS
    Point Player1_score;
    Point Player2_score;
    Player1_score.x = 395;
    Player2_score.x = 395;
    Player2_score.y = 68;
    Player1_score.y = 618;
    char score1[3];
    char score2[3];
    sprintf(score1, "%.2d", P1.harvestedSeeds);
    draw_text(score1, Player1_score, 36, Black);
    sprintf(score2, "%.2d", P2.harvestedSeeds);
    draw_text(score2, Player2_score, 36, Black);

    // Seeds Player 1
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {

        if (P1.seeds[i] == 1)
            present_image(Images.awale.one_seed, Rectangles.awale.p1.seeds[i]);

        else if (P1.seeds[i] == 2)
            present_image(Images.awale.two_seed, Rectangles.awale.p1.seeds[i]);

        else if (P1.seeds[i] == 3)
            present_image(Images.awale.three_seed, Rectangles.awale.p1.seeds[i]);

        else if (P1.seeds[i] >= 4)
            present_image(Images.awale.four_seed, Rectangles.awale.p1.seeds[i]);
    }

    // Seeds Player 2
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {

        if (P2.seeds[i] == 1)
            present_image(Images.awale.one_seed, Rectangles.awale.p2.seeds[i]);

        else if (P2.seeds[i] == 2)
            present_image(Images.awale.two_seed, Rectangles.awale.p2.seeds[i]);

        else if (P2.seeds[i] == 3)
            present_image(Images.awale.three_seed, Rectangles.awale.p2.seeds[i]);

        else if (P2.seeds[i] >= 4)
            present_image(Images.awale.four_seed, Rectangles.awale.p2.seeds[i]);
    }

    // Player_win_sign
    if (GameStatus.isGameJustEnded == 1)
        present_image(Images.misc.player_win_sign, Rectangles.misc.player_win_sign);
    graphic_update();
}

void showLeaderboard(Images Images, Containers Rectangles, GameStatusVar GameStatus)
{
    PlayerScore RecordedScores[5];
    readScores(RecordedScores);
    present_image(Images.background.menu, Rectangles.bg.menu);
    present_image(Images.misc.sign_leaderboard, Rectangles.misc.sign_leaderboard);

    Point Name;
    Point Score;
    Point Moves;

    Name.x = 495;
    Score.x = 650;
    Moves.x = 800;

    for (int i = 0; i < 5; i++)
    {
        Name.y = FIRST_NAME_POS_Y + LEADERBOARD_SEPARATION * i;
        Score.y = FIRST_NAME_POS_Y + LEADERBOARD_SEPARATION * i;
        Moves.y = FIRST_NAME_POS_Y + LEADERBOARD_SEPARATION * i;
        char s[5];
        draw_text(RecordedScores[i].name, Name, 24, Black);
        sprintf(s, "%.2d", RecordedScores[i].score);
        draw_text(s, Score, 24, Black);
        sprintf(s, "%.2d", RecordedScores[i].moves);
        draw_text(s, Moves, 24, Black);
    }

    showReplayButton(Images, Rectangles, GameStatus);
    graphic_update();
}

void showAbout(Images Images, Containers Rectangles, int currentPage)
{
    printf("Current page: %d\n", currentPage);
    present_image(Images.background.about, Rectangles.bg.menu);
    present_image(Images.misc.sign_about[currentPage], Rectangles.misc.sign_about);
    present_image(Images.misc.RL_button[currentPage], Rectangles.misc.RL_button[currentPage]);
    graphic_update();
}

void showGameModeSelection(Images Images, Containers Rectangles)
{
    present_image(Images.background.game, Rectangles.bg.game);
    present_image(Images.misc.pvp, Rectangles.misc.pvp);
    present_image(Images.misc.playerVSia, Rectangles.misc.playerVSia);
    present_image(Images.button.playerVSia, Rectangles.button.playerVSia);
    present_image(Images.button.pvp, Rectangles.button.pvp);
    graphic_update();
}

void showInitPlayer(Images Images, Containers Rectangles, int currentPlayer)
{
    present_image(Images.background.game, Rectangles.bg.game);
    present_image(Images.misc.enter_name[currentPlayer - 1], Rectangles.misc.enter_name);
    graphic_update();
}

void showMenuButton(Images Images, Containers Rectangles, GameStatusVar GameStatus)
{
    if (GameStatus.selectedMenu != SECTION_HOME)
        present_image(Images.button.menu, Rectangles.button.menu);
    graphic_update();
}

void showVolumeButton(Images Images, Containers Rectangles, GameStatusVar GameStatus)
{
    if (GameStatus.isSoundON == 1)
        present_image(Images.button.volume[1], Rectangles.button.volume);
    else
        present_image(Images.button.volume[0], Rectangles.button.volume);
    graphic_update();
}

void showReplayButton(Images Images, Containers Rectangles, GameStatusVar GameStatus)
{
    if (GameStatus.isGameJustEnded == 1)
    {
        present_image(Images.button.replay, Rectangles.button.replay);
    }
    graphic_update();
}

void destroyGui(Images *pImages)
{
    destroy_Images(pImages);
    destroy_window();
}

void menuClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu)
{
    if (is_in(cursor, Rectangles.button.play))
    {
        printf("Click play\n");
        *pSelectedMenu = SECTION_NEW_GAME;
        return;
    }
    if (is_in(cursor, Rectangles.button.leaderboard))
    {
        printf("Click leaderboard\n");
        *pSelectedMenu = SECTION_SCORE;
        return;
    }
    if (is_in(cursor, Rectangles.button.about))
    {
        printf("Click about\n");
        *pSelectedMenu = SECTION_ABOUT;
        return;
    }
    if (is_in(cursor, Rectangles.button.leave))
    {
        printf("Click leave\n");
        *pSelectedMenu = SECTION_EXIT;
        return;
    }
}

void leaderboardClickHandler(Containers Rectangles, Point cursor, int *pSelectedHander)
{
    // No button in leaderboard ??
}

void aboutClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu)
{
    // No button in leaderboard ??
}

void inGameClickHandler(Containers Rectangles, Point cursor, PlayerInfo *pP1, PlayerInfo *pP2, GameStatusVar *pGameStatus)
{
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {
        if (is_in(cursor, Rectangles.awale.p1.seeds[i]))
        {
            printf("Click\n");
            if (pGameStatus->playerTurn == 1)
            {
                playMove(pP1, pP2, pGameStatus);
            }
        }
        if (is_in(cursor, Rectangles.awale.p2.seeds[i]))
        {
            printf("Click\n");
            if (pGameStatus->playerTurn == 2)
            {
                playMove(pP1, pP2, pGameStatus);
            }
        }
    }
}

void guiClickHandler(Containers Rectangles, Point cursor, int *pSelectedMenu)
{
    switch (*pSelectedMenu)
    {
    case SECTION_HOME:
        menuClickHandler(Rectangles, cursor, pSelectedMenu);
        break;
    case SECTION_SCORE:
        leaderboardClickHandler(Rectangles, cursor, pSelectedMenu);
        break;
    case SECTION_ABOUT:
        aboutClickHandler(Rectangles, cursor, pSelectedMenu);
        break;
    case SECTION_EXIT_SCREEN:
        *pSelectedMenu = SECTION_EXIT;
        break;
    case SECTION_EXIT:
        break;
    default:
        break;
    }
}

/*
PROTO: playMove(Player1, Player2, trouID, GameStatus) -> nextPlayer{
    Si illegal{
        retourne GamesStatus.currentPlayer -> besoin de rejouer
    }
    Modifier GameStatus
    Modifie le plateau
    Si p2 est bot{
        attend
        fais jouer p2
    }
    Verifie le plateau
    Calcule nextplayer
    retourne nextplayer
}
*/