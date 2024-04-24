#include <SFML/Graphics.hpp> // Graphics library
#include <vector> // For vector lists
#include "../include/point.hpp" 
#include <random>
using namespace std;

int main()
{   
    // Window variables
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    Point point1({500, 500}, sf::Color::White, 0);
    Point point2({100, 100}, sf::Color::Green, 1);

    point1.init();
    point2.init();

    // Main process
    while (window.isOpen()) {
        // Exit window event
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            point1.drag_point(window);
            point2.drag_point(window);
        }

        window.clear();

        point1.draw_point(window);
        point2.draw_point(window);

        window.display();
    }

    return 0;
}
