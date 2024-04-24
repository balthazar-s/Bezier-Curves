#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

#ifndef POINT_HPP
#define POINT_HPP

class Point {
  public:
    vector<float> pos;
    sf::Color color;
    int type;
    int radius = 7; 
    sf::CircleShape point_shape; 

    // Constructor to initialize position and velocity
    Point(const vector<float> position, const sf::Color color, const int type) : pos(position), color(color), type(type) {};

    void init();

    void draw_point(sf::RenderWindow& window);

    void drag_point(sf::RenderWindow& window);
};

#endif