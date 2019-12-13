#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
int main()
{
    srand(1241234);

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* win = SDL_CreateWindow("Water", 
                      SDL_WINDOWPOS_CENTERED, 
                      SDL_WINDOWPOS_CENTERED, 
                      WINDOW_WIDTH, 
                      WINDOW_HEIGHT, 
                      0);

    if (win == NULL) {
        printf("error creating window: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_SetWindowResizable(win, SDL_TRUE);

    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1,
                             SDL_RENDERER_ACCELERATED | 
                             SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL) {
        printf("error creating renderer: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Event e;
    int quit = 0;
    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    quit = 1;
                    break;

                default: {}
            }
        }

        SDL_SetRenderDrawColor(renderer, 70, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}