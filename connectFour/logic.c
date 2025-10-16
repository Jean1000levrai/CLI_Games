#include <stdio.h>


int checkWin(int row, int col, int player, int **grid, short n, short m) {
    /*
    Returns 0 if there's no win, 1 if player wins, 2 if opponent wins, -1 if something fishy
    */
    // Check rows
    int nbAligned = 0;  // counts nb aligned
    int start = 0;  // 0 if hasn't started counting, else 0

    for (int i = 0; i < m; i++) {
        if (!start && grid[i][col] == player) {
            nbAligned++;
            start = !start;
        }
        if (start && grid[i][col] == player && i > 0 && grid[i-1][col] == player) {
            nbAligned++;
        }
        if (start && grid[i][col] != player) {
            start = !start;
        }
        if (nbAligned >= 4) {
            return 1; // player wins
        }
    }

    // Check columns
    nbAligned = 0;
    for (int i = row - 3; i <= row + 3; i++) {
        if (i >= 0 && i < n && row != i && grid[i][col] == player) {
            nbAligned++;
        }
        if (nbAligned >= 4) {
            return 1; // player wins
        }
    }

    // Check diagonals (top-left to bottom-right)
    nbAligned = 0;
    int startDiag = row - 3;
    int startCol = col - 3;
    for (int i = startDiag, j = startCol; i <= row + 3 && j <= col + 3; i++, j++) {
        if (i >= 0 && i < n && j >= 0 && j < m && row != i && col != j && grid[i][j] == player) {
            nbAligned++;
        }
        if (nbAligned >= 4) {
            return 1; // player wins
        }
    }

    // Check diagonals (top-right to bottom-left)
    nbAligned = 0;
    startDiag = row - 3;
    startCol = col + 3;
    for (int i = startDiag, j = startCol; i <= row + 3 && j >= col - 3; i++, j--) {
        if (i >= 0 && i < n && j >= 0 && j < m && row != i && col != j && grid[i][j] == player) {
            nbAligned++;
        }
        if (nbAligned >= 4) {
            return 1; // player wins
        }
    }

    return 0; // no win
}