#ifndef GRAPHICLIBH
#define GRAPHICLIBH

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>

int graphic_init();
void create_window(int W, int H, const char *name);
void destroy_window();

// is_mouse_in()
// draw_img()

#endif