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
#include "ui.h"
#include "mouse_ui.h"
#include "based_cell.h"
#include "based_factory.h"
#include "coal_station.h"

using namespace std;
string *types_of_ground = new string[2];
const int xF = 15;
const int yF = 10;
int using_mouse_function;




int main()
{
    int picked_category;
    int picked_building;
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
    
    based_factory** factory_field = new based_factory*[xF];
    for (int i = 0; i < xF; i++) {
        factory_field[i] = new based_factory[yF];

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

            mouse_ui(localPosition, background_field, &picked_category, &picked_building, types_of_ground, factory_field);
        }
        window.clear();
        for (int x = 0; x < xF; x++)
        {
            for (int y = 0; y < yF; y++)
            {
                background_field[x][y].draw_cell(&window);
                if (factory_field[x][y].get_empty()) {
                    factory_field[x][y].draw_cell(&window);
                }
            }
        }
        
        ui_draw(&window, 100);

        window.display();
    }

    return 0;
}

