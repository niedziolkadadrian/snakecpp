#ifndef FOOD_H
#define FOOD_H
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
class Food{
private:
	sf::CircleShape foodCrcl;
	sf::Vector2f position;

	float size;
public:
	Food(float size=10.0f, sf::Vector2f pos=sf::Vector2f(0,0), sf::Color color=sf::Color::White);
	void setPosition(sf::Vector2f pos);
	void setPosition(float posx, float posy);
	void setSize(float size);
	void setColor(sf::Color color);
	void draw(sf::RenderWindow &window);
	void setTexture(const sf::Texture *texture);

	sf::Vector2f getPos();
	float getSize();
};
#endif