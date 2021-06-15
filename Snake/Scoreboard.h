#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <string>

struct Interspace{
	float top, right, bottom, left;
};

class Scoreboard{
	sf::RectangleShape box;
	sf::Vector2f pos;
	std::vector<sf::Text> lines;
	std::vector<sf::Vector2f> lines_pos;

	int numOfLines;
	float width, height;
	Interspace padding;

	void UpdatePos();
public:
	Scoreboard(float width, float height, sf::Vector2f pos=sf::Vector2f(0,0), sf::Color color=sf::Color(0,0,0,0));
	void setPosition(sf::Vector2f pos);
	void setPosition(float posx, float posy);
	void setSize(float width, float height);
	void setColor(sf::Color color);
	void setTexture(const sf::Texture *texture);
	void draw(sf::RenderWindow &window);
	void setPadding(float top, float right, float bottom, float left);
	void setPadding(float padding);
	
	void addLine(sf::Font *font);
	void addLine(std::string text, sf::Font *font);
	void addLine(std::string text, sf::Font *font, unsigned int size);
	void setLineText(int i, std::string text);
	void setLinePosition(int i, sf::Vector2f offset);
	//////////////////
	/// Line positions @param:
	/// "center" - centering the text (x axis)
	///	"left" - left (x axis)
	///	"right" - right (x axis)
	//////////////////
	void setLinePosition(int i, std::string pos);
	void setLineTextColor(int i, sf::Color color);
	void setLineTextSize(int i, unsigned int size);

	sf::Vector2f getPos();
	float getWidth();
	float getheight();
	int getNumOfLines();

	sf::Vector2f getLinePos(int i);
	float getLineHeight(int i);
	float getLineWidth(int i);
};
#endif