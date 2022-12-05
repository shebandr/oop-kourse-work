#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "based_cell.h"
#include "mouse_ui.h"
#include "based_factory.h"
#include "coal_station.h"
using namespace std;
int picked_category = -1;
int picked_building = -1;
void mouse_ui(sf::Vector2i localPosition, based_cell** background_field, int* pc, int* pb, std::string* types_of_ground, based_factory** factory_field) {

    int x = localPosition.x;
    int y = localPosition.y;
    if (y <= 640) {
        int x_cell = x / 64;
        int y_cell = y / 64;
        factory_field[x][y] = coal_station();
        factory_field[x][y].set_x(x);
        factory_field[x][y].set_y(y);
        factory_field[x][y].set_empty(0);
        factory_field[x][y].set_ground(types_of_ground[1]);
    }
    else {
        if (y < 800) {

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
                    if (x > 640 && x <= 720) {
                        if (y > 640 && y <= 720) {
                            picked_building = 0;
                        }
                        if (y > 720 && y <= 800) {
                            picked_building = 1;
                        }

                    }
                    if (x > 720 && x <= 800) {
                        if (y > 640 && y <= 720) {
                            picked_building = 2;
                        }
                        if (y > 720 && y <= 800) {
                            picked_building = 3;
                        }

                    }
                    if (x > 800 && x <= 880) {
                        if (y > 640 && y <= 720) {
                            picked_building = 4;
                        }
                        if (y > 720 && y <= 800) {
                            picked_building = 5;
                        }

                    }
                    if (x > 880 && x <= 960) {
                        if (y > 640 && y <= 720) {
                            picked_building = 6;
                        }
                        if (y > 720 && y <= 800) {
                            picked_building = 7;
                        }

                    }
                }
            }
        }
    }
    *pc = picked_category;
    *pb = picked_building;
}
