#include <SFML/Graphics.hpp>
#include "boids.hpp"
#include <vector> 
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Boids");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    vector<Boid> boids;
        
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {   
            vector<int> position = {0, 0};
            vector<int> velocity = {1, 1};
            boids.push_back(Boid(position, velocity));
            boids[i].initialise();
        }
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < 25; i++)
        {
            
            boids[i].draw_boid(window);
        }
        
        window.display();
    }

    return 0;
}