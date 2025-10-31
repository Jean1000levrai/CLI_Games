#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logic.h"


char colors[6] = {'r', 'y', 'g', 'o', 'b', 'm'};
int nColor = 6;


void initRand(void) {
    srand((unsigned int)time(NULL));
}

char chooseColor(char* color, int n) {
    
    int random = rand() % n;
    return color[random];
}

int isInCode(char color, char* code, int n){
    /*
    takes guess[i] in parameter
    returns 1 if the guess is in the code
    returns 0 otherwise
    */
    for (int i = 0; i<n; i++) {
        if (color == code[i])
            return 1;
    }
    return 0;
}

char* generateCode(int n) {
    char* code = malloc(n * sizeof(char));
    char color;
    for (int i = 0; i<n; i++) {
        color = chooseColor(colors, 6);
        if (isInCode(color, code, i)) {
            i--;
            continue;
        }
        code[i] = color;
    }
    for (int i = 0; i<n-1; i++) {
        printf("%c - ", code[i]);
    }
    printf("%c\n", code[n-1]);

    return code;
}

int correct(char* guess, char* code, int i) {
    /*
    takes guess in parameter and i
    returns 1 if the guess is in the code and in the right place
    returns 0 otherwise
    */
    return guess[i] == code[i];
}

int* checkCombi(char* guess, char* code, int n) {
    int* score = malloc(n * sizeof(int));
    for (int i = 0; i<n; i++) {

        if (correct(guess, code, i)){
            score[i] = 2;
        }
        else if (isInCode(guess[i], code, n)){
            score[i] = 1;
        }
        else {
            score[i] = 0;
        }
    }

    return score;
}

int checkWin(int* row, int n) {
    int i = 0;
    while (row[i] == 2 && i < n) {
        i++;
    }
    return i==n;
}

