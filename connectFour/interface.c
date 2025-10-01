#include <stdio.h>


void printGrid(int **grid, int n){
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<7; j++) {
        
            printf("| %d ", *(*(grid+i)+j));
        }
        printf("|\n");
    }
    printf("|___|___|___|___|___|___|___|\n");
}