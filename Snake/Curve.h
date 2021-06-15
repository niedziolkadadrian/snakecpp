#ifndef CURVE_H
#define CURVE_H
#include <SFML\Graphics.hpp>
#include <vector>
#include <utility>
#include <cmath>

class Curve{
	sf::CircleShape circle;
	sf::Vector2f pos;
	std::vector<std::pair<sf::Vector2f,float>> olds;
	int length;
	float radius;
public:
	Curve(float radius=0,sf::Vector2f pos=sf::Vector2f(0,0), sf::Color color=sf::Color(0,0,0,255));
	void setPosition(sf::Vector2f pos);
	void setPosition(float posx, float posy);
	void setRadius(float radius);
	void setColor(sf::Color color);
	void addToOlds();
	void draw(sf::RenderWindow &window);
	bool isColliding(sf::Vector2f other_pos, float other_radius);

	sf::Vector2f getPos();
	float getRadius();
	//returns size of vector with old positions
	int getOldsLength();
	sf::Vector2f getOldPos(int i);
	float getOldRadius(int i);
};
#endif