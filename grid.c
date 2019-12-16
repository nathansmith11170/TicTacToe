#include "Grid.h"
/*
  Check to see if the game is over, and return the resulting state.
*/
state checkGrid(Grid *game)
{
    /*
      Check rows.
    */
    for(int i = 0; i < 3; i++)
    {
        if(game->board[i][0] == game->board[i][1]) {
            if(game->board[i][1] == game->board[i][2]) {
                if (game->board[i][0] != empty) {
                    return game->board[i][0];
                }
            }
        }
    }

    /*
      Check columns.
    */
    for(int j = 0; j < 3; j++)
    {
        if(game->board[0][j] == game->board[1][j]) {
            if(game->board[1][j] == game->board[2][j]) {
                if(game->board[0][j] != empty) {
                    return game->board[0][j];
                }
            }
        }
    }

    /*
      Check diagonal from top right to bottom right
    */
    if(game->board[0][0] == game->board[1][1]) {
        if(game->board[1][1] == game->board[2][2]) {
            if(game->board[0][0] != empty) {
                return game->board[0][0];
            }
        }
    }

    /*
      Check diagonal from top left to bottom left
    */
    if(game->board[0][2] == game->board[1][1]) {
        if(game->board[1][1] == game->board[2][0]) {
            if(game->board[2][0] != empty) {
                return game->board[2][0];
            }
        }
    }

    /*
      Check if there are empty tiles
    */
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(game->board[i][j] == empty) {
                return ongoing;
            }
        }
    }
    
    /*
      If there is no winner and no empty tiles then the game is a tie.
    */
    return tie;
}

void initGrid(Grid *game)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            game->board[i][j] = empty;
        }
    }
    game->gameState = ongoing;
    game->playerMove = 0;
}