#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../include/curve.hpp"
using namespace std;

unsigned int fact(unsigned int n) 
{
    if (n == 0)
       return 1;
    return n * fact(n - 1);
}


void draw_line_curve(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end, float width)
{
    // Calculate the line direction and length
    sf::Vector2f direction = end - start;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);

    // Calculate rotation of the rectangle
    float angle = atan2(direction.y, direction.x) * 180 / M_PI;

    // Create rectangle shape
    sf::RectangleShape line(sf::Vector2f(length, width));
    line.setOrigin(0, width / 2.0f);
    line.setPosition(start);
    line.setRotation(angle);
    line.setFillColor(sf::Color::White);
    
    // Draw the line
    window.draw(line);
}

void Curve::update_curve(vector<Point> points_input)
{
    points.clear();
    for (int i = 0, len = points_input.size(); i < len; i++)
    {
        points.push_back(points_input[i].pos);
    }
    
    curve_points.clear();
    for (int j = 0; j < (resolution+1); j++)
    {
        float t = (1.0 / resolution) * j;
        float x = 0.0;
        float y = 0.0;
        for (int i = 0, n = points.size(); i < n; i++)
        {
            x += float(points[i].x * (fact(n-1) / (fact(i) * fact(n-1-i))) * pow(t, i) * pow(1 - t, n - 1 - i));
            
            y += float(points[i].y * (fact(n-1) / (fact(i) * fact(n-1-i))) * pow(t, i) * pow(1 - t, n - 1 - i));
        }
        
        curve_points.push_back(sf::Vector2f(x, y));
    }
}

void Curve::draw_curve(sf::RenderWindow& window)
{
    for (int i = 0, len = curve_points.size(); i < len; i++)
    {
        if (i < len -1)
        {
            draw_line_curve(window, curve_points[i], curve_points[i+1], 2);
        }
    }
}
