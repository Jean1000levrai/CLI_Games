#include "logic.h"
#include <stdio.h>

int checkWinSquare(short **grid, short n, short square[2], short botPlayer){
    /* 
       grid   : the board
       n      : grid size (3)
       square : [row, col] position to test
       botPlayer : 1 for X, 2 for O (the AI’s symbol)

       Returns:
       2 -> playing here makes the bot win
       1 -> playing here blocks the opponent’s win
       0 -> otherwise
       */

    short opponent = (botPlayer == 1) ? 2 : 1;
    short** gridCopy = malloc(n*sizeof(short*));
    for (int i = 0; i<n; i++) {
        gridCopy[i] = malloc(n*sizeof(short));
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            gridCopy[i][j] = grid[i][j];
        }
    }
    if (gridCopy[square[0]][square[1]] != 0) {
        // free memory
        for (int i = 0; i < n; i++) free(gridCopy[i]);
        free(gridCopy);

        return -1;  // already controlled square  
    }

    // simulate bot playing here
    gridCopy[square[0]][square[1]] = botPlayer;

    if (checkWin(gridCopy, n) == 1) {
        // free memory
        for (int i = 0; i < n; i++) free(gridCopy[i]);
        free(gridCopy);

        return 2; // winning move
    }

    // simulate opponent playing here
    gridCopy[square[0]][square[1]] = opponent;

    if (checkWin(gridCopy, n) == 0) {
        // free memory
        for (int i = 0; i < n; i++) free(gridCopy[i]);
        free(gridCopy);

        return 1; // blocking move
    }
    // free memory
    for (int i = 0; i < n; i++) free(gridCopy[i]);
    free(gridCopy);

    return 0; // neutral
}

void bestMove(short **grid, short n, int* squareMax){
    int score = -1;
    short square[2] = {0, 0};
    int scoreNow = 0;

    for (int i = 0; i<n; i++) {
        square[0] = i;
        for(int j = 0; j<n;j++){
            square[1] = j;  
            if (grid[square[0]][square[1]] == 0){ 
                scoreNow = checkWinSquare(grid, n, square, 2);
                if (score < scoreNow && grid[square[0]][square[1]] == 0){
                    score = scoreNow;
                    squareMax[0] = square[0];
                    squareMax[1] = square[1];
                }
            }
        }   
    }
}




