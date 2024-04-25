#include <SFML/Graphics.hpp> // Graphics library
#include "../include/point.hpp" 
#include <random>
using namespace std;

void drawLine(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end, float thickness)
{
    // Calculate the line direction and length
    sf::Vector2f direction = end - start;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);

    // Calculate rotation of the rectangle
    float angle = atan2(direction.y, direction.x) * 180 / M_PI;

    // Create rectangle shape
    sf::RectangleShape line(sf::Vector2f(length, thickness));
    line.setOrigin(0, thickness / 2.0f);
    line.setPosition(start);
    line.setRotation(angle);
    
    // Draw the line
    window.draw(line);
}

int main()
{   
    // Window variables
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Boids", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    Point point1({500, 500}, sf::Color::White, 0);
    Point point2({100, 100}, sf::Color::Green, 1);

    vector<Point> points;

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
            bool check = point1.drag_point(window);
            check = point2.drag_point(window);
            points.push_back(Point({float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)}, sf::Color::Red, 1));
        }

        window.clear();

        drawLine(window, point1.pos, point2.pos, 2);

        for (int i = 0, len = points.size(); i < len; i++)
        {
            window.draw(points[i].point_shape);
        }

        window.display();
    }

    return 0;
}
