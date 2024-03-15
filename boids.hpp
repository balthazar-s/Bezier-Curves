#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Boid {
  public:
    // Public variables
    vector<int> pos;
    vector<int> vel;
    sf::CircleShape boid_shape;

    // Constructor to initialize pos and vel
    Boid(const vector<int> position, const vector<int> velocity) : pos(position), vel(velocity) {};

    // Public functions
    void initialise();

    void draw_boid(sf::RenderWindow& window);

    void update_pos();
};