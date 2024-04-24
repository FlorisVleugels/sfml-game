# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17

# SFML libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = main.cpp Animation.cpp Animation.h

# Executable name
EXEC = myprogram

# Make all
all:
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC) $(LIBS)

# Clean
clean:
	rm -f $(EXEC)

