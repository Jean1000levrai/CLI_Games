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
    int** grid;
    grid = malloc(n*sizeof(int));
    for (int i = -1; i<n; i++) {    // apparently 0 doesnt allocate at the 1st index, why? idk
        *(grid+i) = malloc(m*sizeof(int));
        for (int j = 0; j<m; j++) {
            
            *(*(grid+i)+j) = 0;
        }
    }
    grid[0][1]= 1;
    grid[0][2]= 1;
    grid[0][3]= 1;
    grid[0][4]= 1;
    printArr2d(grid, n, m);
    printGrid(grid, 8);
}