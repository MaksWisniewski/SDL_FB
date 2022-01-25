#ifndef GAME_WINDOW
#define GAME_WINDOW
///tu powinny byc wszystkie inkludy kropka ha
#include<SDL2/SDL.h>
#include<SDL2/image.h>
#include<stdbool.h>

const int SCREEN_HEIGHT;
const int SCREEN_WIDTH;
const int NUMBERof_PIPES;

typedef enum game_state{
    start,
    playing,
    end_game,
    quit
} GAME_STATE;

typedef struct {
    SDL_Window* my_window;
    GAME_STATE my_state;

} Engine;

bool loadMedia(Engine* X);
bool initGame(Engine* X);

///zamykanie
void closeGame(Engine* X);
void handeInput(Engine* X, SDL_Event* event);
void updateGame(Engine* X);
void renderFrame(Engine* X);

SDL_Texture* loadTexture(char* path, Engine* X);

#endif