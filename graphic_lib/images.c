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
    pImages->button.volume[0] = loadImage("images/sound_off.bmp");
    pImages->button.volume[1] = loadImage("images/sound_on.bmp");
    pImages->button.replay = loadImage("images/replay.bmp");
    pImages->button.playerVSia = loadImage("images/sign_1vsbot.bmp");
    pImages->button.pvp = loadImage("images/sign_1vsplayer.bmp");
    pImages->misc.sign_about[0] = loadImage("images/sign_about1.bmp");
    pImages->misc.sign_about[1] = loadImage("images/sign_about2.bmp");
    pImages->misc.RL_button[0] = loadImage("images/button_right.bmp");
    pImages->misc.RL_button[1] = loadImage("images/button_left.bmp");
    pImages->misc.moves_before_stop_text = loadImage("images/moves_before_stop_text.bmp");
    pImages->misc.total_moves_text = loadImage("images/total_moves_text.bmp");
    pImages->misc.enter_name[0]= loadImage("images/enter_name1.bmp");
    pImages->misc.enter_name[1]= loadImage("images/enter_name2.bmp");
    pImages->misc.player_turn_radio[0]= loadImage("images/player_turn_radio_on.bmp");
    pImages->misc.player_turn_radio[1]= loadImage("images/player_turn_radio_off.bmp");
    pImages->misc.player_win_sign= loadImage("images/player_win_sign.bmp");
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

    // BUTTON
    pRectangles->button.menu.topleft.x = 15;
    pRectangles->button.menu.topleft.y = 15;
    pRectangles->button.menu.w = 90;
    pRectangles->button.menu.h = 90;

    pRectangles->button.volume.topleft.x = 1175;
    pRectangles->button.volume.topleft.y = 15;
    pRectangles->button.volume.w = 90;
    pRectangles->button.volume.h = 90;

    pRectangles->button.replay.topleft.x=595;
    pRectangles->button.replay.topleft.y= 590;
    pRectangles->button.replay.w=90;
    pRectangles->button.replay.h=90;

    pRectangles->button.pvp.topleft.x= 755;
    pRectangles->button.pvp.topleft.y= 165;
    pRectangles->button.pvp.w= 270;
    pRectangles->button.pvp.h= 90;
    pRectangles->button.playerVSia.topleft.x= 255;
    pRectangles->button.playerVSia.topleft.y= 165;
    pRectangles->button.playerVSia.w= 270;
    pRectangles->button.playerVSia.h= 90;

    // ABOUT
    pRectangles->misc.sign_about.topleft.x = 315;
    pRectangles->misc.sign_about.topleft.y = 90;
    pRectangles->misc.sign_about.w = 650;
    pRectangles->misc.sign_about.h = 535;
    pRectangles->misc.RL_button[0].topleft.x=995;
    pRectangles->misc.RL_button[0].topleft.y=330;
    pRectangles->misc.RL_button[0].w=120;
    pRectangles->misc.RL_button[0].h=90;
    pRectangles->misc.RL_button[1].topleft.x=170;
    pRectangles->misc.RL_button[1].topleft.y=330;
    pRectangles->misc.RL_button[1].w=120;
    pRectangles->misc.RL_button[1].h=90;

    // GameModeSelection
    pRectangles->misc.playerVSia.topleft.x=200;
    pRectangles->misc.playerVSia.topleft.y=300;
    pRectangles->misc.playerVSia.w=380;
    pRectangles->misc.playerVSia.h=300;
    pRectangles->misc.pvp.topleft.x=700;
    pRectangles->misc.pvp.topleft.y=320;
    pRectangles->misc.pvp.w=380;
    pRectangles->misc.pvp.h=240;

    pRectangles->misc.enter_name.topleft.x = 340;
    pRectangles->misc.enter_name.topleft.y = 110;
    pRectangles->misc.enter_name.w = 600;
    pRectangles->misc.enter_name.h = 495;

    // AWALE
    pRectangles->bg.game.topleft.x = 0;
    pRectangles->bg.game.topleft.y = 0;
    pRectangles->bg.game.w = 1280;
    pRectangles->bg.game.h = 720;

    pRectangles->awale.deck.topleft.x = 340;
    pRectangles->awale.deck.topleft.y = 235;
    pRectangles->awale.deck.w = 620;
    pRectangles->awale.deck.h = 250;

    pRectangles->awale.total_moves_sign.topleft.x = 1060;
    pRectangles->awale.total_moves_sign.topleft.y = 320;
    pRectangles->awale.total_moves_sign.w = 120;
    pRectangles->awale.total_moves_sign.h = 90;

    pRectangles->awale.move_countdown_sign.topleft.x = 125;
    pRectangles->awale.move_countdown_sign.topleft.y = 320;
    pRectangles->awale.move_countdown_sign.w = 120;
    pRectangles->awale.move_countdown_sign.h = 90;

    pRectangles->awale.moves_before_stop_text.topleft.x= 75;
    pRectangles->awale.moves_before_stop_text.topleft.y= 275;
    pRectangles->awale.moves_before_stop_text.w= 230;
    pRectangles->awale.moves_before_stop_text.h= 30;

    pRectangles->awale.total_moves_text.topleft.x= 1035;
    pRectangles->awale.total_moves_text.topleft.y= 275;
    pRectangles->awale.total_moves_text.w= 170;
    pRectangles->awale.total_moves_text.h= 30;

    pRectangles->misc.player_win_sign.topleft.x= 440;
    pRectangles->misc.player_win_sign.topleft.y= 280;
    pRectangles->misc.player_win_sign.w= 425;
    pRectangles->misc.player_win_sign.h= 160;

    // Sign Player 2
    pRectangles->awale.p2.pseudo_sign.topleft.x = 500;
    pRectangles->awale.p2.pseudo_sign.topleft.y = 40;
    pRectangles->awale.p2.pseudo_sign.w = 300;
    pRectangles->awale.p2.pseudo_sign.h = 90;

    pRectangles->awale.p2.seed_number_sign.topleft.x = 340;
    pRectangles->awale.p2.seed_number_sign.topleft.y = 140;
    pRectangles->awale.p2.seed_number_sign.w = 620;
    pRectangles->awale.p2.seed_number_sign.h = 90;

    pRectangles->awale.p2.moves_sign.topleft.x = 820;
    pRectangles->awale.p2.moves_sign.topleft.y = 40;
    pRectangles->awale.p2.moves_sign.w = 120;
    pRectangles->awale.p2.moves_sign.h = 90;

    pRectangles->awale.p2.score_sign.topleft.x = 355;
    pRectangles->awale.p2.score_sign.topleft.y = 40;
    pRectangles->awale.p2.score_sign.w = 120;
    pRectangles->awale.p2.score_sign.h = 90;

    pRectangles->awale.p2.player_turn_radio.topleft.x= 975;
    pRectangles->awale.p2.player_turn_radio.topleft.y= 155;
    pRectangles->awale.p2.player_turn_radio.w= 60;
    pRectangles->awale.p2.player_turn_radio.h= 60;


    // Sign Player 1
    pRectangles->awale.p1.pseudo_sign.topleft.x = 500;
    pRectangles->awale.p1.pseudo_sign.topleft.y = 590;
    pRectangles->awale.p1.pseudo_sign.w = 300;
    pRectangles->awale.p1.pseudo_sign.h = 90;

    pRectangles->awale.p1.seed_number_sign.topleft.x = 340;
    pRectangles->awale.p1.seed_number_sign.topleft.y = 490;
    pRectangles->awale.p1.seed_number_sign.w = 620;
    pRectangles->awale.p1.seed_number_sign.h = 90;

    pRectangles->awale.p1.moves_sign.topleft.x = 820;
    pRectangles->awale.p1.moves_sign.topleft.y = 590;
    pRectangles->awale.p1.moves_sign.w = 120;
    pRectangles->awale.p1.moves_sign.h = 90;

    pRectangles->awale.p1.score_sign.topleft.x = 355;
    pRectangles->awale.p1.score_sign.topleft.y = 590;
    pRectangles->awale.p1.score_sign.w = 120;
    pRectangles->awale.p1.score_sign.h = 90;

    pRectangles->awale.p1.player_turn_radio.topleft.x= 975;
    pRectangles->awale.p1.player_turn_radio.topleft.y= 505;
    pRectangles->awale.p1.player_turn_radio.w= 60;
    pRectangles->awale.p1.player_turn_radio.h= 60;

    // Seeds Player 2
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {
        pRectangles->awale.p2.seeds[i].topleft.x = AWALE_1ST_SEED_POS_X + i * SEED_SEPARATION;
        pRectangles->awale.p2.seeds[i].topleft.y = AWALE_P2_1ST_SEED_POS_Y;
        pRectangles->awale.p2.seeds[i].w = SEED_WIDTH;
        pRectangles->awale.p2.seeds[i].h = SEED_HEIGHT;
    }

    // Seeds Player 1
    for (int i = 0; i < HOLES_PER_PLAYER; i++)
    {
        pRectangles->awale.p1.seeds[i].topleft.x = AWALE_1ST_SEED_POS_X + i * SEED_SEPARATION;
        pRectangles->awale.p1.seeds[i].topleft.y = AWALE_P1_1ST_SEED_POS_Y;
        pRectangles->awale.p1.seeds[i].w = SEED_WIDTH;
        pRectangles->awale.p1.seeds[i].h = SEED_HEIGHT;
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