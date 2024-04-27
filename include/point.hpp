#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

#ifndef POINT_HPP
#define POINT_HPP

class Point {
  public:
    sf::Vector2f pos;
    sf::Color color;
    int type; // 0 is anchor, 1 is control
    int radius = 7; 
    sf::CircleShape point_shape;
    bool selected = false; 

    // Constructor to initialize position and velocity
    Point(const sf::Vector2f position, const sf::Color color, const int type) : pos(position), color(color), type(type) {};

    void init();

    void check_mouse(sf::RenderWindow& window);

    void draw_point(sf::RenderWindow& window);

    bool drag_point(sf::RenderWindow& window);
};

#endif