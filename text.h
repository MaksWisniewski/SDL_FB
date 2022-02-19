#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

struct Tekst {
    char A[50];
    SDL_Surface *teksSurface;
    SDL_Rect Bounds;
    SDL_Color tekstColor;
};

bool tekstConstructor(Tekst *S, char A[50], TTF_Font *f);
void tekstUpdate(Tekst *S, TTF_Font *f, int pos);

#endif
