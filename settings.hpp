#ifndef SETTINGS_HPP
#define SETTINGS_HPP

// Window settings
extern int WIDTH;
extern int HEIGHT;

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


// Functions
void init_settings();

void change_avoid_walls();

void change_factor(int factor_index, float change);

void change_range(int range_index, float change);

void change_speed_range(int index, float change);

#endif // SETTINGS_HPP