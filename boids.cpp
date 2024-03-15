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

void Boid::update_pos(int WIDTH, int HEIGHT)
{
    pos[0] += vel[0];
    pos[1] += vel[1];

    // Wrap around from edges
    if (pos[0] > WIDTH + 10)
    {
        pos[0] = -10;
    }
    else if (pos[1] > HEIGHT + 10)
    {
        pos[1] = -10;
    }
    else if (pos[0] < -10)
    {
        pos[0] = WIDTH + 10;
    }
    else if (pos[1] < -10)
    {
        pos[1] = HEIGHT + 10;
    }


    boid_shape.setPosition(pos[0], pos[1]);
    if (vel[0] != 0) 
    {
        angle = (atan2(vel[1], vel[0]) * 180 / M_PI) - 90;
    }
    else
    {
        angle = 0; 
    }
    boid_shape.setRotation(angle);
}

void Boid::separation(vector<Boid>& boids)
{   
    int protected_range = 8;
    int avoidfactor = 0.5;
    int close_dx = 0;
    int close_dy = 0;

    for (int i = 0, len = boids.size(); i < len; i++)
    {
        // Calculate the distance between this boid and the current boid
        float dx = boids[i].pos[0] - pos[0];
        float dy = boids[i].pos[1] - pos[1];
        float distance = sqrt(dx * dx + dy * dy);

        if (distance <= protected_range && distance > 0)
        {
            // Calculate the adjustment to the velocity based on separation
            close_dx -= dx / distance;
            close_dy -= dy / distance;
        } 
    }

    vel[0] += close_dx * avoidfactor;
    vel[1] += close_dy * avoidfactor;
}

void Boid::alignment(vector<Boid>& boids)
{
    
}