#include "settings.hpp"

// Define the variables
int WIDTH;
int HEIGHT;

float maxspeed;
float minspeed;

float avoidfactor;
float protected_range;

float visible_range;

float matching_factor;

float centering_factor;

bool avoid_walls;
float turnfactor;

// Initialize settings at proper values
void init_settings()
{ 
    // Speedcap
    maxspeed = 12;
    minspeed = 2;

    // Separation
    avoidfactor = 0.1;
    protected_range = 25;

    // Alignment and Cohesion
    visible_range = 64;

    // Alignment
    matching_factor = 0.00005;

    // Cohesion
    centering_factor = 0.0005;

    // Other settings
    avoid_walls = false;
    turnfactor = 0.2;
}


// Other Functions
void change_avoid_walls()
{
    if (avoid_walls == false)
    {
        avoid_walls = true;
    }
    else
    {
        avoid_walls = false;
    }
}

void change_factor(int factor_index, float change)
{
    switch (factor_index)
    {
    case 0: // Avoidfactor
        avoidfactor += change;
        break;
    case 1: // Matchfactor
        matching_factor += change;
        break;
    case 2: // Centeringfactor
        centering_factor += change;
        break;
    case 3: // Turnfactor
        turnfactor += change;
        break;
    }
}

void change_range(int range_index, float change)
{
    switch (range_index)
    {
    case 0: // Protected Range
        protected_range += change;
        break;
    case 1: // Visible range
        visible_range += change;
        break;
    }
}

void change_speed_range(int speed_index, float change)
{
    switch (speed_index)
    {
    case 0: // Maxspeed
        maxspeed += change;
        break;
    case 1: // Minspeed
        minspeed += change;
        break;
    }
}