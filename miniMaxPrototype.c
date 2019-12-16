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
    Coord move1;
    bestMove(&move1, &test01);
    if(move1.x == 2 && move1.y == 2) {
        printf("Test 01 success.\n");
    } else {
        printf("Test 01 failed, result: (%d,%d), expected: (2,2)\n", move1.x, move1.y);
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
    Coord move2;
    bestMove(&move2, &test02);
    if(move2.x == 2 && move2.y == 2) {
        printf("Test 02 success.\n");
    } else {
        printf("Test 02 failed, result: (%d,%d), expected: (2,2)\n", move2.x, move2.y);
        testHasFailed = 1;
    }

    printf("Test 03 has X to move and win in 2.\n");
    Grid test03 = {
        .board = {
            {ex,    empty, empty},
            {zero,  ex,    empty},
            {empty, empty, zero}
        },
        .playerMove = 0,
        .gameState = ongoing
    };
    Coord move3;
    bestMove(&move3, &test03);
    if(move3.x == 0 && move3.y == 2) {
        printf("Test 03 success.\n");
    } else {
        printf("Test 03 failed, result: (%d,%d), expected: (0,1)\n", move3.x, move3.y);
        testHasFailed = 1;
    }

    printf("Test 04 has O to move and win in 2.\n");
    Grid test04 = {
        .board = {
            {empty, zero,  ex},
            {empty, empty, ex},
            {ex,    empty, zero}
        },
        .playerMove = 1,
        .gameState = ongoing
    };
    Coord move4;
    bestMove(&move4, &test04);
    if(move4.x == 1 && move4.y == 1) {
        printf("Test 03 success.\n");
    } else {
        printf("Test 03 failed, result: (%d,%d), expected: (0,1)\n", move4.x, move4.y);
        testHasFailed = 1;
    }

    printf("Test 05 has O to move after X in the center.\n");
    Grid test05 = {
        .board = {
            {empty, empty, empty},
            {empty, ex,    empty},
            {empty, empty, empty}
        },
        .playerMove = 1,
        .gameState = ongoing
    };
    Coord move5;
    bestMove(&move5, &test05);
    if(move5.x == 2 && move5.y == 2) {
        printf("Test 05 success.\n");
    } else {
        printf("Test 05 failed, result: (%d,%d), expected: (2,2)\n", move5.x, move5.y);
        testHasFailed = 1;
    }

    printf("Test 06 has O to move after X in the corner.\n");
    Grid test06 = {
        .board = {
            {empty, empty, ex},
            {empty, empty, empty},
            {empty, empty, empty}
        },
        .playerMove = 1,
        .gameState = ongoing
    };
    Coord move6;
    bestMove(&move6, &test06);
    if(move6.x == 1 && move6.y == 1) {
        printf("Test 06 success.\n");
    } else {
        printf("Test 06 failed, result: (%d,%d), expected: (1,1)\n", move6.x, move6.y);
        testHasFailed = 1;
    }

    printf("Test 07 has O to move and X on a side.\n");
    Grid test07 = {
        .board = {
            {empty, empty, empty},
            {empty, empty, ex},
            {empty, empty, empty}
        },
        .playerMove = 1,
        .gameState = ongoing
    };
    Coord move7;
    bestMove(&move7, &test07);
    if(move7.x == 2 && move7.y == 2) {
        printf("Test 07 success.\n");
    } else {
        printf("Test 07 failed, result: (%d,%d), expected: (2,2)\n", move7.x, move7.y);
        testHasFailed = 1;
    }
    
    printf("Test 08 has X to move on an empty board.\n");
    Grid test08 = {
        .board = {
            {empty, empty, empty},
            {empty, empty, empty},
            {empty, empty, empty}
        },
        .playerMove = 0,
        .gameState = ongoing
    };
    Coord move8;
    bestMove(&move8, &test08);
    if(move8.x == 2 && move8.y == 2) {
        printf("Test 08 success.\n");
    } else {
        printf("Test 08 failed, result: (%d,%d), expected: (2,2)\n", move8.x, move8.y);
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