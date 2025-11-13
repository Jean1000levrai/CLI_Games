#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "logic.h"

// already counted
// defined because its known
// optimisation
// count it again if you change words.txt
int nbWord = 323500;


void checkWin(){


}

int isInCode(char letter, char* code, int n) {
    /*param: letter, code: the secret word, n is the size of the code
    returns 1 if letter is in code
    returns 0 if it is not
    */
    for (int i = 0; i < n; i++) {
        if (letter == code[i]) {
            return 1;
        }
    }
    return 0;
}

int nbWordCounter(char* word){
    char ch;
    int i = 0;
    FILE *fptr = fopen("../assets/words.txt", "r");
    if(fptr == NULL){
        printf("Error opening file");
        exit(1);
    }
    while ((ch = fgetc(fptr)) != EOF){

        if (ch == '\n') {
            i++;
        }
    }
    return i;    
}

char* choseWord(){ 
    // 38 is nb of letters of the longest word in french (according to ddg ai)
    char* word = malloc(38 * sizeof(char));

    // open file n stuff
    FILE *fptr = fopen("../assets/words.txt", "r");
    if(fptr == NULL){
        printf("Error opening file");
        exit(1);
    }
    int i = 0;
    char ch;
    srand(time(NULL));
    int wordIndex = rand() % nbWord;

    // go to the word right before the one
    while (wordIndex > 0) {

        wordIndex--;
        ch = fgetc(fptr);   
    }

    // finish the already started word
    while ((ch = fgetc(fptr)) != '\n') {
        continue;
    }

    // fill the word
    while ((ch = fgetc(fptr)) != '\n') {
        word[i] = ch;
        i++;
    }

    return word;
}

void printWord(char* word, char* guessedLetter){
    for (int i = 0; i<strlen(word); i++) {
        if (isInCode(word[i], guessedLetter, strlen(guessedLetter))) {
            printf("%c ", word[i]);
        }
        else {
            printf("_ ");
        }
    }
}