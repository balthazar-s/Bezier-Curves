#include <SFML/Graphics.hpp> // Graphics library
#include "boids.hpp" // Boid class
#include "simulation.hpp" // Simulation definitions
#include "settings.hpp"
#include <vector> // For vector lists
#include <cstdlib> // For Random number generation
#include <random>
using namespace std;

int main()
{
    HEIGHT = 1000;
    WIDTH = 1000;

    init_settings();

    // Window variables
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // Adjust the antialiasing level as needed
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);

    srand((unsigned) time(NULL));

    // Create all Boids
    vector<Boid> boids;

    // Define number of boids
    int cols = 10;
    int rows = 10;

    // Define a random number generator engine
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            // Grid for coordinates
            float cord_x = (WIDTH/(cols+1))*(j+1);
            float cord_y = (HEIGHT/(rows+1))*(i+1);

            // Random velocities
            uniform_real_distribution<float> vel_dis(minspeed, maxspeed);
            float vel_x = vel_dis(gen);
            float vel_y = vel_dis(gen);

            // Randomize sign of velocities
            uniform_int_distribution<int> sign_dis(0, 1);
            bool positive = sign_dis(gen);
            if (positive == true) 
            {
                vel_x = -vel_x;
            }
            positive = sign_dis(gen);
            if (positive == true) 
            {
                vel_y = -vel_y;
            }

            // Create vectors to be used in boid creation
            vector<float> position = {cord_x, cord_y};
            vector<float> velocity = {vel_x, vel_y};

            // Create new Boid object at end of boids list
            boids.push_back(Boid(position, velocity));
            
            // Init all values of newest Boid
            boids.back().initialise();
        }
    }
    
    if (avoid_walls == false) // Boids will wrap around edges
    {
        simulation_wraparound(window, boids);
    }
    else // Boids will avoid walls
    {
        simulation_avoid_walls(window, boids);
    }

    return 0;
}