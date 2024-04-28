# Specify ignored build directory
BUILD_DIR := .build

# Main process
all: compile link

# Compile files separately
compile:
	g++ -Isrc/include -c src/main.cpp -o $(BUILD_DIR)/main.o -DSFML_STATIC
	g++ -Isrc/include -c src/point.cpp -o $(BUILD_DIR)/point.o -DSFML_STATIC
	g++ -Isrc/include -c src/curve.cpp -o $(BUILD_DIR)/curve.o -DSFML_STATIC

# Create final file
link:
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/point.o $(BUILD_DIR)/curve.o -o $(BUILD_DIR)/main \
		-lsfml-graphics -lsfml-window -lsfml-system 