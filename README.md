# Nameless Game

### Overview
This is a simple test game developed in C++ to explore game development concepts and techniques. The game includes basic gameplay mechanics, rendering, and input handling.

### Requirements

To build and run this project, you need the following:

- **SFML Libraries**:
  - `libsfml-graphics`
  - `libsfml-window`
  - `libsfml-system`

- **Compiler**:
  - `g++` (GNU C++ Compiler)

### Installation

#### On Arch

You can install the SFML libraries and g++ using the following command:
```sh 
sudo pacman -S sfml gcc
```

#### On Ubuntu/Debian

You can install the SFML libraries using the following commands:

```sh
sudo apt-get update
sudo apt-get install libsfml-dev g++
```

#### On macOS

You can install SFML using Homebrew:

```sh
brew install sfml gcc
```

#### On Windows

1. Download the SFML binaries from the SFML website.
2. Install g++ as part of MinGW or another suitable development environment.
3. Follow the instructions for setting up the SFML and g++ toolchain on Windows.

### Building the Project

To build the project, follow these steps:

1. Clone the repository:

```sh
git clone https://github.com/FlorisVleugels/sfml-game.git
cd sfml-game
```

2. Build the project:

```sh
make
```
This will compile the source files and create an executable in the build directory.

### Running the Program

Navigate to the build directory and run the executable:

```sh
cd build
./mygame
```

