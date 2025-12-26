#!/bin/bash

rm -rf dist
mkdir dist

echo "Compiling..."

cd connectFour
mkdir -p build
cd build
cmake ..
make
mv connectFour ../../dist
echo "connectFour: Done"

cd ../..
cd hangman
mkdir -p build
cd build
cmake ..
make
echo "hangman: Done"

cd ../..
cd mastermind
mkdir -p build
cd build
cmake ..
make
mv mastermind ../../dist
echo "mastermind: Done"

cd ../..
cd rockPaperScissors
mkdir -p build
cd build
cmake ..
make
mv RockPaperScissors ../../dist
echo "rockPaperScissors: Done"

cd ../..
cd ticTacToe
mkdir -p build
cd build
cmake ..
make
mv ticTacToe ../../dist
echo "ticTacToe: Done"

cd ../..
echo "Done"
echo "Run the app with ./app.sh"
echo "Run the app now? [y/n]"
read run
case "$run" in
    y|o|Y|O) ./app.sh ;;
esac
