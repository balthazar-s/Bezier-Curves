# Specify ignored build directory
BUILD_DIR := .build

# Main process
all: compile link

# Compile files seperately
compile:
	g++ -Isrc/include -c main.cpp -o $(BUILD_DIR)/main.o -DSFML_STATIC
	g++ -Isrc/include -c src/boids.cpp -o $(BUILD_DIR)/boids.o -DSFML_STATIC
	g++ -Isrc/include -c src/settings.cpp -o $(BUILD_DIR)/settings.o -DSFML_STATIC

# Create final file
link:
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/boids.o \
		$(BUILD_DIR)/settings.o -o $(BUILD_DIR)/main \
		-Lsrc/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype \
		-lwinmm -lgdi32 -mwindows -lsfml-main -static -lstdc++ -static-libgcc -static-libstdc++
