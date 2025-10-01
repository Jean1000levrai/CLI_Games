#include <stdlib.h>
#include "interface.c"

int main(){
    int n = 8;
    int m = 7;
    int** grid;
    grid = malloc(n*sizeof(int));
    for (int i = 0; i<n; i++) {
        *(grid+i) = malloc(m*sizeof(int));
    }
    // choseANameLater(grid, );
}