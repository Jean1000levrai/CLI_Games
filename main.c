#include "interface.c"


int main(){
    short gridTest[3][3] = {
        {0, 2, 0}, 
        {2, 0, 1},
        {1, 1, 0}
    };
    short **debug;
    debug = malloc(3 * sizeof(short *));
    for (int i = 0; i < 3; i++) {
        debug[i] = malloc(3 * sizeof(short));
    }

    debug[0][0] = -1;
    debug[0][1] = -1;
    debug[0][2] = -1;
    debug[1][0] = -1;
    debug[1][1] = -1;
    debug[1][2] = -1;
    debug[2][0] = -1;
    debug[2][1] = -1;
    debug[2][2] = -1;

    printCLI(debug, 3);

    gameAiP();
    return 0;
}


