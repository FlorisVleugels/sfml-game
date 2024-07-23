# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17

# SFML libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source directories
SRC_DIR = src
BUILD_DIR = build

# Find all .cpp files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executable name
EXEC = $(BUILD_DIR)/mygame

# Make all
all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LIBS)

# Compile .cpp files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependencies
-include $(OBJS:.o=.d)

# Generate dependencies
$(BUILD_DIR)/%.d: $(SRC_DIR)/%.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(BUILD_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

# Clean
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

