#ifndef INTERFACE_H
#define INTERFACE_H

#define MAX_GUESSED 26


char guessedLetter[MAX_GUESSED];
extern int nbLetter;

void game();
void printHangman(int i);

#endif