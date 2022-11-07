#pragma once
#include "based_cell.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

int id;
int x;
int y;
string type_ground;
int placed_block = 0;
sf::Texture texture;
sf::Sprite sprite;

based_cell::based_cell()
{

}
int get_id()
{
    return id;
}
int get_x()
{
    return x;
}
int get_y()
{
    return y;
}

void set_id(int iidd)
{
    id = iidd;
}
void set_x(int xx)
{
    x = xx;
}
void set_y(int yy)
{
    y = yy;
}

void draw_cell(sf::RenderWindow *window)
{
    if (!texture.loadFromFile("resources/grass.png"))
    {
        cout << "texture error" << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    window->draw(sprite);
}
