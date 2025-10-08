


#include <stdio.h>
int checkWin(int row, int col, int player, int **grid, short n, short m){
    /*
    return 0, 1 or 2, respectively for no win, win of player, win of opponent
    returns -1 if there is something fishy
    */
    //check rows
    int nbAligned = 0;
    int start = 0;
    for (int i = 0; i<n; i++) {
        printf("%d - %d\n",i, row);
        
        if (!start && grid[i][col] == player){
            nbAligned++;
            start = !start;
        }
        if (start && grid[i][col] == player && grid[i-1][col] == player){
            nbAligned++;
        }
        if (start && grid[i][col] != player){
            start = !start;
        }
        
        if (nbAligned>=4){
            return 1;
        }
        // printf("%d\n", nbAligned);
        
    }
    if (nbAligned <= 0) {
        return -1;
    }

    //check cols
    nbAligned = 0;
    for (int i = row-3; i<row+3; i++) {
        if (i<=0 && i>=m && grid[row][i] == player) {
            nbAligned++;
        }
        if (nbAligned>=4){
            return 1;
        }
    }

    

    return 0;
}