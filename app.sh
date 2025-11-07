#!/bin/bash

set -e

echo "HI! Choose a game:\n1. [C]onnect Four\n2. [H]angman\n3. [T]ic Tac Toe\n4. [R]ock Paper Scissors"

read game

case $game in
    "C" | "c" | "1")
        cd connectFour
        ./build/main
        ;;
    "H" | "h" | "2")
        cd hangman
        ./build/main
        ;;
    "T" | "t" | "3")
        cd ticTacToe
        ./build/main
        ;;
    "R" | "r" | "4")
        cd rockPaperScissors
        ./build/main
        ;;
    *)
        echo "Invalid game"
        ;;
esac