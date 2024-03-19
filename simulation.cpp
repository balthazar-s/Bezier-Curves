#include <SFML/Graphics.hpp>
#include <vector> // For vector lists

using namespace std;

void simulation_avoid_edges(sf::RenderWindow& window, vector<Boid>& boids)
{
    // Simulation variables
    const int SIMULATION_FPS = 60;
    const sf::Time SIMULATION_TIME_PER_FRAME = sf::seconds(1.0f / SIMULATION_FPS);
    sf::Clock simulationClock;
    sf::Time elapsedTimeSinceLastUpdate = sf::Time::Zero;

            // Simulate fixed time steps
        elapsedTimeSinceLastUpdate += simulationClock.restart();
        while (elapsedTimeSinceLastUpdate >= SIMULATION_TIME_PER_FRAME) {
            // Update simulation
            for (int i = 0, len = boids.size(); i < len; i++) {
                boids[i].update_pos_avoid(WIDTH, HEIGHT);
                boids[i].separation(boids);
                boids[i].alignment(boids);
                boids[i].cohesion(boids);
                boids[i].speed_cap();
            }
            elapsedTimeSinceLastUpdate -= SIMULATION_TIME_PER_FRAME;
        }

        window.clear();

        // Draw all Boids
        for (int i = 0, len = boids.size(); i < len; i++) {
            boids[i].draw_boid(window);
        }
        
        window.display();
}

void simulation_wraparound(sf::RenderWindow& window, vector<Boid>& boids)
{
    // Simulation variables
    const int SIMULATION_FPS = 60;
    const sf::Time SIMULATION_TIME_PER_FRAME = sf::seconds(1.0f / SIMULATION_FPS);
    sf::Clock simulationClock;
    sf::Time elapsedTimeSinceLastUpdate = sf::Time::Zero;

        // Simulate fixed time steps
        elapsedTimeSinceLastUpdate += simulationClock.restart();
        while (elapsedTimeSinceLastUpdate >= SIMULATION_TIME_PER_FRAME) {
            // Update simulation
            for (int i = 0, len = boids.size(); i < len; i++) {
                boids[i].update_pos_wraparound(WIDTH, HEIGHT);
                boids[i].separation(boids);
                boids[i].alignment(boids);
                boids[i].cohesion(boids);
                boids[i].speed_cap();
            }
            elapsedTimeSinceLastUpdate -= SIMULATION_TIME_PER_FRAME;
        }

        window.clear();

        // Draw all Boids
        for (int i = 0, len = boids.size(); i < len; i++) {
            boids[i].draw_boid(window);
        }
        
        window.display();
}
}