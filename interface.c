#include <stdio.h>
#include <stdlib.h>
#include "logic.c"
#include "ia.c"

void printCLI(short **grid, short n){
    int count = 0;
    printf("       A       B       C    \n");
    printf("    _______________________\n");
    for (int i = 0; i<n; i++) {
        printf("   |       |       |       |\n");
        printf("%d  ", i+1);
        for (int j = 0; j<n; j++) {
            switch (grid[i][j]) {
                case -1:
                    printf("|  %c-%d  ", j+65, i+1);
                    break;
                case 0:
                    printf("|       ");
                    break;
                case 1:
                    printf("|   x   ");
                    break;
                case 2:
                    printf("|   o   ");
                    break;
                }
                count++;
            }
            printf("|\n");
            printf("   |_______|_______|_______|\n");
        }
        for (int k = 0; k<3; k++) {
            for (int j=0; j<3; j++) {
            
                printf("%d ;", grid[k][j]);
            }
        }
        printf("\n");
        printf("\n------------------------------\n\n");
}

void game(){
    // the grid
    short **grid;
    grid = malloc(3*sizeof(short *));
    for (int i = 0; i<3; i++) {
        grid[i] = malloc(3*sizeof(short));
    }
    grid[0][0] = 0;
    grid[0][1] = 0;
    grid[0][2] = 0;
    grid[1][0] = 0;
    grid[1][1] = 0;
    grid[1][2] = 0;
    grid[2][0] = 0;
    grid[2][1] = 0;
    grid[2][2] = 0;

    // useful variables
    short turn = 1;
    short win = 2;
    short line;
    char col;
    short nb_turn = 1;
    
    // boucle tant que personne n'a gagné
    // et tant que la grille n'est pas pleine
    while (win == 2 && nb_turn <= 9) {
        
        printCLI(grid, 3);
        printf("Joueur %d: \ncolonne: A, B, C : ", turn);
        scanf(" %c", &col);
        printf("ligne: 1, 2, 3 : ");
        scanf("%hd", &line);
        printf("\n\n");

        if (grid[line-1][col-65] == 0){
            grid[line-1][col-65] = turn;
            turn = turn == 1 ? 2 : 1;
            win = checkWin(grid, 3);
            nb_turn++;
        }else {
            printf("Oups ! La case est déjà occupé, tu peux rejouer.\n");
        }
    }

    // decide un vainqueur lorsque le jeu est fini
    if (win == 0){
        printCLI(grid, 3);
        printf("Joueur 1 a gagné\n");
    }else if (win == 1){
        printCLI(grid, 3);
        printf("Joueur 2 a gagné\n");
    }else if (win == 2) {
        printCLI(grid, 3);
        printf("Égalité !\n");
    }
    else {
        printCLI(grid, 3);
        printf("C'est pas possible ça XD\nComment t'as fais ?\n");
    }
}

void gameAiP(){
    // la grille
    short **grid;
    grid = malloc(3*sizeof(short *));
    for (int i = 0; i<3; i++) {
        grid[i] = malloc(3*sizeof(short));
    }
    grid[0][0] = 0;
    grid[0][1] = 0;
    grid[0][2] = 0;
    grid[1][0] = 0;
    grid[1][1] = 0;
    grid[1][2] = 0;
    grid[2][0] = 0;
    grid[2][1] = 0;
    grid[2][2] = 0;

    // variables utiles
    short turn = 1;
    short win = 2;
    short line;
    char col;
    short nb_turn = 1;
    int* bestMoveSquare;
    bestMoveSquare = malloc(2*sizeof(int));

    // boucle tant que personne n'a gagné
    // et tant que la grille n'est pas pleine
    while (win == 2 && nb_turn <= 9) {
        
        bestMove(grid, 3, bestMoveSquare);
        printCLI(grid, 3);

        // player's turn
        if (turn == 1) {
            printf("Joueur %d: \ncolonne: A, B, C : ", turn);
            scanf(" %c", &col);
            printf("ligne: 1, 2, 3 : ");
            scanf("%hd", &line);
        }else {
            bestMove(grid, 3, bestMoveSquare);
        }
        
        printf("\n\n");
        if (grid[line-1][col-65] == 0 || grid[bestMoveSquare[0]][bestMoveSquare[1]] == 0){
            if (turn == 2) {
                grid[bestMoveSquare[0]][bestMoveSquare[1]] = turn;
            }else {
                grid[line-1][col-65] = turn;
            }
            turn = turn == 1 ? 2 : 1;
            win = checkWin(grid, 3);
            nb_turn++;
        }else {
            printf("Oups ! La case est déjà occupé, tu peux rejouer.\n");
        }

    }

    // decide un vainqueur lorsque le jeu est fini
    if (win == 0){
        printCLI(grid, 3);
        printf("Joueur 1 a gagné\n");
    }else if (win == 1){
        printCLI(grid, 3);
        printf("L'IA a gagné\n");
    }else if (win == 2) {
        printCLI(grid, 3);
        printf("Égalité !\n");
    }
    else {
        printCLI(grid, 3);
        printf("C'est pas possible ça XD\nComment t'as fais ?\n");
    }
}


