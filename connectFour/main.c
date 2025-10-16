#include <stdio.h>
#include <stdlib.h>
#include "interface.c"
#include "logic.c"

void printArr2d(int** arr, short n, short m){
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("%d, ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

int main(){
    int n = 8;
    int m = 7;

    int **grid = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }

    grid[0][1]= 1;
    grid[0][2]= 1;
    grid[0][3]= 1;
    grid[0][4]= 1;
    printArr2d(grid, n, m);
    printGrid(grid, 8);
    printf("%d\n", grid[0][2]);
    printf("%d\n", checkWin(2, 0, 1, grid, 8, 7));
}