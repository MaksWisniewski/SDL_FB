#include "text.h"
#include "bird.h"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

void tekstUpdate(Tekst *S, TTF_Font *f, int pos) {
    if(S->A != NULL) {
        SDL_FreeSurface(S->teksSurface);
        S->A = NULL;
    }
    S->teksSurface = TTF_RenderText_Blended_Wrapped(f, S->A, S->tekstColor, 640);
    if(S->teksSurface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        S->Bounds.w = S->teksSurface->w;
        S->Bounds.h = S->teksSurface->h;
    }

    S->Bounds.x = SCREEN_WIDTH / 2 - S->Bounds.w / 2;
    S->Bounds.y = pos;
}

bool tekstConstructor(Tekst *S, char A[50], TTF_Font *f) {
    strcpy(S->A, A);

    S->tekstColor.r = 255;
    S->tekstColor.g = 255;
    S->tekstColor.b = 255;
    S->tekstColor.a = 255;
    S->teksSurface = TTF_RenderText_Blended_Wrapped(f, S->A, S->tekstColor, 640)
    if(S->teksSurface == NULL) {
                printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
                return false;
    } else {
        S->Bounds.w = S->teksSurface->w;
        S->Bounds.h = S->teksSurface->h;
    }
    S->Bounds.x = 0;
    S->Bounds.y = 0;
}