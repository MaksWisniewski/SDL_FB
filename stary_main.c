#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char *argv[]) {
  // Declare a pointer
  SDL_Window *window;

  SDL_Init(SDL_INIT_VIDEO |
           SDL_INIT_TIMER); // Initialize SDL2, graphics and timer system



  // structure containg metadata bout background
  SDL_Rect background_rect;
  background_rect.x = 0;
  background_rect.y = 0;
  background_rect.w = WIDTH;
  background_rect.h = HEIGHT;

  // structure containg metadata bout ground
  SDL_Rect ground_rect;
  ground_rect.x = 0;
  ground_rect.y = HEIGHT-40;
  ground_rect.w = WIDTH;
  ground_rect.h = 40;

  SDL_Rect bird_rect;
  bird_rect.x = WIDTH/2 - 40;
  bird_rect.y = HEIGHT/2;
  bird_rect.w = 40;
  bird_rect.h = 40;

  // Create an application window with the following settings:
  window = SDL_CreateWindow("Flappy_bird",          // window title
                            SDL_WINDOWPOS_CENTERED, // initial x position
                            SDL_WINDOWPOS_CENTERED, // initial y position
                            WIDTH,                  // width, in pixels
                            HEIGHT,                 // height, in pixels
                            SDL_WINDOW_OPENGL       // flags - see below
  );

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  // Create a renderer, which sets up the graphics and hardware
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  SDL_Renderer *rend = SDL_CreateRenderer(window, -1, render_flags);
  if (rend == NULL) {
    printf("error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  /// Load the img into memory using SDL_image library function
  SDL_Surface *surface_background = IMG_Load("img/background.png");
  if (surface_background == NULL) {
    printf("error creating surface %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_Surface *surface_ground = IMG_Load("img/ground.png");
  if (surface_ground == NULL) {
    printf("error creating surface %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_Surface *surface_bird = IMG_Load("img/bird.png");
  if (surface_ground == NULL) {
    printf("error creating surface %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }


  // Load the image into the hardware's memory
  SDL_Texture *tex_background = SDL_CreateTextureFromSurface(rend, surface_background);
  SDL_FreeSurface(surface_background);
  if (tex_background == NULL) {
    printf("error creating texuture %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex_ground = SDL_CreateTextureFromSurface(rend, surface_ground);
  SDL_FreeSurface(surface_ground);
  if (tex_ground == NULL) {
    printf("error creating texuture %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex_bird = SDL_CreateTextureFromSurface(rend, surface_bird);
  SDL_FreeSurface(surface_bird);
  if (tex_bird == NULL) {
    printf("error creating texuture %s\n", SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Clear the windows
  SDL_RenderClear(rend);

  // Draw the image to the window
  SDL_RenderCopy(rend, tex_background, NULL, &background_rect);
  SDL_RenderCopy(rend, tex_ground, NULL, &ground_rect);
  SDL_RenderCopy(rend, tex_bird, NULL, &bird_rect);
  // Double buffering
  SDL_RenderPresent(rend);
  // The window is open: could enter program loop here (see SDL_PollEvent())

  SDL_Delay(2000); // Pause execution for 3000 milliseconds, for example

  // clean up resources before exitng
  SDL_DestroyTexture(tex_background);
  SDL_DestroyTexture(tex_ground);
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(window);

  // Clean up
  SDL_Quit();
  return 0;
}