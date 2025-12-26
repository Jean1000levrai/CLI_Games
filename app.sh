#!/bin/bash

set -e

printf "HI! Choose a game:\n\
1. [C]onnect Four\n\
2. [H]angman\n\
3. [T]ic Tac Toe\n\
4. [R]ock Paper Scissors\n\
5. [M]astermind\n\
6. [Q]uit\n"

read game

case $game in
    "C" | "c" | "1")
        ./dist/connectFour
        ;;
    "H" | "h" | "2")
        cd hangman/build
        ./hangman
        ;;
    "T" | "t" | "3")
        ./dist/ticTacToe
        ;;
    "R" | "r" | "4")
        ./dist/rockPaperScissors
        ;;
    "M" | "m" | "5")
        ./dist/mastermind
        ;;
    "q" | "Q" | "quit" | "Quit" | "6")
        exit 0 ;;
    *)
        echo "Invalid game"
        ;;
esac