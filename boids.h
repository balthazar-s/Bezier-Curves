#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Boid {
  public:
    // Public variables
    vector<int> pos;
    vector<int> vec;
    sf::CircleShape boid_shape(4.f);
    Boid::boid_shape.setFillColor(sf::Color::Green);

    // Public functions
    void draw();

    void update_pos();
};