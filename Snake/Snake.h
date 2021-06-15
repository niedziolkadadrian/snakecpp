#ifndef SNAKE_H
#define SNAKE_H
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>

class Snake{
private:
	sf::RectangleShape snakeSqr;
	float sqrSize;
	int snakeSize;
	int upDir, rightDir;
	std::vector<sf::Vector2f> positions;
	sf::Vector2f tail;

public:
	Snake(float sqrSize=10.0f, int snakeSize=3, sf::Vector2f pos=sf::Vector2f(0,0), sf::Color color=sf::Color::Black);
	void setSqrSize(float sqrSize);
	void draw(sf::RenderWindow &window);
	void setColor(sf::Color color);
	void grow();
	void reset(sf::Vector2f pos, int size);
	void update();
	void moveDir(int upDir, int rightDir);
	void updateDead();
	
	sf::Vector2f getPos();
	sf::Vector2f getElemPos(int i);
	int getSnakeSize();
	float getSqrSize();

};
#endif