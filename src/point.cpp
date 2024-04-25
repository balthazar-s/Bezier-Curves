#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/point.hpp"
#include <cmath>
using namespace std;

void Point::init()
{
    point_shape.setRadius(radius);
    point_shape.setFillColor(color);
    point_shape.setPosition(pos.x-radius, pos.y-radius);
    point_shape.setPointCount(10);
}

void Point::draw_point(sf::RenderWindow& window)
{
    window.draw(point_shape);
}

bool Point::drag_point(sf::RenderWindow& window)
{
    if (sqrt(pow(pos.x-sf::Mouse::getPosition(window).x, 2) + pow(pos.y-sf::Mouse::getPosition(window).y, 2)) > radius + 15)
    {
        return false;
    }
    pos.x = sf::Mouse::getPosition(window).x;
    pos.y = sf::Mouse::getPosition(window).y;
    point_shape.setPosition(pos.x-radius, pos.y-radius);
    return true;

}