#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/point.hpp"
using namespace std;

void Point::init()
{
    point_shape.setRadius(radius);
    point_shape.setFillColor(color);
    point_shape.setPosition(pos[0], pos[1]);
    point_shape.setPointCount(12);
}

void Point::draw_point(sf::RenderWindow& window)
{
    window.draw(point_shape);
}

void Point::drag_point(sf::RenderWindow& window)
{
    pos[0] = sf::Mouse::getPosition(window).x - radius;
    pos[1] = sf::Mouse::getPosition(window).y - radius;

    point_shape.setPosition(pos[0], pos[1]);

}