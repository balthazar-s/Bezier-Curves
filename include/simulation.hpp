#include <SFML/Graphics.hpp>
#include <vector> // For vector lists
#include "boids.hpp" // Boid class
#include "menu.hpp"
using namespace std;

void simulation_avoid_walls(sf::RenderWindow& window, vector<Boid>& boids);

void simulation_wraparound(sf::RenderWindow& window, vector<Boid>& boids);

void draw_menu_logic(Menu &menu_instance, sf::RenderWindow& window);