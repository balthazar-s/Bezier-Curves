#include <SFML/Graphics.hpp> // Graphics library
#include "boids.hpp" // Boid class
#include <vector> // For vector lists
#include <cstdlib> // For Random number generation
#include <ctime>   // For time (random seed)
using namespace std;

int main()
{
    // Window variables
    const int HEIGHT = 1000;
    const int WIDTH = 1000;

    // Anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // Adjust the antialiasing level as needed

    // Create window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    srand(time(nullptr));

    // Create all Boids
    vector<Boid> boids;

    // Define number of boids
    int cols = 10;
    int rows = 10;

    // Velocity ranges
    float min = -10.0f;
    float max = 10.0f; 

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            // Grid for coordinates
            float cord_x = (WIDTH/(cols+1))*(j+1);
            float cord_y = (HEIGHT/(rows+1))*(i+1);

            // Random velocities
            float vel_x = min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max - min)));
            float vel_y = min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (max - min)));

            // Create vectors to be used in boid creation
            vector<float> position = {cord_x, cord_y};
            vector<float> velocity = {vel_x, vel_y};

            // Create new Boid object at end of boids list
            boids.push_back(Boid(position, velocity));
            
            // Init all values of newest Boid
            boids.back().initialise();
        }
    }
    
    // Main process
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw and update all Boids
        for (int i = 0, len = boids.size(); i < len; i++)
        {
            boids[i].update_pos(WIDTH, HEIGHT);
            boids[i].draw_boid(window);
            boids[i].separation(boids);
            boids[i].alignment(boids);
            boids[i].cohesion(boids);
            boids[i].speed_cap();
        }
        
        window.display();
    }

    return 0;
}