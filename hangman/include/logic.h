#ifndef LOGIC_H
#define LOGIC_H

int checkWin(const char *word, const char *guessedLetter);
void readWord();
char* choseWord();
int isInCode(char letter, char* code, int n);
void printWord(char* word, char* guessedLetter);

#endif