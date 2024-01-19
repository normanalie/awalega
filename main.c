#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"

int main(void)
{
    graphic_init();
    create_window(640, 480, "Awaléga");
    draw_rect(20, 20, 100, 150);
    blocking_delay();
    destroy_window();
    return 0;
}