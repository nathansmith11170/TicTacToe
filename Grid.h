#ifndef GRID
#define GRID

typedef enum {exes, zeros, tie, ongoing} state;
typedef enum {ex, zero, empty} tile;

typedef struct {
    tile board[3][3];
    state gameState;
    int playerMove;
} Grid;

//Checks the state of the game for a winner or a tie
state checkGrid(Grid *game);

//initializes the board to an empty game with ex to move
void initGrid(Grid *game);
#endif