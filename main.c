#include <stdio.h>
#include <stdlib.h>

#include "graphic_lib/graphic_lib.h"

int main(void)
{
    graphic_init();
    create_window(480, 600, "Awaléga");
    Point center = {10, 10};
    Rect r = rect_by_center(center, 10, 20, Lavender);

    draw_rect(r);

    // Initi the variable to store typed text
    int maxTextLen = 254;
    char *text = (char *)malloc(maxTextLen * sizeof(char));
    memset(text, 0, maxTextLen);
    // Set text origin position in the window
    Point textpos = {100, 100};

    /*
    GAME LOOP
    */
    char quit = 0;
    SDL_Event event;
    SDL_StartTextInput(); // Listen for text input envents
    while (!quit)
    {
        event = graphic_get_event(); // Get the latest event
        switch (event.type)
        {
        case SDL_QUIT:
            quit = 1;
            break;
        case SDL_TEXTINPUT:
            // Add typed text at the end of the variable
            strncat(text, event.text.text, maxTextLen - strlen(text) - 1);
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_RETURN) // If enter is pressed
            {
                printf("Entrée\n");
            }
        }

        draw_text(text, textpos, 24, Gold); // Draw text variable on the screen
        graphic_update();
    }
    SDL_StopTextInput(); // Stop listenning for text input events

    destroy_window();

    return 0;
}