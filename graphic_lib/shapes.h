#ifndef SHAPESH
#define SHAPESH

#include <SDL2/SDL.h>

#include "colors.h"

typedef struct point
{
    int x;
    int y;
} Point;

typedef struct vector
{
    Point start;
    Point end;
} Vect;

typedef struct rectangle
{
    Point topleft;
    int w;
    int h;
    Color outline;
    Color fill;
    SDL_Texture *pImage;
} Rect;

typedef struct circle
{
    Point center;
    int r;
    // Sprite sprite;
    Color outline;
    Color fill;
} Circle;

Rect rect_by_center(Point center, int w, int h, Color color);
Point center_of_rect(Rect rectangle);
Bool is_in(Point point, Rect rectangle);

#endif