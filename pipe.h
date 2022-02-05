#ifndef PIPE_H
#define PIPE_H

#include "bird.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;

typedef struct {
    int topHeight;
    int botHeight;
    int free;
    int self_width;
    int self_height;
    double self_x;
    double velocity;
    SDL_Rect topBounds;
    SDL_Rect botBounds;
    bool isActive;
} Pipe;

void pipeConstructor(Pipe *p);
void pipeUpdate(Pipe *p, double dt);

#endif