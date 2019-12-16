#include "Grid.h"

#ifndef MINIMAX
#define MINIMAX
typedef struct {
    int x, y;
} Coord;

/*
  This is a function that judges the optimal move given the state of the board
  in {game}. The coordinate of the optimal move is placed into {move}.
*/
int miniMax(Grid *game);

void bestMove(Coord *move, Grid *game);
#endif