////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "based_cell.h"

using namespace std;
string types_of_ground[2];
const int xF = 15;
const int yF = 10;
int using_mouse_function;
int picked_category;
int picked_building;

void mouse_click(sf::Vector2i localPosition, based_cell** background_field) {
    
    int x = localPosition.x;
    int y = localPosition.y;
    if (y <= 640) {
        int x_cell = x / 64;
        int y_cell = y / 64;
        background_field[x_cell][y_cell].set_ground(types_of_ground[1]);
    }
    else {
        if (y < 800){

            if (x > 560 && x < 640) { // выбор категории построек

                if (x <= 600) {
                    picked_category = ((y - 640) / 40);
                }
                else {
                    picked_category = ((y - 640) / 40) + 4;
                }

            }
            else {
                if (x > 640 && x < 960) { // выбор постройки

                }
            }
        }
    }
}

void ui_draw(sf::RenderWindow* window) {
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
    
    
    for (int i = 640; i <= 960; i += 40) {
        sf::Vertex line[] =
        {
             sf::Vertex(sf::Vector2f(i, 640), sf::Color::Black),
             sf::Vertex(sf::Vector2f(i, 800), sf::Color::Black)
        };
        window->draw(line, 2, sf::Lines);
    }
}

int main()
{
    types_of_ground[0] = "resources/grass.png";
    types_of_ground[1] = "resources/coal_power_plant.png";
    sf::RenderWindow window(sf::VideoMode(960, 800), "SFML works!");
    based_cell **background_field = new based_cell *[xF];
    for (int i = 0; i < xF; i++) {
        background_field[i] = new based_cell[yF];
    }
    int id = 0;
    for (int x = 0; x < xF; x++)
    {
        for (int y = 0; y < yF; y++)
        {
            background_field[x][y].set_id(id);
            id++;
            background_field[x][y].set_x(x * 64);
            background_field[x][y].set_y(y * 64);
            background_field[x][y].set_ground(types_of_ground[0]);
        }
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);

            mouse_click(localPosition, background_field);
            cout << picked_category << endl;
        }
        window.clear();
        for (int x = 0; x < xF; x++)
        {
            for (int y = 0; y < yF; y++)
            {
                background_field[x][y].draw_cell(&window);
            }
        }
        ui_draw(&window);

        window.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
