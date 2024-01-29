#ifndef IMAGE_STRUCTH
#define IMAGE_STRUCTH

#include <SDL2/SDL.h>
#include "shapes.h"

typedef struct background{
    SDL_Texture *menu; 
    SDL_Texture *game; 
    SDL_Texture *leaderboard;
    SDL_Texture *about;
} Background;

typedef struct button{
    SDL_Texture *play;
    SDL_Texture *about;
    SDL_Texture *leaderboard;
    SDL_Texture *leave;
} Button;

typedef struct awale{
    SDL_Texture *deck;
    SDL_Texture *one_seed;
    SDL_Texture *two_seed;
    SDL_Texture *three_seed;
    SDL_Texture *four_seed;
} Awale;

typedef struct misc{
    SDL_Texture *title;
    SDL_Texture *playerVSia;
    SDL_Texture *pvp;
} Misc;

typedef struct image{
    Background background;
    Button button;
    Awale awale;
    Misc misc;
} Image;

// STRUCTURES DES RECTANGLES POUR GERER L'AFFICHAGE DES IMAGES

typedef struct rect_bg{
    Rect menu;
    Rect game;
    Rect leaderboard;
    Rect about;
} Rect_bg;

typedef struct rect_button{
    Rect play;
    Rect about;
    Rect leaderboard;
    Rect leave;
} Rect_button;

typedef struct rect_awale{
    Rect one_seed;
    Rect two_seed;
    Rect three_seed;
    Rect four_seed;
    Rect deck;
} Rect_awale;

typedef struct rect_misc{
    Rect playerVSplayer;
    Rect pvp;
    Rect title;
} Rect_misc;

typedef struct rectangle_image{
    Rect_awale awale;
    Rect_button button;
    Rect_misc misc;
    Rect_bg bg;
} Rectangle;

#endif