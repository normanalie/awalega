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
    //SDL_UpdateWindowSurface(pWindow); 
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

void init_Images(Image *Images){
    Images->background.menu=loadImage("images/menu_bg.bmp");
    Images->background.game=loadImage("images/game_bg.bmp");
    Images->button.play=loadImage("images/play.bmp");
    Images->button.about=loadImage("images/about.bmp");
    Images->button.leaderboard=loadImage("images/leaderboard.bmp");
    Images->button.leave=loadImage("images/leave.bmp");
    Images->awale.one_seed=loadImage("images/one_seed.bmp");
    Images->awale.two_seed=loadImage("images/two_seeds.bmp");
    Images->awale.three_seed=loadImage("images/three_seeds.bmp");
    Images->awale.four_seed=loadImage("images/four_seeds.bmp");
    Images->awale.deck=loadImage("images/deck.bmp");
    Images->misc.playerVSia=loadImage("images/playerVSia.bmp");
    Images->misc.pvp=loadImage("images/pvp.bmp");
    Images->misc.sign=loadImage("images/sign.bmp");
    Images->misc.sign_leaderboard=loadImage("images/sign_leaderboard.bmp");
    Images->button.menu=loadImage("images/menu.bmp");
    Images->button.mute=loadImage("images/mute.bmp");
    Images->button.unmute=loadImage("images/unmute.bmp");
    Images->button.replay=loadImage("images/replay.bmp");
}





void init_Rectangle(Rectangle *Rectangles){
    //MENU
    Rectangles->bg.menu.topleft.x=0; Rectangles->bg.menu.topleft.y=0; Rectangles->bg.menu.w=1280; Rectangles->bg.menu.h=720;
    Rectangles->button.play.topleft.x=560; Rectangles->button.play.topleft.y=300; Rectangles->button.play.w=240; Rectangles->button.play.h=65;
    Rectangles->button.leaderboard.topleft.x=560; Rectangles->button.leaderboard.topleft.y=365; Rectangles->button.leaderboard.w=240; Rectangles->button.leaderboard.h=65;
    Rectangles->button.about.topleft.x=560; Rectangles->button.about.topleft.y=430; Rectangles->button.about.w=240; Rectangles->button.about.h=65;
    Rectangles->button.leave.topleft.x =1030; Rectangles->button.leave.topleft.y=645; Rectangles->button.leave.w=240; Rectangles->button.leave.h= 65;

    //AWALE
    Rectangles->bg.game.topleft.x=0; Rectangles->bg.game.topleft.y=0; Rectangles->bg.game.w=1280; Rectangles->bg.game.h=720;
    Rectangles->awale.deck.topleft.x=340; Rectangles->awale.deck.topleft.y=235; Rectangles->awale.deck.w=620; Rectangles->awale.deck.h=250; 

    //PSEUDO Player 1
    Rectangles->awale.p1.sign.topleft.x=500; Rectangles->awale.p1.sign.topleft.y=40; Rectangles->awale.p1.sign.w= 300; Rectangles->awale.p1.sign.h=90;

    //PSEUDO Player 2
    Rectangles->awale.p2.sign.topleft.x=500; Rectangles->awale.p2.sign.topleft.y=585; Rectangles->awale.p2.sign.w= 300; Rectangles->awale.p2.sign.h=90;

    //Seeds Player 1
    for(int i=0; i<HOLES_PER_PLAYER; i++){
        Rectangles->awale.p1.seeds[i].topleft.x=AWALE_1ST_SEED_POS_X + i*SEED_SEPARATION; 
        Rectangles->awale.p1.seeds[i].topleft.y=AWALE_P1_1ST_SEED_POS_Y; 
        Rectangles->awale.p1.seeds[i].w=SEED_WIDTH; 
        Rectangles->awale.p1.seeds[i].h=SEED_HEIGHT;
    }

    //Seeds Player 2
    for(int i=0; i<HOLES_PER_PLAYER; i++){
        Rectangles->awale.p2.seeds[i].topleft.x=AWALE_1ST_SEED_POS_X + i*SEED_SEPARATION; 
        Rectangles->awale.p2.seeds[i].topleft.y=AWALE_P2_1ST_SEED_POS_Y; 
        Rectangles->awale.p2.seeds[i].w=SEED_WIDTH; 
        Rectangles->awale.p2.seeds[i].h=SEED_HEIGHT;
    }

    //Sign Leaderboard
    Rectangles->misc.sign_leaderboard.topleft.x= 340; Rectangles->misc.sign_leaderboard.topleft.y= 110 ; Rectangles->misc.sign_leaderboard.w= 600; Rectangles->misc.sign_leaderboard.h= 495;
}

void destroy_Images(Image *Images){
    SDL_DestroyTexture(Images->background.menu);
    SDL_DestroyTexture(Images->background.game);
    SDL_DestroyTexture(Images->button.play);
    SDL_DestroyTexture(Images->button.about);
    SDL_DestroyTexture(Images->button.leaderboard);
    SDL_DestroyTexture(Images->button.leave);
    SDL_DestroyTexture(Images->awale.one_seed);
    SDL_DestroyTexture(Images->awale.two_seed);
    SDL_DestroyTexture(Images->awale.three_seed);
    SDL_DestroyTexture(Images->awale.four_seed);
    SDL_DestroyTexture(Images->awale.deck);
    SDL_DestroyTexture(Images->misc.playerVSia);
    SDL_DestroyTexture(Images->misc.pvp);
}

void present_image(SDL_Texture *image, Rect destination)
{
    SDL_Rect src = {0, 0, 0, 0};
    SDL_Rect dst = {destination.topleft.x, destination.topleft.y, destination.w, destination.h};
    SDL_QueryTexture(image, NULL, NULL, &src.w, &src.h);
    SDL_RenderCopy(pRenderer, image, &src, &dst);
    SDL_RenderPresent(pRenderer);
}

void draw_text(const char *text, Point topleft, int fontsize, Color textcolor)
{
    if (!fontsize)
    {

        fontsize = 12;
    }
    if (!textcolor)
    {
        textcolor = White;
    }
    TTF_Font *font = TTF_OpenFont("./fonts/PUSAB.ttf", fontsize);
    if (!font)
    {
        printf("[Graphic Lib] - Can't load font\n");
        printf("%s",  TTF_GetError());
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
    SDL_RenderPresent(pRenderer);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    return;
}