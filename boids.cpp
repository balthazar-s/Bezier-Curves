#include <vector> 
#include <math.h>
#include "boids.hpp"
using namespace std;

void Boid::initialise()
{
    boid_shape.setPointCount(3);
    boid_shape.setFillColor(sf::Color(255, 255, 255));
    boid_shape.setPoint(0, sf::Vector2f(0, 10)); // Top point
    boid_shape.setPoint(1, sf::Vector2f(-5, -10)); // Bottom left point
    boid_shape.setPoint(2, sf::Vector2f(5, -10)); // Bottom right point
}

void Boid::draw_boid(sf::RenderWindow& window) 
{
    window.draw(boid_shape);
}

void Boid::update_pos()
{
    pos[0] += vel[0];
    pos[1] += vel[1];
    boid_shape.setPosition(pos[0], pos[1]);
    if (vel[0] != 0) 
    {
        angle = atan(vel[1]/vel[0]) * 180 / M_PI;
    }
    else
    {
        angle = 0; 
    }
    boid_shape.setRotation(angle);
}
