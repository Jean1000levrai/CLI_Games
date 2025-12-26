#include "logic.h"

int checkWin(int row, int col, int player, int **grid, int n, int m) {
    /*
        Returns:
          0 -> no win
          1 -> player wins
         -1 -> invalid input
    */

    if (!grid) return -1;
    if (player != 1 && player != 2) return -1;
    if (row < 0 || row >= n || col < 0 || col >= m) return -1;
    if (grid[row][col] != player) return 0;

    const int directions[4][2] = {
        { 0,  1},  // horizontal
        { 1,  0},  // vertical
        { 1,  1},  // diagonal \.
        { 1, -1}   // diagonal /
    };

    for (int d = 0; d < 4; ++d) {
        int dr = directions[d][0];
        int dc = directions[d][1];
        int count = 1;

        /* forward */
        for (int step = 1; step < 4; ++step) {
            int r = row + dr * step;
            int c = col + dc * step;
            if (r < 0 || r >= n || c < 0 || c >= m) break;
            if (grid[r][c] != player) break;
            count++;
        }

        /* backward */
        for (int step = 1; step < 4; ++step) {
            int r = row - dr * step;
            int c = col - dc * step;
            if (r < 0 || r >= n || c < 0 || c >= m) break;
            if (grid[r][c] != player) break;
            count++;
        }

        if (count >= 4)
            return 1;
    }

    return 0;
}

int drop(int col, int player, int **grid, int n, int m) {
    if (!grid) return -1;
    if (player != 1 && player != 2) return -1;
    if (col < 0 || col >= m) return -1;

    for (int row = n - 1; row >= 0; --row) {
        if (grid[row][col] == 0) {
            grid[row][col] = player;
            return row;
        }
    }

    return -1;  // column full
}
