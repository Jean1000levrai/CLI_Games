#ifndef LOGIC_H
#define LOGIC_H

void initRand(void);
char* generateCode(int n);
int* checkCombi(char* guess, char* code, int n);
int checkWin(int* row, int n);

#endif