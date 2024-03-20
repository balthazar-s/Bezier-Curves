#include <SFML/Graphics.hpp> // Graphics library
#include "../include/menu.hpp"
#include "../include/settings.hpp"


void Menu::init_menu_vars()
{
    font.loadFromFile("resources/fonts/Helvetica.ttf");

    // select the font
    menu_dropdown.setFont(font); // font is a sf::Font

    // set the string to display
    menu_dropdown.setString("Menu");

    // set the character size
    menu_dropdown.setCharacterSize(28); // in pixels, not points!

    // set the color
    menu_dropdown.setFillColor(sf::Color::Red);

    menu_dropdown.setPosition(WIDTH-100, 10);
}

void Menu::draw_menu_closed(sf::RenderWindow& window)
{
    window.draw(menu_dropdown);
}

void Menu::draw_menu_open(sf::RenderWindow& window)
{
    window.draw(menu_dropdown);
}
