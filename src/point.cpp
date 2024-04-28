#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/point.hpp"
#include <cmath>
using namespace std;

// Init everything about point
void Point::init()
{
    point_shape.setRadius(radius);
    point_shape.setFillColor(color);
    point_shape.setPosition(pos.x-radius, pos.y-radius);
    point_shape.setPointCount(10);
    if (type == 1)
    {
        point_shape.setOutlineThickness(2);
        point_shape.setOutlineColor(sf::Color::White);
    }
}

// Draw point to window
void Point::draw_point(sf::RenderWindow& window)
{
    window.draw(point_shape);
}

// Move point by mouse relative window coordinates
bool Point::drag_point(sf::RenderWindow& window)
{
    pos.x = sf::Mouse::getPosition(window).x;
    pos.y = sf::Mouse::getPosition(window).y;
    point_shape.setPosition(pos.x-radius, pos.y-radius);
    return true;
}