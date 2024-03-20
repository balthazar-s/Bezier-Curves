#include "../include/settings.hpp"

// Define variables
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
bool menu_dropdown;

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
    menu_dropdown = false;
}
