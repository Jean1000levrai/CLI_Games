#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"
#include "interface.h"
#include "hangman.h"

char guessedLetter[MAX_GUESSED];
int nbLetter = 0;

char playerInput() {
    char letter;
    scanf(" %c", &letter); // leading space skips '\n'
    return letter;
}

void printHangman(int i) {
    printf("%s", HANGMANPICS[i]);
}

void game() {
    int running = 1;
    char* secretWord = choseWord();
    int wordLen = strlen(secretWord);
    int nbGuess = 0;
    char guess;

    guessedLetter[0] = '\0';

    while (running) {

        printHangman(nbGuess);
        printf("\n");
        printWord(secretWord, guessedLetter);
        printf("\n");

        printf("Guess a letter: ");
        guess = playerInput();

        if (isInCode(guess, secretWord, wordLen)) {
            guessedLetter[nbLetter++] = guess;
            guessedLetter[nbLetter] = '\0';
        } else {
            nbGuess++;
        }

        if (nbGuess >= MAX_TRIES) {
            running = 0;
        }

        if (checkWin(secretWord, guessedLetter)) {
            printf("You Win!\n");
            running = 0;
        }
    }

    printf("\nWord was: %s\n", secretWord);
    free(secretWord);
}
