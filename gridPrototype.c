#include <stdlib.h>
#include <stdio.h>
#include "Grid.h"

int main()
{
    int testHasFailed = 0;

    /*
      Test for an empty grid, should get ongoing as a result.
    */
   printf("Test 01 is an empty grid.\n");
    Grid test01;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            test01.board[i][j] = empty;
            printf("%d ", test01.board[i][j]);
        }
        printf("\n");
    }
    state result = checkGrid(&test01);
    if(result == ongoing) {
        printf("Test 01 success.\n");
    } else {
        printf("Test 01 failed, result: %d, expected: 3\n", result);
        testHasFailed = 1;
    }

    /*
      Test for exes in a row
    */
    printf("Test 02 is a row of exes.\n");
    Grid test02;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == 0) {
                test02.board[i][j] = ex;
            } else {
                test02.board[i][j] = empty;
            }
            printf("%d ", test02.board[i][j]);
        }
        printf("\n");
    }
    result = checkGrid(&test02);
    if(result == exes) {
        printf("Test 02 success.\n");
    } else {
        printf("Test 02 failed, result: %d, expected: 0\n", result);
        testHasFailed = 1;
    }

    /*
      Test for zeroes in a row
    */
    printf("Test 03 is a row of zeroes.\n");
    Grid test03;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == 1) {
                test03.board[i][j] = zero;
            } else {
                test03.board[i][j] = empty;
            }
            printf("%d ", test03.board[i][j]);
        }
        printf("\n");
    }
    result = checkGrid(&test03);
    if(result == zeros) {
        printf("Test 03 success.\n");
    } else {
        printf("Test 03 failed, result: %d, expected: 1\n", result);
        testHasFailed = 1;
    }

    /*
      Test for exes in a column
    */
    printf("Test 04 is a column of exes.\n");
    Grid test04;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 1) {
                test04.board[i][j] = ex;
            } else {
                test04.board[i][j] = empty;
            }
            printf("%d ", test04.board[i][j]);
        }
        printf("\n");
    }
    result = checkGrid(&test04);
    if(result == exes) {
        printf("Test 04 success.\n");
    } else {
        printf("Test 04 failed, result: %d, expected: 0\n", result);
        testHasFailed = 1;
    }

    /*
      Test for zeros in a column
    */
    printf("Test 05 is a column of zeros.\n");
    Grid test05;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 2) {
                test05.board[i][j] = zero;
            } else {
                test05.board[i][j] = empty;
            }
            printf("%d ", test05.board[i][j]);
        }
        printf("\n");
    }
    result = checkGrid(&test05);
    if(result == zeros) {
        printf("Test 05 success.\n");
    } else {
        printf("Test 05 failed, result: %d, expected: 1\n", result);
        testHasFailed = 1;
    }

    /*
      Test for exes in a diagonal
    */
    printf("Test 06 is a diagonal of exes.\n");
    Grid test06;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == i) {
                test06.board[i][j] = ex;
            } else {
                test06.board[i][j] = empty;
            }
            printf("%d ", test06.board[i][j]);
        }
        printf("\n");
    }
    result = checkGrid(&test06);
    if(result == exes) {
        printf("Test 06 success.\n");
    } else {
        printf("Test 06 failed, result: %d, expected: 0\n", result);
        testHasFailed = 1;
    }

    /*
      Test for zeros in a diagonal
    */
    printf("Test 07 is a diagonal of zeros.\n");
    Grid test07;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 0 && i == 2 || j == 1 && i == 1 || j == 2 && i == 0) {
                test07.board[i][j] = zero;
            } else {
                test07.board[i][j] = empty;
            }
            printf("%d ", test07.board[i][j]);
        }
        printf("\n");
    }
    result = checkGrid(&test07);
    if(result == zeros) {
        printf("Test 07 success.\n");
    } else {
        printf("Test 07 failed, result: %d, expected: 1\n", result);
        testHasFailed = 1;
    }

    /*
      Test for tie
    */
    printf("Test 08 is a tie.\n");
    Grid test08;
    test08.board[0][0] = ex;
    test08.board[1][1] = zero;
    test08.board[0][1] = ex;
    test08.board[0][2] = zero;
    test08.board[2][0] = ex;
    test08.board[1][0] = zero;
    test08.board[1][2] = ex;
    test08.board[2][1] = zero;
    test08.board[2][2] = ex;
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", test08.board[i][j]);
        }
        printf("\n");
    }
    result = checkGrid(&test08);
    if(result == tie) {
        printf("Test 08 success.\n");
    } else {
        printf("Test 08 failed, result: %d, expected: 2\n", result);
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