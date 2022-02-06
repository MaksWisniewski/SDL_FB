#ifndef ENGINE_H
#define ENGINE_H

#include "bird.h"
#include "pipe.h"
#include <math.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int noPipes = 6;

typedef enum game_state{
    START_GAME,
    PLAYING,
    LOST_GAME,
    QUIT_GAME
} GAME_STATE;

typedef struct {
    SDL_Texture *pipe_texture;
    SDL_Renderer *renderer;
    SDL_Window *window;
    GAME_STATE state;
    Bird bird;
    Pipe pipes[30];
    long long current_time;
    long long since_time;
    long long pipeGen_time;
    size_t pipe_index;
} Engine;

bool collisionDetection(Bird *b, Pipe *p);
bool loadMedia(Engine *e);
bool initGame(Engine *e);
void closeGame(Engine *e);
void input(Engine *e, SDL_Event *event);
void updateGame(Engine *e);
void renderFrame(Engine *e);
SDL_Texture* loadTexture(char *path, Engine *e);

#endif
