#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

struct Tekst {
    char A[500];
    SDL_Surface *teksSurface;
    SDL_Rect Bounds;
    SDL_Color tekstColor;
};

bool tekstConstructor(struct Tekst *S, char A[], TTF_Font *f);
void tekstUpdate(struct Tekst *S, TTF_Font *f, int pos);

#endif