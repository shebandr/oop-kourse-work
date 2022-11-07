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

int main()
{
    types_of_ground[0] = "resources/grass.png";
    types_of_ground[1] = "resources/coal_power_plant.png";
    sf::RenderWindow window(sf::VideoMode(960, 640), "SFML works!");
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

        window.clear();
        for (int x = 0; x < xF; x++)
        {
            for (int y = 0; y < yF; y++)
            {
                background_field[x][y].draw_cell(&window);
            }
        }

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
