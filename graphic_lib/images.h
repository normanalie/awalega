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
    SDL_Texture *mute;
    SDL_Texture *unmute;
    SDL_Texture *replay;
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
    SDL_Texture *sign;
    SDL_Texture *sign_leaderboard;
} Misc;

typedef struct
{
    Background background;
    Button button;
    Awale awale;
    Misc misc;
} Images;

typedef struct
{
    Rect menu;
    Rect game;
    Rect leaderboard;
    Rect about;
} Container_bg;

typedef struct
{
    Rect play;
    Rect about;
    Rect leaderboard;
    Rect leave;
    Rect menu;
    Rect mute;
    Rect unmute;
    Rect replay;
} Container_button;

typedef struct
{
    Rect seeds[HOLES_PER_PLAYER];
    Rect sign;
} Container_awale_player1;

typedef struct
{
    Rect seeds[HOLES_PER_PLAYER];
    Rect sign;
} Container_awale_player2;

typedef struct
{
    Container_awale_player1 p1;
    Container_awale_player2 p2;
    Rect deck;
} Container_awale;

typedef struct
{
    Rect playerVSplayer;
    Rect pvp;
    Rect title;
    Rect sign_leaderboard;
} Container_misc;

typedef struct
{
    Container_awale awale;
    Container_button button;
    Container_misc misc;
    Container_bg bg;
} Containers;

void init_Images(Images *pImages);
void init_Images_Containers(Containers *pRectangles);
void destroy_Images(Images *pImages);

#endif