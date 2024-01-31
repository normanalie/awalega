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

    if (TTF_Init() < 0)
    {
        printf("Echec de l'initialisation de SDL/TTF\n");
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

    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
}

void destroy_window()
{
    SDL_DestroyRenderer(pRenderer);
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

    if (rectangle.outline)
    {
        ColorRGB c = hex_to_rgb(rectangle.outline);
        SDL_SetRenderDrawColor(pRenderer, c.r, c.g, c.b, 255);
        SDL_RenderDrawRect(pRenderer, &r);
    }

    if (rectangle.fill)
    {
        ColorRGB c = hex_to_rgb(rectangle.fill);
        SDL_SetRenderDrawColor(pRenderer, c.r, c.g, c.b, 255);
        SDL_RenderFillRect(pRenderer, &r);
    }

    if (rectangle.pImage)
    {
        present_image(rectangle.pImage, rectangle);
    }
    // SDL_UpdateWindowSurface(pWindow);
    SDL_RenderPresent(pRenderer);
}

void graphic_update()
{
    SDL_RenderPresent(pRenderer);
    // SDL_UpdateWindowSurface(pWindow);
}

SDL_Event graphic_get_event()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    return e;
}

SDL_Texture *loadImage(const char path[])
{
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if (NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(pRenderer, tmp);
    SDL_FreeSurface(tmp);
    if (NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}

void present_image(SDL_Texture *image, Rect destination)
{
    SDL_Rect src = {0, 0, 0, 0};
    SDL_Rect dst = {destination.topleft.x, destination.topleft.y, destination.w, destination.h};
    SDL_QueryTexture(image, NULL, NULL, &src.w, &src.h);
    SDL_RenderCopy(pRenderer, image, &src, &dst);
    // SDL_RenderPresent(pRenderer);
}

void draw_text(const char *text, Point topleft, int fontsize, Color textcolor)
{
    if (!fontsize)
        fontsize = 12;
    if (!textcolor)
        textcolor = White;

    TTF_Font *font = TTF_OpenFont("./fonts/PUSAB.ttf", fontsize);
    if (!font)
    {
        printf("[Graphic Lib] - Can't load font\n");
        printf("Error: %s\n", TTF_GetError());
        return;
    }

    ColorRGB c = hex_to_rgb(textcolor);
    SDL_Color color = {c.r, c.g, c.b, 255};

    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(font, text, color);

    SDL_Texture *Message = SDL_CreateTextureFromSurface(pRenderer, surfaceMessage);

    // Obtenir les dimensions du texte rendu
    int textWidth, textHeight;
    TTF_SizeText(font, text, &textWidth, &textHeight);

    // Ajuster le rectangle contenant le texte en fonction de ses dimensions
    SDL_Rect Message_rect;
    Message_rect.x = topleft.x;
    Message_rect.y = topleft.y;
    Message_rect.w = textWidth;
    Message_rect.h = textHeight;

    SDL_RenderCopy(pRenderer, Message, NULL, &Message_rect);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    return;
}