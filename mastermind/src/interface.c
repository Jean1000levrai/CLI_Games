#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "logic.h"
#include "interface.h"
#include "main.h"


void printBoard(char** boardStat, int** board, int L, int l) {
    for (int j = 0; j<L; j++) {

        for (int i = 0; i<l-1; i++) {
            printf("%c - ", boardStat[j][i]);
        }
        printf("%c   --->   ", boardStat[j][l-1]);

        for (int i = 0; i<l-1; i++) {
            printf("%d - ", board[j][i]);
        }
        printf("%d\n", board[j][l-1]);
    }
    printf("\n\n");
    
}

void printArr2dstr(char** arr, int l, int L) {

    for (int j = 0; j<L; j++) {
        for (int i = 0; i<l-1; i++) {
        printf("%c - ", arr[j][i]);
        }
    printf("%c\n", arr[j][l-1]);
    }

}

void game(char** boardStat, int** board, int L, int l) {

    
    initRand();
    char* code = generateCode(5);
    printf("code: %s\n", code);     // ----- T E M P -----
    int running = 1;
    int nbGuess = 0;
    
    while (running) {
    
        printBoard(boardStat, board, L, l);

        // guess
        char guess[6];
        printf("Make a guess: \"rygobm\":\n");
        scanf("%5s", guess);

        int* score = checkCombi(guess, code, 5);
        printArr(score, 5);
        board[nbGuess] = malloc(5 * sizeof(int));
        memcpy(board[nbGuess], score, 5 * sizeof(int));
        printArr2dstr(boardStat, l, L);
        for (int i = 0; i<l; i++) {
            boardStat[nbGuess][i] = guess[i];
        }
        printArr2dstr(boardStat, l, L);
        if (checkWin(score, 5)) {
            printf("You Win!\n");
            running = 0;
        }
        free(score);

        if (nbGuess > 11){
            printf("You Loose!");
            running = 0;
        }
        nbGuess++;
    }
}