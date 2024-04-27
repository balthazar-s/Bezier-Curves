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
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Bezier Curves", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    vector<Point> points;

    points.push_back(Point({200, 500}, sf::Color::Red, 0));
    points.push_back(Point({500, 200}, sf::Color::Black, 1));
    points.push_back(Point({500, 800}, sf::Color::Black, 1));
    points.push_back(Point({800, 500}, sf::Color::Red, 0));




    for (int i = 0, len = points.size(); i < len; i++)
    {
        points[i].init();
    }

    vector<sf::Vector2f> locations;
    for (int i = 0, len = points.size(); i < len; i++)
    {
        locations.push_back(points[i].pos);
    }

    Curve curve(locations);

    // Main process
    while (window.isOpen()) {
        // Exit window event
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bool check = false;
        // Check for mouse clicks
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            int len = points.size();
            for (int i = 0; i < len; ++i) 
            {
                if (points[i].point_shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
                {
                    bool temp = false;
                    for (int j = 0; j < len; j++)
                    {
                        if (points[j].selected)
                        {
                            temp = true;
                        }
                    }
                    if (!temp)
                    {
                        points[i].selected = true;
                        check = true;
                    }
                }
            }
            for (int i = 0; i < len; ++i) 
            {
                if (points[i].selected)
                {
                    check = true;
                }
            }
            if (!check)
            {   
                int len = points.size() - 1;
                Point new_point({float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)}, sf::Color::Black, 1);
                points.insert(points.end() - 1, new_point);
                
                points[len].init();
                points[len].selected = true;
            }
        } else {
            // Release all points when mouse button is up
            for (int i = 0; i < points.size(); ++i) 
            {
                points[i].selected = false;
            }
        }

        // Update dragged points
        for (int i = 0; i < points.size(); ++i) {
            if (points[i].selected) 
            {
                points[i].drag_point(window);
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
