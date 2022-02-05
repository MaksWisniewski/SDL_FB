#include "text.h"
#include "bird.h"
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

const int MAX_TEXT_L = 200;

void textUpdate(Text *t, TTF_Font *font, int posY) {
    if(t->Surface != NULL) {
        SDL_FreeSurface(t->Surface);
        t->tab = NULL;
    }

    t->Surface = TTF_RenderText(font, t->tab, t->Color, 640);

    if(t->Surface == NULL)
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    else {
        t->Bounds.w = t->Surface->w;
        t->Bounds.h = t->Surface->h;
    }

    t->Bounds.x = WIDTH / 2 - t->Bounds.w / 2;
    t->Bounds.y = posY;
}

bool textConstructor(Text* t, char tab[200], TTF_Font* f){
    strcpy(t->tab, tab);
    t->Color.r = 255;
    t->Color.g = 255;
    t->Color.b = 255;
    t->Color.a = 255;
    t->Surface = TTF_RenderText_Blended_Wrapped(f, t->tab, t->Color, 640);
    if (t->Surface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }else{
        t->Bounds.w = t->Surface->w;
        t->Bounds.h = t->Surface->h;
    }
    
    t->Bounds.x = 0;
    t->Bounds.y = 0;
    return true;
}