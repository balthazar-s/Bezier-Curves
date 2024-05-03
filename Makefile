BUILD_DIR := .build

all: compile link

compile:
	g++ -Isrc/include -c src/main.cpp -o $(BUILD_DIR)/main.o
	g++ -Isrc/include -c src/point.cpp -o $(BUILD_DIR)/point.o
	g++ -Isrc/include -c src/curve.cpp -o $(BUILD_DIR)/curve.o


link:
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/point.o \
		$(BUILD_DIR)/curve.o -o $(BUILD_DIR)/main \
		-lsfml-graphics -lsfml-window -lsfml-system
