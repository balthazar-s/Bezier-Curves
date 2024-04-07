#ifndef SETTINGS_HPP
#define SETTINGS_HPP

// Window settings
extern int WIDTH;
extern int HEIGHT;

// Define size of grid of Boids
extern int boids_cols;
extern int boids_rows;

// Speedcap
extern float maxspeed;
extern float minspeed;

// Separation
extern float avoidfactor;
extern float protected_range;

// Alignment and Cohesion
extern float visible_range;

// Alignment
extern float matching_factor;

// Cohesion
extern float centering_factor;

// Other settings
extern bool avoid_walls;
extern float turnfactor;
extern bool menu_dropdown;
extern int margin;


// Functions
void init_settings();

#endif // SETTINGS_HPP