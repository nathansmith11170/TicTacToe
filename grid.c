#include "Grid.h"
/*
  Check to see if the game is over, and return the resulting state.
*/
state checkGrid(Grid *game)
{
    for(int i = 0; i < 3; i++)
    {
        if(game->board[i][0] == game->board[i][1]) {
            if(game->board[i][1] == game->board[i][2]) {
                if (game->board[i][0] == zero) {
                    return zeros;
                } else if (game->board[i][0] == exes) {
                    return exes;
                }
            }
        }
    }

    for(int j = 0; j < 3; j++)
    {
        if(game->board[0][j] == game->board[1][j]) {
            if(game->board[1][j] == game->board[2][j]) {
                if(game->board[0][j]==zero) {
                    return zeros;
                } else if (game->board[0][j] == exes) {
                    return exes;
                }
            }
        }
    }

    if(game->board[0][0] == game->board[1][1]) {
        if(game->board[1][1] == game->board[2][2]) {
            if(game->board[0][0]==zero) {
                return zeros;
            } else if (game->board[0][0] == exes) {
                return exes;
            }
        }
    }

    if(game->board[0][2] == game->board[1][1]) {
        if(game->board[1][1] == game->board[2][0]) {
            if(game->board[0][2]==zero) {
                return zeros;
            } else if (game->board[0][2] == exes){
                return exes;
            }
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(game->board[i][j] == empty) {
                return ongoing;
            }
        }
    }
    
    return tie;
}