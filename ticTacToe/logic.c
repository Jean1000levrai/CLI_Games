#include <stdio.h>
#include <stdlib.h>

int checkWin(short **grid, short n) {
    // check diagonals
    if (grid[0][0] != 0 && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        return (grid[0][0] == 1) ? 0 : 1;
    if (grid[0][2] != 0 && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return (grid[0][2] == 1) ? 0 : 1;

    // check rows
    for (int i = 0; i < n; i++)
        if (grid[i][0] != 0 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            return (grid[i][0] == 1) ? 0 : 1;

    // check columns
    for (int i = 0; i < n; i++)
        if (grid[0][i] != 0 && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
            return (grid[0][i] == 1) ? 0 : 1;

    return 2; // no winner / tie
}

