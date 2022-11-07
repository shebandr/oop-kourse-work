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
    virtual virtual int get_id();
    virtual virtual int get_x();
    virtual virtual int get_y();
    virtual virtual void set_id(int iidd);
    virtual virtual void set_x(int xx);
    virtual virtual void set_y(int yy);
    virtual virtual void draw_cell(sf::RenderWindow *window);
};
