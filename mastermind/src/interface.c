#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "logic.h"
#include "interface.h"


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

    arr[2][3] = 'A';

    for (int j = 0; j<L; j++) {
        for (int i = 0; i<l-1; i++) {
        printf("%c - ", arr[j][i]);
        }
    printf("%c\n", arr[j][l-1]);
    }

}

int isGuessValid(char* guess, int nGuess) {
    int i = 0;
    int pass = 0;
    while (guess[i] != '\0') {
        for (int j = 0; j<nColor; j++) {
            if (guess[i] == colors[j]){
                pass = 1;
            }
        }
        if (pass == 0) {
            return 0;
        }
        pass = 0;
        i++;
    }
    return i==nGuess;
}

void game(char** boardStat, int** board, int L, int l) {

    
    initRand();
    char* code = generateCode(5);
    int running = 1;
    int nbGuess = 0;
    
    while (running) {
    
        printBoard(boardStat, board, L, l);

        // guess
        char guess[6];
        printf("Make a guess: \"rygobm\":\n");
        scanf("%5s", guess);

        if (isGuessValid(guess, 5)) {       
            // board & score
            int* score = checkCombi(guess, code, 5);
            board[nbGuess] = malloc(5 * sizeof(int));
            memcpy(board[nbGuess], score, 5 * sizeof(int));
            for (int i = 0; i<l; i++) {
                boardStat[nbGuess][i] = guess[i];
            }
            if (checkWin(score, 5)) {
                printf("You Win!\n");
                running = 0;
            }
    
            // update for a new loop
            free(score);
            if (nbGuess > 11){
                printf("You Loose!");
                running = 0;
            }
            nbGuess++;
        } else {
            printf("Invalid guess!\n");
        }

    }
}