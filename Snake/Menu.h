#ifndef MENU_H
#define MENU_H

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <list>
#include "Button.h"

class Menu{
	sf::RectangleShape box;
	std::list<Button> buttons;

	float width, height;
	float buts_length;

	Menu(float width, float height);
};

#endif