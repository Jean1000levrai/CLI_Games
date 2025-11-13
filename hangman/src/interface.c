#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"
#include "interface.h"
#include "hangman.h"

char* guessedLetter = "";
int nbLetter = 0;


char playerInput(){

    char letter;
    scanf("%c", &letter);
    return letter;
}

void printHangman(int i){

    printf("%s", HANGMANPICS[i]);
}

void game(){

    // init game
    int running = 1;
    char* secretWord = choseWord();
    char* urGuessedWord = malloc(strlen(secretWord) * sizeof(char));
    char guess;
    int nbGuess = 0;

    // game loop
    while (running) {
    
        // print hangman
        printHangman(nbGuess);
        printf("\n");
        printf("the word is: ");
        printWord(secretWord, guessedLetter);

        // print word
        // void printWord(char* word, char* guessedLetter);

        // guess
        printf("Guess a letter: ");
        guess = playerInput();

        // valid guess
        if (isInCode(guess, secretWord, strlen(secretWord))) {
            guessedLetter[nbLetter] = guess;
            
        }
        else {
            nbGuess++;
        }
    }

    printf("%s\n", secretWord);
    free(secretWord);

}
