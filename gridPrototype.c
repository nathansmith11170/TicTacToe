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
      Test for exes in a column in a row
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

    if(testHasFailed) {
        printf("Tests have failed.\n");
        return EXIT_FAILURE;
    } else {
        printf("All test cases passed.\n");
        return EXIT_SUCCESS;
    }
}