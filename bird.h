#ifndef BIRD_H
#define BIRD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_touch.h>
#include <stdbool.h>
#include <stdio.h>

extern const int HEIGHT;
extern const int WIDTH;

double limit(double x, double limit);

typedef struct {
    float x, y;
} Vector;

typedef struct {
    SDL_Rect bounds;
    Vector position;
    SDL_Texture *img;
    bool isJump;
    float velocity;
    float gravity;
    float lift;
    float time_afterJump;
} Bird;

bool birdUpdate(Bird *x, double dt);
void birdJump(Bird *x);
void birdConstructor(Bird *x);

#endif