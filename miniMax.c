#include "MiniMax.h"
#include "Grid.h"
#include <stdio.h>

int miniMax(Grid *game)
{
    state node = checkGrid(game);

    //If we have reached a game state with no possible moves
    if( node != ongoing)
    {
        if(node == exes)
        {
            return 1;
        }
        else if (node == zeros)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

    //Otherwise if ex is moving, we maximize
    if(game->playerMove == 0)
    {
        int value = -1;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(game->board[i][j] == empty){
                    Grid temp = *game;
                    temp.board[i][j] = ex;
                    int tempValue = miniMax(&temp);
                    if(tempValue > value)
                    {
                        value = tempValue;
                    }
                }
            }
        }
        return value;
    }

    //Zeros minimize
    else
    {
        int value = 1;
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(game->board[i][j] == empty)
                {
                    Grid temp = *game;
                    temp.board[i][j] = zero;
                    int tempValue = miniMax(&temp);
                    if(tempValue < value)
                    {
                        value = tempValue;
                    }
                }
            }
        }
        return value;
    }
}

void bestMove(Coord *move, Grid *game)
{
    int goingForATie = 1;
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(game->board[i][j] == empty){
                int moveScore;
                if(game->playerMove == 0)
                {
                    Grid temp = *game;
                    temp.board[i][j] = ex;
                    temp.playerMove = 1;
                    moveScore = miniMax(&temp);
                    printf("Score for move (%d,%d) is %d\n", i, j, moveScore);
                    if(goingForATie && moveScore == 1)
                    {
                        move->x = i;
                        move->y = j;
                        goingForATie = 0;
                    }
                    else if(moveScore == 0)
                    {
                        move->x = i;
                        move->y = j;
                    }
                }
                if(game->playerMove == 1)
                {
                    Grid temp = *game;
                    temp.board[i][j] = zero;
                    temp.playerMove = 0;
                    moveScore = miniMax(&temp);
                    printf("Score for move (%d,%d) is %d\n", i, j, moveScore);
                    if(goingForATie && moveScore == -1)
                    {
                        move->x = i;
                        move->y = j;
                        goingForATie = 0;
                    }
                    else if(moveScore == 0)
                    {
                        move->x = i;
                        move->y = j;
                    }
                }
            }
        }
    }
}