#ifndef IMAGE_STRUCTH
#define IMAGE_STRUCTH

#include <SDL2/SDL.h>

typedef struct background{
    SDL_Texture *menu; 
    SDL_Texture *game; 
    SDL_Texture *leaderboard;
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

#endif