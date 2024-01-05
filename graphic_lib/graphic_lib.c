#include "graphic_lib.h"

SDL_Window *pWindow = NULL;

int graphic_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }
    return 0;
}

void create_window(int W, int H, const char *name)
{
    pWindow = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               W,
                               H,
                               SDL_WINDOW_SHOWN);
}

void destroy_window()
{
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}