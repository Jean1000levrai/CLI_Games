#include <stdio.h>
#include <stdlib.h>

#include "logic.h"
#include "interface.h"
#include "hangman.h"


void printHangman(int i){
    // 0 <= i <= 9
    printf("%s", HANGMANPICS[i]);

}

void game(){
   
}

int main(){
    printHangman(5);
}