#include "engine.h"

#include <math.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int noPipes = 6;

int main(int argc, char **argv) {
    srand(time(NULL));

    Engine silnikGry;
    if(!initGame(&silnikGry)) {
        printf("failed to init!\n");
    }
    else {
        if(!loadMedia(&silnikGry))
            printf("failed to init!\n");
        else {
            SDL_Event imprezka; /// :D

            while(silnikGry.state != QUIT_GAME) {
                input(&silnikGry, &imprezka);

                updateGame(&silnikGry);

                renderFrame(&silnikGry);
            }
        }
    }
    closeGame(&silnikGry);
}
