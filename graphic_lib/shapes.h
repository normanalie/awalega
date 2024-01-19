#ifndef SHAPESH
#define SHAPESH

typedef struct point {
    int x;
    int y;
} Point;

typedef struct vector {
    Point start;
    Point end;
} Vect;

typedef struct rectangle {
    Point topleft;
    int w;
    int h;
} Rect;

typedef struct circle {
    Point center;
    int r;
} Circle;


Rect rect_by_center(Point center, int w, int h);
Point center_of_rect(Rect rectangle);

#endif