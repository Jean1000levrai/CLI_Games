#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"
#include "interface.h"
#include "hangman.h"


char playerInput(){

    char letter;
    scanf("%c", &letter);
    return letter;
}

void printHangman(int i){

    printf("%s", HANGMANPICS[i]);
}

void printWord(char* word){
    printf("%s\n", word);
}

void game(){

    // init game
    int running = 1;
    char* secretWord = choseWord();
    char guess;
    int nbGuess = 0;

    // game loop
    while (running) {
    
        // print hangman
        printHangman(nbGuess);

        // guess
        guess = playerInput();

        // valid guess
        if (isInCode(guess, secretWord, strlen(secretWord))) {
        }
        else {
            nbGuess++;
        }
    }

    printf("%s\n", secretWord);
    free(secretWord);

}
