#include <vector>
#include <SFML/Graphics.hpp>
#include "point.hpp"
using namespace std;

#ifndef CURVE_HPP
#define CURVE_HPP

class Curve {
  public:
    vector<sf::Vector2f> anchors;
    sf::Vector2f control;
    int width = 2;
    int resolution = 32;
    vector<sf::Vector2f> curve_points; 

    // Constructor to initialize position and velocity
    Curve(const vector<sf::Vector2f> anchors, const sf::Vector2f control) : anchors(anchors), control(control) {};

    void update_curve(vector<Point> points);

    void draw_curve(sf::RenderWindow& window);
};

#endif