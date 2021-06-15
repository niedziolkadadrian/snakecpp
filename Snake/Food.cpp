#include "Food.h"

Food::Food(float size, sf::Vector2f pos, sf::Color color){
	this->size=size;
	this->foodCrcl.setRadius(size/2);
	this->position=pos;
	this->foodCrcl.setPosition(this->position);
	this->foodCrcl.setFillColor(color);
}

void Food::setPosition(sf::Vector2f pos){
	this->position=pos;
	this->foodCrcl.setPosition(pos);
}

void Food::setPosition(float posx, float posy){
	this->position=sf::Vector2f(posx,posy);
	this->foodCrcl.setPosition(this->position);
}

void Food::setSize(float size){
	this->size=size;
	this->foodCrcl.setRadius(size/2);
}

void Food::setColor(sf::Color color){
	this->foodCrcl.setFillColor(color);
}

void Food::draw(sf::RenderWindow &window){
	window.draw(foodCrcl);
}

sf::Vector2f Food::getPos(){
	return this->position;
}

float Food::getSize(){
	return this->size;
}

void Food::setTexture(const sf::Texture *texture){
	this->foodCrcl.setTexture(texture);
}