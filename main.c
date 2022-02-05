#include "engine.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern const int SCREEN_WIDTH = 1280;
extern const int SCREEN_HEIGHT = 720;
extern const int noPipes = 6;

int main(int argc, char **argv) {
    srand(time(NULL));
}