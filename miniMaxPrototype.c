#include "MiniMax.h"
#include "Grid.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int testHasFailed = 0;

    printf("Test 01 has X to make the winning move.\n");
    Grid test01 = {
        .board = {
            {ex, zero, zero},
            {zero, ex, zero},
            {zero, zero, empty}
        },
        .playerMove = 0,
        .gameState = ongoing
    };
    Coord move;
    bestMove(&move, &test01);
    if(move.x == 2 && move.y == 2) {
        printf("Test 01 success.\n");
    } else {
        printf("Test 01 failed, result: (%d,%d), expected: (2,2)\n", move.x, move.y);
        testHasFailed = 1;
    }

    printf("Test 02 has O to make the winning move.\n");
    Grid test02 = {
        .board = {
            {zero, ex, empty},
            {ex, zero, ex},
            {ex, ex, empty}
        },
        .playerMove = 1,
        .gameState = ongoing
    };
    bestMove(&move, &test02);
    if(move.x == 2 && move.y == 2) {
        printf("Test 02 success.\n");
    } else {
        printf("Test 02 failed, result: (%d,%d), expected: (2,2)\n", move.x, move.y);
        testHasFailed = 1;
    }
    

    if(testHasFailed) {
        printf("Tests have failed.\n");
        return EXIT_FAILURE;
    } else {
        printf("All test cases passed.\n");
        return EXIT_SUCCESS;
    }
}