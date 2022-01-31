#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{
    // Declare a pointer
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER); // Initialize SDL2, graphics and timer system

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Flappy_bird",          // window title
        SDL_WINDOWPOS_CENTERED, // initial x position
        SDL_WINDOWPOS_CENTERED, // initial y position
        1280,                   // width, in pixels
        720,                    // height, in pixels
        SDL_WINDOW_OPENGL       // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer, which sets up the graphics and hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, render_flags);
    if (rend == NULL)
    {
        printf("error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    /// Load the img into memory using SDL_image library function
    SDL_Surface *surface = IMG_Load("img/background.png");
    if (surface == NULL)
    {
        printf("error creating surface %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load the image into the hardware's memory
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (tex == NULL)
    {
        printf("error creating texuture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000); // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}