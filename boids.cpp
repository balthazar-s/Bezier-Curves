#include <vector> 
#include <math.h>
#include "boids.hpp"
using namespace std;

void Boid::initialise()
{
    boid_shape.setRadius(10);
    boid_shape.setFillColor(sf::Color::Green);
    boid_shape.setPosition(pos[0], pos[1]);
}

void Boid::draw_boid(sf::RenderWindow& window) 
{
    window.draw(boid_shape);
}

void Boid::update_pos()
{
    
}