#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"

int main(void)
{
    graphic_init();
    create_window(480, 600, "Awaléga");

    blocking_delay(5000);
    SDL_Delay(5000);

    destroy_window();

    return 0;
}