# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17 -Isrc/player -Isrc/floor -Isrc/animations

# SFML libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source directories
SRC_DIRS = src/animations src/scenes src/npc src/player src

# Build directories
BUILD_DIR = build
BUILD_SUBDIRS = $(BUILD_DIR)/animations $(BUILD_DIR)/scenes $(BUILD_DIR)/npc $(BUILD_DIR)/player

# Find all .cpp files in the src directory and its subdirectories
SRCS = $(wildcard $(SRC_DIRS:%=%/*.cpp))

# Object files
OBJS = $(patsubst src/%.cpp, build/%.o, $(SRCS))

# Executable name
EXEC = $(BUILD_DIR)/mygame

# Default target
all: $(BUILD_SUBDIRS) $(EXEC)

# Create the build directories if they do not exist
$(BUILD_SUBDIRS):
	mkdir -p $(BUILD_SUBDIRS)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LIBS)

# Compile .cpp files to .o files
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_SUBDIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependencies
-include $(OBJS:.o=.d)

# Generate dependencies
$(BUILD_DIR)/%.d: src/%.cpp | $(BUILD_SUBDIRS)
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(BUILD_DIR)/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

