#include <SFML/Graphics.hpp> // Graphics library
#include "boids.hpp" // Boid class
#include "simulation.hpp" // Simulation definitions
#include "settings.hpp" // Settings
#include "menu.hpp"
#include <vector> // For vector lists
#include <cstdlib> // For Random number generation
#include <random>
using namespace std;

// Declare functions
vector<Boid> create_boids(int cols, int rows, int WIDTH, int HEIGHT);

int main()
{
    // Window variables
    const int HEIGHT = 1000;
    const int WIDTH = 1000;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // Adjust the antialiasing level as needed
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);

    // Define number of boids
    int cols = 10;
    int rows = 10;

    // Init settings
    init_settings();

    // Create all Boids
    vector<Boid> boids = create_boids(cols, rows, WIDTH, HEIGHT);
      
    // Simulation variables
    const int SIMULATION_FPS = 60;
    const sf::Time SIMULATION_TIME_PER_FRAME = sf::seconds(1.0f / SIMULATION_FPS);
    sf::Clock simulationClock;
    sf::Time elapsedTimeSinceLastUpdate = sf::Time::Zero;

    // Main process
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Simulate fixed time steps
        elapsedTimeSinceLastUpdate += simulationClock.restart();
        while (elapsedTimeSinceLastUpdate >= SIMULATION_TIME_PER_FRAME) {
            // Update simulation
            for (int i = 0, len = boids.size(); i < len; i++) {
                boids[i].update_pos_wraparound(WIDTH, HEIGHT);
                boids[i].separation(boids);
                boids[i].alignment(boids);
                boids[i].cohesion(boids);
                boids[i].speed_cap();
            }
            elapsedTimeSinceLastUpdate -= SIMULATION_TIME_PER_FRAME;
        }

        window.clear();

        // Draw all Boids
        for (int i = 0, len = boids.size(); i < len; i++) {
            boids[i].draw_boid(window);
        }
        
        window.display();
    }

    return 0;
}

vector<Boid> create_boids(int cols, int rows, int WIDTH, int HEIGHT) // Returns list of boids assigned coordinates and random velocities
{
    // Random seed
    srand((unsigned) time(NULL));

    // Define a random number generator engine
    random_device rd;
    mt19937 gen(rd());  

    vector<Boid> create_boids_boids;

    for (int i = 0; i < rows; i++) // Iterate through rows (x-coordinate)
    {
        for (int j = 0; j < cols; j++) // Iterate through columns (y-coordinate)
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
            create_boids_boids.push_back(Boid(position, velocity));
            
            // Init all values of newest Boid
            create_boids_boids.back().initialise();
        }
    }

    return create_boids_boids;
}