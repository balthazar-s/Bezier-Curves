#include <SFML/Graphics.hpp> // Graphics library

#ifndef MENU_HPP
#define MENU_HPP

// Menu functions
class Menu {
    public:
        sf::Font font;
        sf::Text menu_dropdown;

        void init_menu_vars();
        void draw_menu_closed(sf::RenderWindow& window);
        void draw_menu_open(sf::RenderWindow& window);
};

#endif // MENU_HPP