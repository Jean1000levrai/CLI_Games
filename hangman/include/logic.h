#ifndef LOGIC_H
#define LOGIC_H

void checkWin();
void readWord();
char* choseWord();
int isInCode(char letter, char* code, int n);
void printWord(char* word, char* guessedLetter);

#endif