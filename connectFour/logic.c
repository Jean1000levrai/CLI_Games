


int checkWin(int col, int row, int player, int **grid, short n){
    /*
    return 0, 1 or 2, respectively for no win, win of player, win of opponent
    returns -1 if there is something fishy
    */
    //check rows
    int nbAligned = 0;
    for (int i = row-3; i<row+3; i++) {
        if (i<=0 && grid[i][col] == player) {
            nbAligned++;
        }
        if (nbAligned>=4){
            return 1;
        }
        else if (nbAligned <= 0) {
            return -1;
        }
    }

    //check cols
    nbAligned = 0;
    for (int i = row-3; i<row+3; i++) {
        if (i<=0 && grid[i][col] == player) {
            nbAligned++;
        }
        if (nbAligned>=4){
            return 1;
        }
    }

    return 0;
}