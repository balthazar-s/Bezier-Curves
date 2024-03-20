BUILD_DIR := .build

all: compile link

compile:
	g++ -Isrc/include -c main.cpp -o $(BUILD_DIR)/main.o -DSFML_STATIC
	g++ -Isrc/include -c bin/boids.cpp -o $(BUILD_DIR)/boids.o -DSFML_STATIC
	g++ -Isrc/include -c bin/simulation.cpp -o $(BUILD_DIR)/simulation.o -DSFML_STATIC
	g++ -Isrc/include -c bin/settings.cpp -o $(BUILD_DIR)/settings.o -DSFML_STATIC
	g++ -Isrc/include -c bin/menu.cpp -o $(BUILD_DIR)/menu.o -DSFML_STATIC

link:
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/boids.o $(BUILD_DIR)/simulation.o \
		$(BUILD_DIR)/settings.o $(BUILD_DIR)/menu.o -o $(BUILD_DIR)/main \
		-Lsrc/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype \
		-lwinmm -lgdi32 -mwindows -lsfml-main -llibstdc++