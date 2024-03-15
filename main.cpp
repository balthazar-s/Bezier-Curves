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

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {   
            // Grid for coordinates
            int cord_x = (WIDTH/6)*(j+1);
            int cord_y = (HEIGHT/6)*(i+1);

            // Random velocities
            int vel_x = (rand() % 300 + 100) / 100;
            int vel_y = (rand() % 300 + 100) / 100;

            // Randomly assign velocities positive or negative signs
            if (rand() % 2 == 0) {
                vel_x = -vel_x; 
            }
            if (rand() % 2 == 0) {
                vel_y = -vel_y; 
}
            // Create vectors to be used in boid creation
            vector<int> position = {cord_x, cord_y};
            vector<int> velocity = {vel_x, vel_y};

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
        for (int i = 0; i < 25; i++)
        {
            boids[i].update_pos(WIDTH, HEIGHT);
            boids[i].draw_boid(window);
            boids[i].separation(boids);
        }
        
        window.display();
    }

    return 0;
}