#include "graphic_lib.h"

SDL_Window *pWindow = NULL;
SDL_Renderer *pRenderer = NULL;
SDL_Surface *pSurface = NULL;

int graphic_init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
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
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    pSurface = SDL_GetWindowSurface(pWindow);

    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}

void destroy_window()
{
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

void draw_rect(int topX, int topY, int w, int h)
{
    SDL_Rect r;
    r.x = topX;
    r.y = topY;
    r.w = w;
    r.h = h;

    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(pRenderer, &r);
    SDL_RenderPresent(pRenderer);
}

void blocking_delay()
{
    const Uint32 startMs = SDL_GetTicks();
    while (SDL_GetTicks() - startMs < 5000)
    {
        SDL_WaitEvent();
        SDL_PollEvent();
        SDL_PumpEvents();
        SDL_RenderSetLogicalSize(pRenderer, 640, 480);
        SDL_RenderClear(pRenderer);

        SDL_RenderPresent(pRenderer);
    }
}