#include <SFML/Graphics.hpp>
#include "boids.hpp"
#include <vector> 
#include <cstdlib> 
using namespace std;

int main()
{
    // Window variables
    const int HEIGHT = 1000;
    const int WIDTH = 1000;

    // Anti-aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4; // Adjust the antialiasing level as needed

    // Create window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    // Create all Boids
    vector<Boid> boids;



    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {   
            int cord_x = (WIDTH/6)*(j+1);
            int cord_y = (HEIGHT/6)*(i+1);

            vector<int> position = {cord_x, cord_y};
            vector<int> velocity = {0, 1};

            boids.push_back(Boid(position, velocity));
            
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
            boids[i].update_pos();
            boids[i].draw_boid(window);
        }
        
        window.display();
    }

    return 0;
}