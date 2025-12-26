
# CLI Games  
     
![preview](ressources/screenshot1.png)    

## Author
[Jean1000](https://github.com/Jean1000levrai/CLI_Games)    


## 📑 Table of Contents
[ℹ️ About](#-about)  
[✨ Features](#-features)  
[💾 Installation](#-installation)   
[📜 License](#-license)    
   

## ℹ️ About
This a project made to learn the C programming language.   

## ✨ Features
- Tictactoe
- Rock Paper Scissors
- Connect Four
- Mastermind   
- Hangman

## 💾 Installation
### 1. Prerequisites
 - C11 or above
 - A Compiler (e.g. gcc, clang)
 - CMake >= 3.16     

### 2. Download

#### In the desired folder:

```bash
git clone https://github.com/Jean1000levrai/CLI_Games.git
cd CLI_Games
```

## Install via installation script

### 3. install
```bash
chmod +x install.sh
./install.sh
```

### Play on the command line interface!

```bash
./app.sh
```

## Compile manually

### 3. 
#### Browse to the game of your choice
```bash
cd ticTacToe    # for example
```

### 4. Compile
```bash
mkdir -p build
cd build/
cmake ..
make
```

### 5. Play on the command line interface!
In the `build`folder.   
You can find the game's name with `ls`, then looking for the binary file.   
```bash
./<name_of_game>
```

<br><br>
## 📜 License
This project is licensed under the MIT License — see the LICENSE file for details.
