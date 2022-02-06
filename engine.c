#include "engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_rect.h>
#include <stdbool.h>

// returns true if there is intersection
bool collisionDetection(Bird *b, Pipe *p) {
    return SDL_IntersectRect(p->topBounds, b->Bounds, NULL) || SDL_IntersectRect(p->botBounds, b->Bounds, NULL);
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