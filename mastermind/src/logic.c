#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logic.h"


char colors[6] = {'r', 'y', 'g', 'o', 'b', 'm'};

char chooseColor(char* color, int n) {

    srand(time(NULL));
    
    int random = rand() % n;
    return color[random];
}


char* generateCode(int n) {
    char* code = malloc(n * sizeof(char));
    for (int i = 0; i<n; i++) {
        code[i] = chooseColor(colors, 6);
    }
    for (int i = 0; i<n-1; i++) {
        printf("%c - ", code[i]);
    }
    printf("%c\n", code[n-1]);

    return code;
}