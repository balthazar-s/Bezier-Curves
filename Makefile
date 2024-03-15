all: compile link

compile:
	g++ -Isrc/include -c main.cpp boids.cpp

link:
	g++ main.o boids.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

