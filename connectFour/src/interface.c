#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "logic.h"


void printGrid(int **grid, int n, int m){
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    printf("|---|---|---|---|---|---|---|\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0)
                printf("|   ");
            else if (grid[i][j] == 1)
                printf("| x ");
            else if (grid[i][j] == 2)
                printf("| o ");
            else
                printf("| ? ");
        }
        printf("|\n");
    }
    printf("|___|___|___|___|___|___|___|\n\n");
}

void game() {
    int n = 8, m = 7;
    int **grid = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) grid[i][j] = 0;
    }

    int win = 0;
    int turn = 0;
    int col, row;

    while (win == 0 && turn < n * m) {
        printGrid(grid, n, m);
        printf("Player %d — Choose column (1–%d): ", (turn % 2) + 1, m);
        if (scanf("%d", &col) != 1 || col < 1 || col > m) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n'); // clear stdin
            continue;
        }

        row = drop(col - 1, (turn % 2) + 1, grid, n, m);
        if (row == -1) {
            printf("Column full. Choose another.\n");
            continue;
        }

        win = checkWin(row, col - 1, (turn % 2) + 1, grid, n, m);
        turn++;
    }

    printGrid(grid, n, m);
    if (win == 1)
        printf("Player %d wins!\n", ((turn - 1) % 2) + 1);
    else if (turn == n * m)
        printf("Draw! No more moves.\n");

    for (int i = 0; i < n; i++) free(grid[i]);
    free(grid);
}