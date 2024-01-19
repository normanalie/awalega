#ifndef GRAPHICLIBH
#define GRAPHICLIBH

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>

int graphic_init();
void create_window(int W, int H, const char *name);
void destroy_window();
void draw_rect(int topX, int topY, int w, int h);
//  void draw_rect_by_center(int cx, int cy, int w, int h);

// is_mouse_in()
// draw_img()

void blocking_delay();
#endif