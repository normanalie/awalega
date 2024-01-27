#ifndef GRAPHICLIBH
#define GRAPHICLIBH

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <string.h>

#include "shapes.h"

int graphic_init();
void create_window(int W, int H, const char *name);
void destroy_window();
void draw_rect(Rect rectangle);
void graphic_update();
SDL_Event graphic_get_event();
//  void draw_rect_by_center(int cx, int cy, int w, int h);

// is_mouse_in()
// draw_img()
#endif