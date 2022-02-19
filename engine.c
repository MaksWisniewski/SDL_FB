#include "engine.h"
#include "bird.h"
#include "pipe.h"
#include "text.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <SDL_mixer.h>
#include <stdbool.h>

// returns true if there is intersection
bool collisionDetection(Bird *b, Pipe *p) {
    SDL_Rect *prostokat = malloc(sizeof(SDL_Rect));
    return SDL_IntersectRect(&p->topBounds, &b->Bounds, prostokat) || SDL_IntersectRect(&p->botBounds, &b->Bounds, prostokat);
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
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO); 
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    e->sound = Mix_LoadMUS("sounds/sound.mp3");
    e->musicEffect = Mix_LoadWAV("sounds/death_sound.ogg");
    e->window = SDL_CreateWindow("Flappy bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
   
    Mix_PlayMusic(e->sound, -1);

    if(e->window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    
    e->renderer = SDL_CreateRenderer(e->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(e->renderer == NULL) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            return false;
    }
    if(TTF_Init() == -1) {
        printf("TTF_SDL could not initialize: TTF_Error: %s\n", TTF_GetError());
        return false;
    }


    e->since_time = 0;
    e->current_time = 0;
    e->pipe_index = 0;
    e->pipeGen_time = 0;
    e->state = START_GAME;

    birdConstructor(&e->bird);

    e->mFont = TTF_OpenFont("img/Bullpen3D.ttf", 24);
    if(e->mFont == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());    
        return false;
    }

    SDL_SetRenderDrawColor(e->renderer, 0x00, 0x00, 0x00, 0x00);
    
    struct Tekst *pismo;
    tekstConstructor(pismo, "nacisnij enter aby rozpaczac", e->mFont);
    tekstUpdate(pismo, e->mFont, SCREEN_WIDTH/2);
    SDL_Delay(100);

    for(int i = 0; i < noPipes; i++) {
        pipeConstructor(&e->pipes[i]);
    }
    return true;
}

bool loadMedia(Engine *e) {
    e->bird.img = loadTexture("img/bird.png", e);
    if(e->bird.img == NULL) 
        return false;
    e->pipe_texture = loadTexture("img/pipe.png", e);
    if(e->pipe_texture == NULL) 
        return false;
    e->background_pic = loadTexture("img/background.png", e);
    if(e->background_pic == NULL)
        return false;
    return true;
}

void input(Engine *e, SDL_Event *event) {
    while(SDL_PollEvent(event) != 0) {
    
        if(event->type == SDL_QUIT) {
            e->state = QUIT_GAME;
        } else if(event->type == SDL_KEYDOWN) {
            switch(event->key.keysym.sym) {
                case SDLK_SPACE:
                    birdJump(&e->bird);
                    break;
                case SDLK_ESCAPE:
                    if(e->state == LOST_GAME)
                        e->state = QUIT_GAME;
                    break;
                case SDLK_RETURN:
                    if(e->state == START_GAME)
                        e->state = PLAYING;
                    if(e->state == LOST_GAME) {
                        resetGame(e);
                        e->state = PLAYING;
                    }
                    break;
            }
        }

        else if(event->type == SDL_KEYUP) 
            switch (event->key.keysym.sym) {
                case SDLK_SPACE:
                    e->bird.isJump = false;
                    break;
            }    
    }
}

void updateGame(Engine *e) {
    // calculate delta time
    e->since_time = e->current_time;
    e->current_time = SDL_GetPerformanceCounter();

    double dt = ((e->current_time - e->since_time) * 1000 / (double) SDL_GetPerformanceFrequency()) / 1000;
    int total_time = SDL_GetTicks();

    if(e->state == PLAYING) {

        if(e->pipe_index < noPipes && total_time > e->pipeGen_time + 2200) {
        
            if(e->pipes[e->pipe_index].isActive == false) {
                e->pipes[e->pipe_index].isActive = true;
                e->pipe_index++;
                e->pipeGen_time = total_time;
            }
            e->pipe_index %= noPipes;
        }
        
        if(birdUpdate(&e->bird, dt)) {
            Mix_PlayChannel(-1, e->musicEffect, 0);    
            e->state = LOST_GAME;
        }

        for(int i = 0; i < noPipes; i++) {
            pipeUpdate(&e->pipes[i], dt);
            
            if(collisionDetection(&e->bird, &e->pipes[i])) {
                e->state = LOST_GAME;
                Mix_PlayChannel(-1, e->musicEffect, 0);    
            }
            
        }   
    }
}

void renderFrame(Engine *e) {
    SDL_RenderClear(e->renderer);
    SDL_RenderCopy(e->renderer, e->background_pic, NULL, NULL);

    if(e->state == PLAYING || e->state == LOST_GAME) {
        for(int i = 0; i < noPipes; i++) {
            if(e->pipes[i].isActive == true) {
                SDL_RenderCopyEx(e->renderer, e->pipe_texture, NULL, &e->pipes[i].topBounds, 0, NULL, SDL_FLIP_NONE);
                SDL_RenderCopyEx(e->renderer, e->pipe_texture, NULL, &e->pipes[i].botBounds, 0, NULL, SDL_FLIP_VERTICAL);
            }
        }

        SDL_RenderCopy(e->renderer, e->bird.img, NULL, &e->bird.Bounds);
    }
    SDL_RenderPresent(e->renderer);
}

void closeGame(Engine *e) {
    SDL_DestroyTexture(e->bird.img);
    e->bird.img = NULL;
    SDL_DestroyTexture(e->pipe_texture);
    e->pipe_texture = NULL;
    SDL_DestroyTexture(e->background_pic);
    e->pipe_texture = NULL;
    SDL_DestroyRenderer(e->renderer);
    e->renderer = NULL;
    SDL_DestroyWindow(e->window);

    Mix_FreeChunk(e->musicEffect);
    Mix_FreeMusic(e->sound);
    IMG_Quit();
    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();
}

void resetGame(Engine *e) {
    birdConstructor(&e->bird);
    e->since_time = 0;
    e->current_time = SDL_GetPerformanceCounter();
    e->pipe_index = 0;
    e->pipeGen_time = 0;
    for(int i = 0; i < noPipes; i++) {
        pipeConstructor(&e->pipes[i]);
    }
}
