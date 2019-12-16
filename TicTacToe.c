#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"
#include "MiniMax.h"

#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 200

/*
  Draws an ex using the renderer
*/
void drawEx(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    // The coordinates of the corner point of the tile that was clicked
    int tile_x, tile_y;
    // The coordinates of the rectangles making the cross
    int rect1_x1, rect1_x2, rect2_x1, rect2_x2, rect1_y1, rect1_y2, rect2_y1,
        rect2_y2;

    //Dimensions of the tiles
    int tile_width = w / 3 - w / 100;
    int tile_height = h / 3 - h / 100;

    tile_x = x * (w / 3 + w / 100);
    tile_y = y * (h / 3 + h / 100);

    //Center of the tile
    int center_x = tile_width / 2 + tile_x;
    int center_y = tile_height / 2 + tile_y;

    rect1_x1 = center_x - tile_width / 3;
    rect1_y1 = center_y - tile_height / 3;
    rect1_x2 = center_x + tile_width / 3;
    rect1_y2 = center_y + tile_height / 3;

    rect2_x1 = center_x - tile_width / 3;
    rect2_y1 = center_y + tile_height / 3;
    rect2_x2 = center_x + tile_width / 3;
    rect2_y2 = center_y - tile_height / 3;

    thickLineRGBA(renderer, rect1_x1,
                            rect1_y1,
                            rect1_x2,
                            rect1_y2,
                            10,
                            255, 0, 0, 255);
                            
    thickLineRGBA(renderer, rect2_x1,
                            rect2_y1,
                            rect2_x2,
                            rect2_y2,
                            10,
                            255, 0, 0, 255);
}

/*
  Draws a zero using the renderer
*/
void drawZero(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    // The coordinates of the corner point of the tile that was clicked
    int tile_x = x * (w / 3 + w / 100);
    int tile_y = y * (h / 3 + w / 100);

    //Dimensions of the tiles
    int tile_width = w / 3 - w / 100;
    int tile_height = h / 3 - w / 100;

    //Center of the tile
    int center_x = tile_width / 2 + tile_x;
    int center_y = tile_height / 2 + tile_y;

    filledCircleRGBA(renderer, center_x, center_y, tile_width / 4 + 10, 0, 0, 255, 255);
    filledCircleRGBA(renderer, center_x, center_y, tile_width / 4, 0, 0, 0, 255);
}

/*
  Draws the grid
*/
void drawGrid(SDL_Renderer *renderer, int w, int h)
{
    SDL_Rect topDown1, topDown2, across1, across2;
    topDown1.x = w/3-w/100;
    topDown1.y = 0;
    topDown1.h = h;
    topDown1.w = w/50;
    topDown2.x = (w/3)*2-w/100;
    topDown2.y = 0;
    topDown2.h = h;
    topDown2.w = w/50;
    across1.x = 0;
    across1.y = h/3-h/100;
    across1.h = h/50;
    across1.w = w;
    across2.x = 0;
    across2.y = (h/3)*2-h/100;
    across2.h = h/50;
    across2.w = w;
    SDL_RenderFillRect(renderer, &topDown1);
    SDL_RenderFillRect(renderer, &topDown2);
    SDL_RenderFillRect(renderer, &across1);
    SDL_RenderFillRect(renderer, &across2);
}


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
    int w, h;
    Grid game;
    int quit = 0;
    initGrid(&game);
    while(!quit)
    {
        SDL_GetWindowSize(win, &w, &h);
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                int x, y;
                case SDL_MOUSEBUTTONUP:
                    if(e.button.x < w/3)
                    {
                        x = 0;
                    }
                    else if(e.button.x < (w/3)*2)
                    {
                        x = 1;
                    }
                    else
                    {
                        x = 2;
                    }
                    if(e.button.y < h/3)
                    {
                        y = 0;
                    }
                    else if(e.button.y < (h/3)*2)
                    {
                        y = 1;
                    }
                    else
                    {
                        y = 2;
                    }
                    if(game.board[x][y] == empty)
                    {
                        if(game.playerMove == 0)
                        {
                            game.board[x][y] = ex;
                            game.playerMove = 1;
                        }
                    }
                    if(game.gameState != ongoing)
                    {
                        initGrid(&game);
                    }
                    break;
                case SDL_QUIT:
                    quit = 1;
                    break;

                default: {}
            }
        }
        game.gameState = checkGrid(&game);
        //If it is the computer's move, then make a move
        if(game.playerMove == 1)
        {
            Coord move;
            bestMove(&move, &game);
            game.board[move.x][move.y] = zero;
            game.playerMove = 0;
            
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //draw board
        switch(game.gameState)
        {
            case 0:
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
                break;
            case 1:
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
                break;
            case 2:
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
                break;
            default:
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                break;
        }
        drawGrid(renderer, w, h);

        //Draw exes and zeros
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(game.board[i][j] == ex)
                {
                    drawEx(renderer, i, j, w, h);
                }
                if(game.board[i][j] == zero)
                {
                    drawZero(renderer, i, j, w, h);
                }
            }
        }
        SDL_RenderPresent(renderer);
        game.gameState = checkGrid(&game);
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}