#pragma once
#include <SFML/Graphics.hpp>
#include "based_cell.h"
#include <string>

void mouse_ui(sf::Vector2i localPosition, based_cell** background_field, int* pc, int* pb, std::string* types_of_ground);