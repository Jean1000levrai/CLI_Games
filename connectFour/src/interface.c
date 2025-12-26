#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "logic.h"

static void printGrid(int **grid, int n, int m) {
    /* column numbers */
    for (int j = 1; j <= m; j++)
        printf("| %d ", j);
    printf("|\n");

    for (int j = 0; j < m; j++)
        printf("|---");
    printf("|\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch = ' ';
            if (grid[i][j] == 1) ch = 'x';
            else if (grid[i][j] == 2) ch = 'o';
            printf("| %c ", ch);
        }
        printf("|\n");
    }

    for (int j = 0; j < m; j++)
        printf("|___");
    printf("|\n\n");
}

void game(void) {
    const int n = 6;   /* rows */
    const int m = 7;   /* columns */

    int **grid = malloc(n * sizeof *grid);
    if (!grid) return;

    for (int i = 0; i < n; i++) {
        grid[i] = malloc(m * sizeof *grid[i]);
        if (!grid[i]) goto cleanup;
        for (int j = 0; j < m; j++)
            grid[i][j] = 0;
    }

    int win = 0;
    int turn = 0;

    while (!win && turn < n * m) {
        int col, row;
        int player = (turn % 2) + 1;

        printGrid(grid, n, m);
        printf("Player %d — Choose column (1–%d): ", player, m);

        if (scanf("%d", &col) != 1 || col < 1 || col > m) {
            printf("Invalid input. Try again.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        row = drop(col - 1, player, grid, n, m);
        if (row == -1) {
            printf("Column full. Choose another.\n");
            continue;
        }

        win = checkWin(row, col - 1, player, grid, n, m);
        if (win == -1) {
            printf("Internal error.\n");
            break;
        }

        turn++;
    }

    printGrid(grid, n, m);

    if (win)
        printf("Player %d wins!\n", ((turn - 1) % 2) + 1);
    else if (turn == n * m)
        printf("Draw! No more moves.\n");

cleanup:
    for (int i = 0; i < n; i++)
        free(grid[i]);
    free(grid);
}
