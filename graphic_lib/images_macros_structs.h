#ifndef IMAGE_STRUCTH
#define IMAGE_STRUCTH

#include "shapes.h"
#include "../awale_game_macros_structs.h"

//Macro POS_VAR_LEADERBOARD
#define FIRST_NAME_POS_Y 295
#define LEADERBOARD_SEPARATION 45

//Macro POS_SEEDS_AWALE
#define SEED_WIDTH 50
#define SEED_HEIGHT 50
#define AWALE_1ST_SEED_POS_X 375
#define AWALE_P1_1ST_SEED_POS_Y 275
#define AWALE_P2_1ST_SEED_POS_Y 405
#define SEED_SEPARATION 100

typedef struct {
    SDL_Texture *menu; 
    SDL_Texture *game; 
    SDL_Texture *leaderboard;
    SDL_Texture *about;
} Background;

typedef struct {
    SDL_Texture *play;
    SDL_Texture *about;
    SDL_Texture *leaderboard;
    SDL_Texture *leave;
    SDL_Texture *menu;
    SDL_Texture *mute;
    SDL_Texture *unmute;
    SDL_Texture *replay;
} Button;

typedef struct {
    SDL_Texture *deck;
    SDL_Texture *one_seed;
    SDL_Texture *two_seed;
    SDL_Texture *three_seed;
    SDL_Texture *four_seed;
} Awale;

typedef struct {
    SDL_Texture *title;
    SDL_Texture *playerVSia;
    SDL_Texture *pvp;
    SDL_Texture *sign;
    SDL_Texture *sign_leaderboard;
} Misc;

typedef struct {
    Background background;
    Button button;
    Awale awale;
    Misc misc;
} Image;

// STRUCTURES DES RECTANGLES POUR GERER L'AFFICHAGE DES IMAGES

typedef struct {
    Rect menu;
    Rect game;
    Rect leaderboard;
    Rect about;
} Rect_bg;

typedef struct {
    Rect play;
    Rect about;
    Rect leaderboard;
    Rect leave;
    Rect menu;
    Rect mute;
    Rect unmute;
    Rect replay;
} Rect_button;

typedef struct {
    Rect seeds[HOLES_PER_PLAYER];
    Rect sign;
} Rect_awale_player1;

typedef struct{
    Rect seeds[HOLES_PER_PLAYER];
    Rect sign;
} Rect_awale_player2;

typedef struct {
    Rect_awale_player1 p1;
    Rect_awale_player2 p2;
    Rect deck;
} Rect_awale;

typedef struct {
    Rect playerVSplayer;
    Rect pvp;
    Rect title;
    Rect sign_leaderboard;
} Rect_misc;

typedef struct {
    Rect_awale awale;
    Rect_button button;
    Rect_misc misc;
    Rect_bg bg;
} Rectangle;

#endif