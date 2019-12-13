#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
int main()
{
    srand(time(0));

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
    Grid game;
    
    int quit = 0;
    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_MOUSEBUTTONUP:
                    //TODO Handle mouse click
                    break;
                case SDL_QUIT:
                    quit = 1;
                    break;

                default: {}
            }
        }

        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        //draw board
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        int w, h;
        SDL_GetWindowSize(win, &w, &h);
        SDL_Rect topDown1, topDown2, across1, across2;
        topDown1.x = w/3-w/50;
        topDown1.y = 0;
        topDown1.h = h;
        topDown1.w = w/50;
        topDown2.x = (w/3)*2-w/50;
        topDown2.y = 0;
        topDown2.h = h;
        topDown2.w = w/50;
        across1.x = 0;
        across1.y = h/3-h/50;
        across1.h = h/50;
        across1.w = w;
        across2.x = 0;
        across2.y = (h/3)*2-h/50;
        across2.h = h/50;
        across2.w = w;
        SDL_RenderFillRect(renderer, &topDown1);
        SDL_RenderFillRect(renderer, &topDown2);
        SDL_RenderFillRect(renderer, &across1);
        SDL_RenderFillRect(renderer, &across2);
        SDL_RenderPresent(renderer);

        //TODO check board
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}