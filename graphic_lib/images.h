#ifndef IMAGES_H
#define IMAGES_H

#include "graphic_lib.h"
#include "shapes.h"
#include "../awale_game_macros_structs.h"
#include "images_config.h"

typedef struct
{
    SDL_Texture *menu;
    SDL_Texture *game;
    SDL_Texture *leaderboard;
    SDL_Texture *about;
} Background;
typedef struct
{
    SDL_Texture *play;
    SDL_Texture *about;
    SDL_Texture *leaderboard;
    SDL_Texture *leave;
    SDL_Texture *menu;
    SDL_Texture *volume[2];
    SDL_Texture *replay;
    SDL_Texture *pvp;
    SDL_Texture *playerVSia;
} Button;
typedef struct
{
    SDL_Texture *deck;
    SDL_Texture *one_seed;
    SDL_Texture *two_seed;
    SDL_Texture *three_seed;
    SDL_Texture *four_seed;
} Awale;
typedef struct
{
    SDL_Texture *title;
    SDL_Texture *playerVSia;
    SDL_Texture *pvp;
    SDL_Texture *pseudo_sign;
    SDL_Texture *sign_leaderboard;
    SDL_Texture *seed_number_sign;
    SDL_Texture *square_sign;
    SDL_Texture *sign_about[2];
    SDL_Texture *RL_button[2];
    SDL_Texture *total_moves_text;
    SDL_Texture *moves_before_stop_text;
    SDL_Texture *enter_name[2];
} Misc;
typedef struct
{
    Background background;
    Button button;
    Awale awale;
    Misc misc;
} Images;
// STRUCTURES DES RECTANGLES POUR GERER L'AFFICHAGE DES IMAGES
typedef struct
{
    Rect menu;
    Rect game;
    Rect leaderboard;
    Rect about;
} Containers_bg;
typedef struct
{
    Rect play;
    Rect about;
    Rect leaderboard;
    Rect leave;
    Rect menu;
    Rect volume;
    Rect replay;
    Rect pvp;
    Rect playerVSia;
} Containers_button;
typedef struct
{
    Rect seeds[HOLES_PER_PLAYER];
    Rect pseudo_sign;
    Rect score_sign;
    Rect seed_number_sign;
    Rect moves_sign;
} Containers_awale_player1;
typedef struct
{
    Rect seeds[HOLES_PER_PLAYER];
    Rect pseudo_sign;
    Rect score_sign;
    Rect seed_number_sign;
    Rect moves_sign;
} Containers_awale_player2;
typedef struct
{
    Containers_awale_player1 p1;
    Containers_awale_player2 p2;
    Rect deck;
    Rect total_moves_sign;
    Rect move_countdown_sign;
    Rect total_moves_text;
    Rect moves_before_stop_text;
} Containers_awale;

typedef struct
{
    Rect pvp;
    Rect title;
    Rect sign_leaderboard;
    Rect sign_about;
    Rect RL_button[2];
    Rect playerVSia;
    Rect enter_name;
} Containers_misc;
typedef struct
{
    Containers_awale awale;
    Containers_button button;
    Containers_misc misc;
    Containers_bg bg;
} Containers;

void init_Images(Images *pImages);
void init_Images_Containers(Containers *pRectangles);
void destroy_Images(Images *pImages);

#endif