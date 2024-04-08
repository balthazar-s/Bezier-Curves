#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

#ifndef BOIDS_HPP
#define BOIDS_HPP

class Boid {
  public:
    // Public variables
    
    vector<float> pos; // Position
    vector<float> vel; // Velocity
    int angle; // Angle
    sf::ConvexShape boid_shape; // Triangle for boid shape

    // Constructor to initialize position and velocity
    Boid(const vector<float> position, const vector<float> velocity) : pos(position), vel(velocity) {};

    // Public functions

    void initialise(); // Initialise boid object

    void draw_boid(sf::RenderWindow& window); // Draw boid shape onto window

    void update_pos(int WIDTH, int HEIGHT); // Update position, wrap around borders

    void update_pos_avoidwalls(int WIDTH, int HEIGHT); // Update position, avoid walls

    void separation(vector<Boid>& boids); // Avoid other boids

    void alignment_and_cohesion(vector<Boid>& boids); // Steer towards average heading of neighbors and towards their center of mass

    void speed_cap(); // Clamp speed to upper and lower bounds
};

#endif