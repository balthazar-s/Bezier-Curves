BUILD_DIR := .build

# SFML directory paths
SFML_LIB := /mingw64/lib

# SFML library names for static linking
SFML_LIBRARIES := -lsfml-graphics-s -lsfml-window-s -lsfml-system-s

# Compiler flags for static linking
STATIC_FLAGS := -static -static-libgcc -static-libstdc++

all: compile link

compile:
	g++ -c main.cpp -o $(BUILD_DIR)/main.o
	g++ -c boids.cpp -o $(BUILD_DIR)/boids.o

link:
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/boids.o -o $(BUILD_DIR)/main -L$(SFML_LIB) $(SFML_LIBRARIES) $(STATIC_FLAGS)
