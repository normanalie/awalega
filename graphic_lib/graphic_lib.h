#ifndef GRAPHICLIBH
#define GRAPHICLIBH

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "images.h"
#include "shapes.h"

int graphic_init();
void create_window(int W, int H, const char *name);
void destroy_window();
void draw_rect(Rect rectangle);
void graphic_update();
SDL_Event graphic_get_event();
SDL_Texture *loadImage(const char path[]);
void present_image(SDL_Texture *image, Rect destination);
void draw_text(const char *text, Point topleft, int fontsize, Color textcolor);

#endif