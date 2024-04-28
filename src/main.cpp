#include <SFML/Graphics.hpp> // Graphics library
#include "../include/point.hpp" 
#include <random>
#include "../include/curve.hpp"
#include <string>
using namespace std;

// Type for menu button
struct Menu_Button {
    sf::RectangleShape shape;
    sf::Text text;
    bool selected;

    Menu_Button(const sf::RectangleShape& shape, sf::Text text, bool selected) : shape(shape), text(text), selected(selected) {}
};

// Main process
int main()
{   
    // Window variables
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Bezier Curves", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);

    // Default font for button text
    sf::Font default_font;
    if (!default_font.loadFromFile("assets/arial.ttf"))
    {
        return 1;
    }

    // Vector of seperate buttons
    vector<Menu_Button> menu_buttons;

    // Temporary vector of button texts
    vector<string> menu_text = {"Move", "Create", "Delete", "Hidden"};

    // Init all 4 buttons
    for (int i = 0; i < 4; i++)
    {
        menu_buttons.push_back(Menu_Button(sf::RectangleShape(sf::Vector2f(230, 40)), sf::Text(menu_text[i], default_font, 40), false));
        menu_buttons.back().shape.setPosition(sf::Vector2f(10 + i*250, 10));
        menu_buttons.back().shape.setFillColor(sf::Color::Black);
        menu_buttons.back().shape.setOutlineThickness(2);
        menu_buttons.back().shape.setOutlineColor(sf::Color::White);
        menu_buttons.back().text.setFillColor(sf::Color::White);
        menu_buttons.back().text.setPosition(15 + i*250, 3.5);
    }

    // Set button 1 as active
    menu_buttons[0].shape.setFillColor(sf::Color(100, 100, 100));
    menu_buttons[0].selected = true;

    // Set setting 1 as active
    int selection_settings = 0;

    // List of all points in scene
    vector<Point> points;

    // Default points, 0 is anchor, 1 is control
    points.push_back(Point({200, 500}, sf::Color::Red, 0));
    points.push_back(Point({500, 200}, sf::Color::Black, 1));
    points.push_back(Point({500, 800}, sf::Color::Black, 1));
    points.push_back(Point({800, 500}, sf::Color::Red, 0));

    // Init all buttons
    for (int i = 0, len = points.size(); i < len; i++)
    {
        points[i].init();
    }

    // Extract only sf::Vector2f locations from points
    vector<sf::Vector2f> locations;
    for (int i = 0, len = points.size(); i < len; i++)
    {
        locations.push_back(points[i].pos);
    }

    // Create curve object with locations above
    Curve curve(locations);

    // Main window process
    while (window.isOpen()) {
        // Exit window event
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Menu click event
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for (int i = 0; i < 4; i++)
            {   
                // Update selected menu button
                if (menu_buttons[i].shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
                {
                    menu_buttons[i].selected = true;
                    selection_settings = i;

                    for (int j = 0; j < 4; j++)
                    {
                        if (i != j)
                        {
                            menu_buttons[j].selected = false;
                        }
                    }
                }

                // Change colors to match selected menu button
                if (menu_buttons[i].selected)
                {
                    menu_buttons[i].shape.setFillColor(sf::Color(100, 100, 100));
                }
                else 
                {
                    menu_buttons[i].shape.setFillColor(sf::Color::Black);
                }
            }
        }  

        // Move/Create/Delete point events
        bool check = false;
        switch (selection_settings)
        {
        case 0: // move only
            // If mouse click left
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
            {
                // Get current mouse position
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int len = points.size();
                for (int i = 0; i < len; i++) 
                {
                    // If mouse is over this point
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
                for (int i = 0; i < len; i++) 
                {
                    if (points[i].selected)
                    {
                        check = true;
                    }
                }
            } else {
                // Release all points when mouse button is up
                for (int i = 0; i < points.size(); i++) 
                {
                    points[i].selected = false;
                }
            }
            break;

        case 1: // create
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int len = points.size();
                for (int i = 0; i < len; i++) 
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
                for (int i = 0; i < len; i++) 
                {
                    if (points[i].selected)
                    {
                        check = true;
                    }
                }
                if (!check)
                {   
                    if (mousePos.y > 50)
                    {
                        int len = points.size() - 1;
                        Point new_point({float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y)}, sf::Color::Black, 1);
                        points.insert(points.end() - 1, new_point);
                        
                        points[len].init();
                        points[len].selected = true;
                    }
                }
            } else {
                // Release all points when mouse button is up
                for (int i = 0; i < points.size(); i++) 
                {
                    points[i].selected = false;
                }
            }
            break;

        case 2: // Delete
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int len = points.size();
                for (int i = 0; i < len; i++) 
                {
                    if (points[i].point_shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
                    {
                        vector<Point>::iterator it = ( points.begin() + i);
                        points.erase(it);
                    }
                }
            }
            break;  
        
        case 3: // Hide points
            break;  
        }
        

        // Update dragged points
        for (int i = 0; i < points.size(); ++i) {
            if (points[i].selected) 
            {
                points[i].drag_point(window);
            }
        }
        
        // Update curve w/ updated point positions
        curve.update_curve(points);

        // Clear window
        window.clear();

        // Draw curve first
        curve.draw_curve(window);

        // Draw points if setting is not 3
        if (selection_settings != 3)
        {
            for (int i = 0, len = points.size(); i < len; i++)
            {
                window.draw(points[i].point_shape);
            }
        }

        // Draw menu boxes & text
        for (int i = 0; i < 4; i++)
        {
            window.draw(menu_buttons[i].shape);
            window.draw(menu_buttons[i].text);
        }
        
        // Display everything
        window.display();
    }

    return 0;
}
