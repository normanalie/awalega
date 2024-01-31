#include "images.h"

void init_Images(Images *pImages)
{
    pImages->background.menu = loadImage("images/menu_bg.bmp");
    pImages->background.game = loadImage("images/game_bg.bmp");
    pImages->background.about = loadImage("images/menu_bg.bmp");
    pImages->button.play = loadImage("images/play.bmp");
    pImages->button.about = loadImage("images/about.bmp");
    pImages->button.leaderboard = loadImage("images/leaderboard.bmp");
    pImages->button.leave = loadImage("images/leave.bmp");
    pImages->awale.one_seed = loadImage("images/one_seed.bmp");
    pImages->awale.two_seed = loadImage("images/two_seeds.bmp");
    pImages->awale.three_seed = loadImage("images/three_seeds.bmp");
    pImages->awale.four_seed = loadImage("images/four_seeds.bmp");
    pImages->awale.deck = loadImage("images/deck.bmp");
    pImages->misc.playerVSia = loadImage("images/playerVSia.bmp");
    pImages->misc.pvp = loadImage("images/pvp.bmp");
    pImages->misc.pseudo_sign = loadImage("images/pseudo_sign.bmp");
    pImages->misc.seed_number_sign = loadImage("images/seed_number_sign.bmp");
    pImages->misc.square_sign = loadImage("images/square_sign.bmp");
    pImages->misc.sign_leaderboard = loadImage("images/sign_leaderboard.bmp");
    pImages->button.menu = loadImage("images/menu.bmp");
    pImages->button.mute = loadImage("images/mute.bmp");
    pImages->button.unmute = loadImage("images/unmute.bmp");
    pImages->button.replay = loadImage("images/replay.bmp");
    pImages->misc.sign_about[0] = loadImage("images/sign_about1.bmp");
    pImages->misc.sign_about[1] = loadImage("images/sign_about2.bmp");
}

void init_Images_Containers(Containers *pRectangles)
{
    // MENU
    pRectangles->bg.menu.topleft.x = 0;
    pRectangles->bg.menu.topleft.y = 0;
    pRectangles->bg.menu.w = 1280;
    pRectangles->bg.menu.h = 720;
    pRectangles->button.play.topleft.x = 560;
    pRectangles->button.play.topleft.y = 300;
    pRectangles->button.play.w = 240;
    pRectangles->button.play.h = 65;
    pRectangles->button.leaderboard.topleft.x = 560;
    pRectangles->button.leaderboard.topleft.y = 365;
    pRectangles->button.leaderboard.w = 240;
    pRectangles->button.leaderboard.h = 65;
    pRectangles->button.about.topleft.x = 560;
    pRectangles->button.about.topleft.y = 430;
    pRectangles->button.about.w = 240;
    pRectangles->button.about.h = 65;
    pRectangles->button.leave.topleft.x = 1030;
    pRectangles->button.leave.topleft.y = 645;
    pRectangles->button.leave.w = 240;
    pRectangles->button.leave.h = 65;

    // ABOUT
    pRectangles->misc.sign_about.topleft.x = 340;
    pRectangles->misc.sign_about.topleft.y = 90;
    pRectangles->misc.sign_about.w = 650;
    pRectangles->misc.sign_about.h = 535;

    // AWALE
    pRectangles->bg.game.topleft.x = 0;
    pRectangles->bg.game.topleft.y = 0;
    pRectangles->bg.game.w = 1280;
    pRectangles->bg.game.h = 720;
    pRectangles->awale.deck.topleft.x = 340;
    pRectangles->awale.deck.topleft.y = 235;
    pRectangles->awale.deck.w = 620;
    pRectangles->awale.deck.h = 250;
    pRectangles->awale.total_moves.topleft.x = 1060;
    pRectangles->awale.total_moves.topleft.y = 320;
    pRectangles->awale.total_moves.w = 120;
    pRectangles->awale.total_moves.h = 90;
    pRectangles->awale.move_countdown.topleft.x = 125;
    pRectangles->awale.move_countdown.topleft.y = 320;
    pRectangles->awale.move_countdown.w = 120;
    pRectangles->awale.move_countdown.h = 90;

    // Sign Player 1
    pRectangles->awale.p1.pseudo_sign.topleft.x = 500;
    pRectangles->awale.p1.pseudo_sign.topleft.y = 40;
    pRectangles->awale.p1.pseudo_sign.w = 300;
    pRectangles->awale.p1.pseudo_sign.h = 90;
    pRectangles->awale.p1.seed_number_sign.topleft.x = 340;
    pRectangles->awale.p1.seed_number_sign.topleft.y = 140;
    pRectangles->awale.p1.seed_number_sign.w = 620;
    pRectangles->awale.p1.seed_number_sign.h = 90;
    pRectangles->awale.p1.moves_sign.topleft.x = 820;
    pRectangles->awale.p1.moves_sign.topleft.y = 40;
    pRectangles->awale.p1.moves_sign.w = 120;
    pRectangles->awale.p1.moves_sign.h = 90;
    pRectangles->awale.p1.score_sign.topleft.x = 355;
    pRectangles->awale.p1.score_sign.topleft.y = 40;
    pRectangles->awale.p1.score_sign.w = 120;
    pRectangles->awale.p1.score_sign.h = 90;

    // Sign Player 2
    pRectangles->awale.p2.pseudo_sign.topleft.x = 500;
    pRectangles->awale.p2.pseudo_sign.topleft.y = 590;
    pRectangles->awale.p2.pseudo_sign.w = 300;
    pRectangles->awale.p2.pseudo_sign.h = 90;
    pRectangles->awale.p2.seed_number_sign.topleft.x = 340;
    pRectangles->awale.p2.seed_number_sign.topleft.y = 490;
    pRectangles->awale.p2.seed_number_sign.w = 620;
    pRectangles->awale.p2.seed_number_sign.h = 90;
    pRectangles->awale.p2.moves_sign.topleft.x = 820;
    pRectangles->awale.p2.moves_sign.topleft.y = 590;
    pRectangles->awale.p2.moves_sign.w = 120;
    pRectangles->awale.p2.moves_sign.h = 90;
    pRectangles->awale.p2.score_sign.topleft.x = 355;
    pRectangles->awale.p2.score_sign.topleft.y = 590;
    pRectangles->awale.p2.score_sign.w = 120;
    pRectangles->awale.p2.score_sign.h = 90;

    // Seeds Player 1
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {
        pRectangles->awale.p1.seeds[i].topleft.x = AWALE_1ST_SEED_POS_X + i * SEED_SEPARATION;
        pRectangles->awale.p1.seeds[i].topleft.y = AWALE_P1_1ST_SEED_POS_Y;
        pRectangles->awale.p1.seeds[i].w = SEED_WIDTH;
        pRectangles->awale.p1.seeds[i].h = SEED_HEIGHT;
    }

    // Seeds Player 2
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {
        pRectangles->awale.p2.seeds[i].topleft.x = AWALE_1ST_SEED_POS_X + i * SEED_SEPARATION;
        pRectangles->awale.p2.seeds[i].topleft.y = AWALE_P2_1ST_SEED_POS_Y;
        pRectangles->awale.p2.seeds[i].w = SEED_WIDTH;
        pRectangles->awale.p2.seeds[i].h = SEED_HEIGHT;
    }

    // Sign Leaderboard
    pRectangles->misc.sign_leaderboard.topleft.x = 340;
    pRectangles->misc.sign_leaderboard.topleft.y = 110;
    pRectangles->misc.sign_leaderboard.w = 600;
    pRectangles->misc.sign_leaderboard.h = 495;
}

void destroy_Images(Images *pImages)
{
    SDL_DestroyTexture(pImages->background.menu);
    SDL_DestroyTexture(pImages->background.game);
    SDL_DestroyTexture(pImages->button.play);
    SDL_DestroyTexture(pImages->button.about);
    SDL_DestroyTexture(pImages->button.leaderboard);
    SDL_DestroyTexture(pImages->button.leave);
    SDL_DestroyTexture(pImages->awale.one_seed);
    SDL_DestroyTexture(pImages->awale.two_seed);
    SDL_DestroyTexture(pImages->awale.three_seed);
    SDL_DestroyTexture(pImages->awale.four_seed);
    SDL_DestroyTexture(pImages->awale.deck);
    SDL_DestroyTexture(pImages->misc.playerVSia);
    SDL_DestroyTexture(pImages->misc.pvp);
}