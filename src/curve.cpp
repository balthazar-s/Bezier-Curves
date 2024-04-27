#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../include/curve.hpp"
using namespace std;

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

void Curve::update_curve(vector<Point> points)
{
    anchors = {points[0].pos, points[1].pos};
    control = {points[2].pos, points[3].pos};
    
    curve_points.clear();
    for (int i = 0; i < (resolution+1); i++)
    {
        float p = (1.0 / resolution) * i;
        float x = pow(1 - p, 3) * anchors[0].x + 3*pow(1 - p, 2)*p*control[0].x + 3*(1 - p)*pow(p, 2)*control[1].x + pow(p, 3)*anchors[1].x;
        float y = pow(1 - p, 3) * anchors[0].y + 3*pow(1 - p, 2)*p*control[0].y + 3*(1 - p)*pow(p, 2)*control[1].y + pow(p, 3)*anchors[1].y;
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
