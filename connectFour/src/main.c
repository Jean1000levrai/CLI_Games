#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void printArr2d(int** arr, short n, short m){
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            printf("%d, ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

int main(){
    
    game();
    
}