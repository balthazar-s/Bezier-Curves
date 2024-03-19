#include <SFML/Graphics.hpp>
#include <vector> // For vector lists
#include "boids.hpp" // Boid class
using namespace std;

void simulation_avoid_edges(sf::RenderWindow& window, vector<Boid>& boids);

void simulation_wraparound(sf::RenderWindow& window, vector<Boid>& boids);