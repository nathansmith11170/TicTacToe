#ifndef GRID
#define GRID

typedef enum {exes, zeros, tie, ongoing} state;
typedef enum {ex, zero, empty} tile;

typedef struct {
    tile board[3][3];
    state gameState;
    int playerMove;
} Grid;

state checkGrid(Grid *game);
#endif