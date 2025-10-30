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

    // size of board
    int l = 5;
    int L = 12;

    // board hints
    int * boardRow = malloc(l * sizeof(int));
    int** board = malloc(L * sizeof(boardRow));

    // board stats
    int * boardStatRow = malloc(l * sizeof(int));
    int** boardStat = malloc(L * sizeof(boardRow));

    // fill board hints and stats
    for (int i = 0; i<l; i++) {
        boardRow[i] = 0;
        boardStatRow[i] = 0;
    }
    for (int i = 0; i<L; i++) {
        board[i] = boardRow;
        board[i] = boardStatRow;
    }


    game(board, l, L);

    


    return 0;
}