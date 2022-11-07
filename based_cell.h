#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class based_cell
{
  protected:
    int id;
    int x;
    int y;
    sf::Texture texture;
    sf::Sprite sprite;

  public:
    based_cell();
    int get_id();
    int get_x();
    int get_y();
    void set_id(int iidd);
    void set_x(int xx);
    void set_y(int yy);
    void draw_cell(sf::RenderWindow *window);
};
