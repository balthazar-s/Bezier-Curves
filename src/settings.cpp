#include "../include/settings.hpp"

// Define variables

// Window size
int WIDTH;
int HEIGHT;

// Size of grid of Boids
int boids_cols;
int boids_rows;

// Maximum and minimum speed
float maxspeed;
float minspeed;

// Separation
float avoidfactor;
float protected_range;

// Alignment and Cohesion
float visible_range;
float matching_factor;
float centering_factor;

// Other settings
bool avoid_walls;
float turnfactor;
bool menu_dropdown;
int margin;

// Initialize settings at proper values
void init_settings()
{ 
    WIDTH = 1000;
    HEIGHT = 1000;

    boids_cols = 20;
    boids_rows = 20;

    maxspeed = 3;
    minspeed = 1.5;

    avoidfactor = 0.06;
    protected_range = 12;

    visible_range = 32;

    matching_factor = 0.0075;

    centering_factor = 0.001;

    avoid_walls = false;
    turnfactor = 0.1;
    menu_dropdown = false;
    margin = 100;
}
