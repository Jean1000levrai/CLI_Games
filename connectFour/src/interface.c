#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "logic.h"


void printGrid(int **grid, int n){
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    printf("|   |   |   |   |   |   |   |\n");
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<7; j++) {
            if (*(*(grid+i)+j) == 0) {
                printf("|   ");
            }
            else if (*(*(grid+i)+j) == 1) {
                printf("| x ");
            }
            else if (*(*(grid+i)+j) == 2) {
                printf("| o ");
            }
            else {
                printf("|WTF|");
            }
        }
        printf("|\n");
    }
    
    printf("|___|___|___|___|___|___|___|\n");
    printf("\n\n");
}

void game(){
    int n = 8;
    int m = 7;

    int **grid = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }

    int win = 0;
    int turn = 1;
    int col = 0;
    int row = 0;

    printGrid(grid, 8);

    while (win == 0 && turn <= 56) {
        printGrid(grid, 8);
        printf("Joueur %d: \nCase: (1, ..., 7) : ", turn);
        scanf("%d", &col);
        drop(col-1, (turn%2)+1, grid, 8, 7);
        win = checkWin(row, col, (turn%2)+1, grid, 8, 7);
        turn++;
        
    
    }



    printf("%d\n", grid[0][2]);
    printf("%d\n", checkWin(0, 2, 1, grid, 8, 7));
}