#include <stdio.h>
#include "logic.h"


int checkWin(int row, int col, int player, int **grid, short n, short m) {
    /* 
       Returns:
         0  -> no win
         1  -> given player wins
         2  -> opponent wins
        -1  -> invalid input (fishy)
    */

    if (row < 0 || row >= n || col < 0 || col >= m) return -1;
    if (player != 1 && player != 2) return -1;

    /* Validate grid contains only 0,1,2 */
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int v = grid[r][c];
            if (v != 0 && v != 1 && v != 2) return -1;
        }
    }

    /* lambda-like helper is simulated with a local loop for each direction */
    const int directions[4][2] = {
        { 0,  1}, /* horizontal: left-right */
        { 1,  0}, /* vertical: up-down (rows) */
        { 1,  1}, /* diag: top-left to bottom-right */
        { 1, -1}  /* diag: top-right to bottom-left */
    };

    /* Helper to test one player (playerToTest). Returns 1 if wins else 0 */
    for (int test = 0; test < 2; ++test) {
        int playerToTest = (test == 0) ? player : (3 - player); /* first player, then opponent */

        for (int d = 0; d < 4; ++d) {
            int dr = directions[d][0];
            int dc = directions[d][1];

            int count = 1; // include the placed cell

            /* step forward */
            for (int step = 1; step < 4; ++step) {
                int r = row + dr * step;
                int c = col + dc * step;
                if (r < 0 || r >= n || c < 0 || c >= m) break;
                if (grid[r][c] == playerToTest) count++;
                else break;
            }

            /* step backward */
            for (int step = 1; step < 4; ++step) {
                int r = row - dr * step;
                int c = col - dc * step;
                if (r < 0 || r >= n || c < 0 || c >= m) break;
                if (grid[r][c] == playerToTest) count++;
                else break;
            }

            if (count >= 4) {
                return (playerToTest == player) ? 1 : 2;
            }
        }
    }

    return 0; // no win 
}

int drop(int col, int player, int **grid, short n, short m) {
    for (int row = n - 1; row >= 0; --row) {
        if (grid[row][col] == 0) {
            grid[row][col] = player;
            return row;
        }
    }
    return -1; // full column 
}
