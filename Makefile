BUILD_DIR := .gitignore/build

all: compile link

compile:
	g++ -Isrc/include -c main.cpp -o $(BUILD_DIR)/main.o
	g++ -Isrc/include -c boids.cpp -o $(BUILD_DIR)/boids.o

link:
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/boids.o -o $(BUILD_DIR)/main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
