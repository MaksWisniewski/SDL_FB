#include "engine.h"
#include "bird.h"
#include "pipe.h"

// returns true if there is intersection
bool collisionDetection(Bird *b, Pipe *p) {
    return SDL_IntersectRect(&p->topBounds, &b->Bounds, NULL) || SDL_IntersectRect(&p->botBounds, &b->Bounds, NULL);
}

SDL_Texture* loadTexture(char* path, Engine* e) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(path);

    if(surface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path,
            IMG_GetError());
    } else {
        texture = SDL_CreateTextureFromSurface(e->renderer, surface);
        if (texture == NULL) {
            printf("Unable to create texture from surface: %s! SDL_image Error: %s\n", path, IMG_GetError());
        }
        SDL_FreeSurface(surface);  
    }
    return texture;
}

bool initGame(Engine *e) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER); 
    e->window = SDL_CreateWindow("Flappy bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    
    if(e->window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    
    e->renderer = SDL_CreateRenderer(e->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(e->renderer == NULL) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            return false;
    }
    
    SDL_SetRenderDrawColor(e->renderer, 0x00, 0x00, 0x00, 0x00);
    e->since_time = 0;
    e->current_time = 0;
    e->pipe_index;
    e->pipeGen_time = 0;
    e->state = START_GAME;

    birdConstructor(&e->bird);

    for(int i = 0; i < noPipes; i++) {
        pipeConstructor(&e->pipes[i]);
    }
    return true;
}