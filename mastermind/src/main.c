#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "interface.h"

void printArr(int* arr, int n){
    for (int i = 0; i<n-1; i++) {
        printf("%d - ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
}

void printArr2d(int** arr, int l, int L) {

    for (int j = 0; j<L; j++) {
        for (int i = 0; i<l-1; i++) {
        printf("%d - ", arr[j][i]);
        }
    printf("%d\n", arr[j][l-1]);
    }

}

int main(){

    int l = 5;
    int L = 12;

    // allocate row pointers
    int **board = malloc(L * sizeof(int *));
    char **boardStat = malloc(L * sizeof(char *));

    for (int i = 0; i < L; i++) {
        board[i] = malloc(l * sizeof(int));
        boardStat[i] = malloc(l * sizeof(char));
        for (int j = 0; j < l; j++) {
            board[i][j] = 0;
            boardStat[i][j] = '.';
        }
    }

    game(boardStat, board, L, l);

    for (int i = 0; i < L; i++) {
        free(board[i]);
        free(boardStat[i]);
    }
    free(board);
    free(boardStat);

    
    return 0;
}