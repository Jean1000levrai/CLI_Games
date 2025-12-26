#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "logic.h"

int nbWord = 323500;

int checkWin(const char *word, const char *guessedLetter) {
    int wordLen = strlen(word);
    int guessedLen = strlen(guessedLetter);

    for (int i = 0; i < wordLen; i++) {
        if (!isInCode(word[i], (char *)guessedLetter, guessedLen)) {
            return 0; // at least one letter not guessed
        }
    }
    return 1; // all letters guessed
}


int isInCode(char letter, char* code, int n) {
    for (int i = 0; i < n; i++) {
        if (letter == code[i]) {
            return 1;
        }
    }
    return 0;
}

char* choseWord(){ 
    FILE *fptr = fopen("../assets/words.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char* word = malloc(64);   // enough for longest word
    if (!word) {
        exit(1);
    }

    srand(time(NULL));
    int wordIndex = rand() % nbWord;
    int current = 0;
    char buffer[64];

    while (fgets(buffer, sizeof(buffer), fptr)) {
        if (current == wordIndex) {
            buffer[strcspn(buffer, "\r\n")] = '\0';  // remove newline
            strcpy(word, buffer);
            break;
        }
        current++;
    }

    fclose(fptr);
    return word;
}


void printWord(char* word, char* guessedLetter) {
    int wordLen = strlen(word);
    int guessLen = strlen(guessedLetter);

    for (int i = 0; i < wordLen; i++) {
        if (isInCode(word[i], guessedLetter, guessLen)) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
}
