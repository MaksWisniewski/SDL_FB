
#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

extern const int HEIGHT;
extern const int WIDTH;
extern const int MAX_TEXT_L;

typedef struct {
    char Text[200];
    SDL_Surface* Surface;
    SDL_Rect Bounds;
    SDL_Color Color;
} Text;

void textSet(Text* t);
bool textConstructor(Text* t, char txt[200], TTF_Font* font);
void textUpdate(Text* t, TTF_Font* font, int posY);

#endif