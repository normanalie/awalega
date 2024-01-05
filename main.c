#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"

int main(void)
{
    graphic_init();
    create_window(640, 480, "Awaléga");
    char c;
    scanf("%c", &c);
    destroy_window();
    return 0;
}