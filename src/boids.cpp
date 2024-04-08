#include <vector> 
#include <math.h>
#include <algorithm>
#include "../include/boids.hpp"
#include "../include/settings.hpp"
using namespace std;

void Boid::initialise()
{
    // Create triangle for boid object
    boid_shape.setPointCount(3);
    boid_shape.setFillColor(sf::Color(0, 255, 0));
    boid_shape.setPoint(0, sf::Vector2f(0, 5)); // Top point
    boid_shape.setPoint(1, sf::Vector2f(-3, -5)); // Bottom left point
    boid_shape.setPoint(2, sf::Vector2f(3, -5)); // Bottom right point
}

void Boid::draw_boid(sf::RenderWindow& window) 
{
    // Draw boid shape with SFML
    window.draw(boid_shape);
}

void Boid::update_pos(int WIDTH, int HEIGHT) // Boids wrap around borders
{
    // Update position based on velocity
    pos[0] += vel[0]; 
    pos[1] += vel[1];

    // Wrap around borders
    if (pos[0] > WIDTH + 10)
    {
        pos[0] = -10.0;
    }
    else if (pos[1] > HEIGHT + 10)
    {
        pos[1] = -10.0;
    }
    else if (pos[0] < -10)
    {
        pos[0] = WIDTH + 10;
    }
    else if (pos[1] < -10)
    {
        pos[1] = HEIGHT + 10;
    }

    // Set position of the boid shape based on position
    boid_shape.setPosition(pos[0], pos[1]);

    // Calculate angle boid is facing based on velocity
    if (vel[0] != 0 || vel[1] != 0) 
    {
        angle = (atan2(vel[1], vel[0]) * 180 / M_PI) - 90;
    }
    else
    {
        angle = 0; 
    }

    // Set angle of the boid shape based on angle calculated before
    boid_shape.setRotation(angle);
}

void Boid::update_pos_avoidwalls(int WIDTH, int HEIGHT) // Boids avoid walls
{
    // Update position based on velocity
    pos[0] += vel[0]; 
    pos[1] += vel[1];

    // Avoid walls

    // Check if the boid hits the right or left margin
    if (pos[0] > WIDTH - margin)
    {
        vel[0] -= turnfactor;    
    }
    else if (pos[0] < margin)
    {
        vel[0] += turnfactor;    
    }
    // Check if the boid hits the bottom or top margin
    if (pos[1] > HEIGHT - margin)
    {
        vel[1] -= turnfactor;       
    }
    else if (pos[1] < margin)
    {
        vel[1] += turnfactor;       
    }

    // Set position of the boid shape based on position
    boid_shape.setPosition(pos[0], pos[1]);

    // Calculate angle boid is facing based on velocity
    if (vel[0] != 0 || vel[1] != 0) 
    {
        angle = (atan2(vel[1], vel[0]) * 180 / M_PI) - 90;
    }
    else
    {
        angle = 0; 
    }

    // Set angle of the boid shape based on angle calculated before
    boid_shape.setRotation(angle);
}

void Boid::speed_cap()
{
    // Calculated current speed based on velocity vector
    float speed = sqrt(vel[0] * vel[0] + vel[1] * vel[1]);

    if (speed > maxspeed) // Clamp to maximum speed
    {
        vel[0] = (vel[0] / speed) * maxspeed;
        vel[1] = (vel[1] / speed) * maxspeed;
    }
    else if (speed < minspeed) // Clamp to minimum speed
    {
        vel[0] = (vel[0] / speed) * minspeed;
        vel[1] = (vel[1] / speed) * minspeed;
    }
}

void Boid::separation(vector<Boid>& boids)
{   
    // Init values for repulsion forces
    float close_dx = 0.0;
    float close_dy = 0.0;

    // Iterate over each boid in vector
    for (int i = 0, len = boids.size(); i < len; i++)
    {
        // Calculate the distance between the iterated boid and the current boid object
        float dx = pos[0] - boids[i].pos[0];
        float dy = pos[1] - boids[i].pos[1];
        float distance = sqrt(dx * dx + dy * dy);

        // If the iterated boid is within the protected range and is not the current boid object
        if (distance <= protected_range && distance > 0)
        {
            // Scaling value (stronger repulsion if boids are closer)
            float inv_distance = 1.0 / distance;
            
            // Scale the repulsion force using the inverse distance
            close_dx += dx * inv_distance;
            close_dy += dy * inv_distance;
        } 
    }

    // Update velocities based on repulsion force
    vel[0] += close_dx * avoidfactor;
    vel[1] += close_dy * avoidfactor;
}


void Boid::alignment_and_cohesion(vector<Boid>& boids)
{
    // Initialise averages for velocities and positions of neighboring boids, as well as the total number of neighbors
    float xvel_avg = 0.0;
    float yvel_avg = 0.0;
    float xpos_avg = 0.0;
    float ypos_avg = 0.0;
    int neighboring_boids = 0;

    // Iterate over each boid in vector
    for (int i = 0, len = boids.size(); i < len; i++)
    {
        // Calculate the distance between this boid and the current boid
        float dx = boids[i].pos[0] - pos[0];
        float dy = boids[i].pos[1] - pos[1];
        float distance = sqrt(dx * dx + dy * dy);

        // If the iterated boid is within the visible range and is not the current boid object
        if (distance <= visible_range && distance > 0)
        {
            // Add the iterated boid's velocity to the velocity averages
            xvel_avg += boids[i].vel[0];
            yvel_avg += boids[i].vel[1];
            // Add the iterated boid's position to the position averages
            xpos_avg += boids[i].pos[0];
            ypos_avg += boids[i].pos[1];
            // Add one to the number of neighboring boids
            neighboring_boids += 1;
        }
    }    
    // If there are valid neighboring boids
    if (neighboring_boids > 0)
    {
        // Finalise average calculation for the velocities of the neighboring boids
        xvel_avg /= float(neighboring_boids);
        yvel_avg /= float(neighboring_boids);

        // Update the current boid's velocity based on the average, its current velocity, and the matching factor
        vel[0] += (xvel_avg - vel[0]) * matching_factor;
        vel[1] += (yvel_avg - vel[1]) * matching_factor;  

        // Finalise average calculation for the positions of the neighboring boids
        xpos_avg /= float(neighboring_boids);
        ypos_avg /= float(neighboring_boids);

        // Update the current boid's velocity based on the average, its current position, and the centering factor
        vel[0] += (xpos_avg - pos[0]) * centering_factor;
        vel[1] += (ypos_avg - pos[1]) * centering_factor;  
    }

    // Color gradient

    // Calculate color level based on number of boids in neighborhood of current boid object
    int color_level = round(neighboring_boids * 255 / 10);

    // Initialise seperate color values
    int red, green, blue;
    
    if (color_level > 255) // Yellow to red
    {
        red = 255;
        green = 255 - (color_level - 255);
        blue = 0;
    }
    else // Blue to yellow
    {
        red = color_level;
        green = color_level;
        blue = 255 - color_level;
    }
    
    // Change current color with rgb values
    boid_shape.setFillColor(sf::Color(red, green, blue));
}