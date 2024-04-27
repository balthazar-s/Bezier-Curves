#include <SFML/Graphics.hpp> // Graphics library
#include "../include/point.hpp" 
#include <random>
#include "../include/curve.hpp"
using namespace std;

int main()
{   
    // Window variables
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Bezier Curves", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    vector<Point> points;

    points.push_back(Point({300, 500}, sf::Color::White, 0));
    points.push_back(Point({500, 500}, sf::Color::White, 0));
    points.push_back(Point({700, 100}, sf::Color::Red, 1));
    points.push_back(Point({300, 200}, sf::Color::Red, 1));

    for (int i = 0, len = points.size(); i < len; i++)
    {
        points[i].init();
    }

    Curve curve({points[0].pos, points[1].pos}, {points[2].pos, points[3].pos});

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
            bool check = false;
            for (int i = 0, len = points.size(); i < len; i++)
            {
                if (!check)
                {
                    check = points[i].drag_point(window);
                }
            }
        }

        curve.update_curve(points);

        window.clear();

        curve.draw_curve(window);

        for (int i = 0, len = points.size(); i < len; i++)
        {
            window.draw(points[i].point_shape);
        }

        window.display();
    }

    return 0;
}
