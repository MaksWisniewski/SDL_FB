#ifndef BIRD_H
#define BIRD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_touch.h>
#include <stdbool.h>
#include <stdio.h>

extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;

typedef struct {
    SDL_Texture *img;
    SDL_Rect Bounds;
    double self_x;
    double self_y;
    double velocity;
    double gravity;
    double lift;
    double time_sinceJump;
    bool isJump;
} Bird;

void birdConstructor(Bird *x);
bool birdUpdate(Bird *x, double dt);
void birdJump(Bird *x);

#endif