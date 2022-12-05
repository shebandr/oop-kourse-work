#include "ui.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
using namespace std;

void ui_draw(sf::RenderWindow* window, int energy_eu) {
    sf::RectangleShape minimap(sf::Vector2f(160, 160));
    minimap.setFillColor(sf::Color(100, 100, 100));
    minimap.setPosition(0, 640);
    window->draw(minimap);
    sf::RectangleShape information(sf::Vector2f(400, 160));
    information.setFillColor(sf::Color(200, 200, 200));
    information.setPosition(160, 640);
    window->draw(information);
    sf::RectangleShape bt(sf::Vector2f(80, 160));
    bt.setFillColor(sf::Color(150, 150, 150));
    bt.setPosition(560, 640);
    window->draw(bt);
    sf::RectangleShape building(sf::Vector2f(320, 160));
    building.setFillColor(sf::Color(50, 50, 50));
    building.setPosition(640, 640);
    window->draw(building);
    for (int i = 640; i <= 800; i += 40) {
        sf::Vertex line[] =
        {
             sf::Vertex(sf::Vector2f(560, i), sf::Color::Black),
             sf::Vertex(sf::Vector2f(640, i), sf::Color::Black)
        };
        window->draw(line, 2, sf::Lines);
    }
    for (int i = 640; i <= 800; i += 80) {
        sf::Vertex line[] =
        {
             sf::Vertex(sf::Vector2f(640, i), sf::Color::Black),
             sf::Vertex(sf::Vector2f(960, i), sf::Color::Black)
        };
        window->draw(line, 2, sf::Lines);
    }
    for (int i = 560; i <= 640; i += 40) {
        sf::Vertex line[] =
        {
             sf::Vertex(sf::Vector2f(i, 640), sf::Color::Black),
             sf::Vertex(sf::Vector2f(i, 800), sf::Color::Black)
        };
        window->draw(line, 2, sf::Lines);
    }


    for (int i = 640; i <= 960; i += 80) {
        sf::Vertex line[] =
        {
             sf::Vertex(sf::Vector2f(i, 640), sf::Color::Black),
             sf::Vertex(sf::Vector2f(i, 800), sf::Color::Black)
        };
        window->draw(line, 2, sf::Lines);
    }
    sf::Font font;
    if (!font.loadFromFile("resources/PressStart2P-Regular.ttf"))
    {
        cout << "font error" << endl;
    }
    sf::Text energy;
    energy.setFont(font);

    energy.setString("Energy: "+ to_string(energy_eu));
    energy.setCharacterSize(20);
    energy.setFillColor(sf::Color::Black);
    energy.setPosition(165, 770);
    window->draw(energy);
}