#include "graphic_lib.h"

SDL_Window *pWindow = NULL;
SDL_Renderer *pRenderer = NULL;
SDL_Surface *pSurface = NULL;
SDL_GLContext pContext;

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
    pContext = SDL_GL_CreateContext(pWindow);
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    pSurface = SDL_GetWindowSurface(pWindow);

    // Fill background
    Color background = Black;
    SDL_FillRect(pSurface, NULL, background);
    SDL_UpdateWindowSurface(pWindow);

    // SDL_RenderClear(pRenderer);
    // SDL_RenderPresent(pRenderer);
}

void destroy_window()
{
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

void draw_rect(Rect rectangle)
{
    SDL_Rect r;
    r.x = rectangle.topleft.x;
    r.y = rectangle.topleft.y;
    r.w = rectangle.w;
    r.h = rectangle.h;

    //   SDL_SetRenderDrawBMP(pRenderer, SurfaceBMP);
    SDL_FillRect(pSurface, &r, rectangle.fill);
    SDL_UpdateWindowSurface(pWindow);
}

void graphic_update()
{
    SDL_UpdateWindowSurface(pWindow);
}

SDL_Event graphic_get_event()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    return e;
}