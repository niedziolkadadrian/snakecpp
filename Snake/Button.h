#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>

class Button{
private:
	sf::RectangleShape box;
	sf::Text text;
	sf::Vector2f pos;

	float width, height;
	float textOffsetX, textOffsetY;
	float padding_top, padding_right, padding_bottom, padding_left;
	std::string alignment;
	unsigned int text_size;
	void setElementsPositions();
public:
	Button(float width,float height, sf::Vector2f pos, sf::Color color=sf::Color(0,0,0,0));
	Button(float width,float height, float posx=0, float posy=0, sf::Color color=sf::Color(0,0,0,0));
	//Button position
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	//TEXT FONT
	void setFont(sf::Font *font);
	//TEXT
	void setText(sf::Text text, sf::Font *font, sf::Color color=sf::Color::Black, unsigned int size=30);
	void setText(std::string text, sf::Font *font, sf::Color color=sf::Color::Black, unsigned int size=30);
	//////////////////
	/// Text align params:
	/// "center" - centering the text (x and y axis)
	///	"left" - left (x axis), center (y axis)
	///	"right" - right (x axis), center (y axis)
	///	"bottom" - center (x axis), bottom (y axis)
	///	"top" - center (x axis), top (y axis)
	///	"bottom-left" - left (x axis), bottom(y axis)
	///	"top-left" - left (x axis), top (y axis)
	///	"bottom-right" - right (x axis), bottom (y axis)
	///	"top-right" - right (x axis), top (y axis)
	//////////////////
	void setTextAlign(std::string align);
	void setTextSize(unsigned int size);
	void setTextColor(sf::Color color);
	void changeText(std::string text);
	void changeText(sf::Text text);
	//BUTTON
	void setColor(sf::Color color);
	void setTexture(const sf::Texture *texture);

	void setPadding(float padding_top, float padding_right, float padding_bottom, float padding_left);
	void setPadding(float padding);

	sf::Vector2f getPos();
	float getWidth();
	float getheight();

	bool isPressed(const sf::Window &window, sf::Event &event);
	bool isMouseOver(const sf::Window &window);

	void draw(sf::RenderWindow &window);
};
#endif