#ifndef LOGIC_H
#define LOGIC_H

// {'r', 'y', 'g', 'o', 'b', 'm'};
char colors[6];
int nColor;

void initRand(void);
char* generateCode(int n);
int* checkCombi(char* guess, char* code, int n);
int checkWin(int* row, int n);
int isInCode(char color, char* code, int n);

#endif