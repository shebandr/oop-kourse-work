#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class based_cell
{
  protected:
    int id;
    int x;
    int y;
    std::string type_ground;
    sf::Texture texture;
    sf::Sprite sprite;

  public:
    based_cell();
    int get_id();
    std::string get_ground();
    int get_x();
    int get_y();
    void set_id(int iidd);
    void set_ground(std::string gr);
    void set_x(int xx);
    void set_y(int yy);
    void draw_cell(sf::RenderWindow *window);
};
