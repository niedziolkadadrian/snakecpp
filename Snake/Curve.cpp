#include "Curve.h"

Curve::Curve(float radius,sf::Vector2f pos, sf::Color color){
	this->radius=radius;
	this->pos=pos;
	this->length=0;
	this->circle.setRadius(radius);
	this->circle.setOrigin(radius,radius);
	this->circle.setPosition(this->pos);
	this->circle.setFillColor(color);
}
void Curve::setPosition(sf::Vector2f pos){
	this->pos=pos;
	this->circle.setPosition(this->pos);
}
void Curve::setPosition(float posx, float posy){
	this->pos=sf::Vector2f(posx,posy);
	this->circle.setPosition(this->pos);
}
void Curve::setRadius(float radius){
	this->radius=radius;
	this->circle.setRadius(radius);
	this->circle.setOrigin(radius,radius);
}
void Curve::setColor(sf::Color color){
	this->circle.setFillColor(color);
}
void Curve::addToOlds(){
	this->length++;
	this->olds.push_back(std::make_pair(this->pos,this->radius));
}
void Curve::draw(sf::RenderWindow &window){
	window.draw(circle);
}
bool Curve::isColliding(sf::Vector2f other_pos, float other_radius){
	float dst=hypot(abs(this->pos.x-other_pos.x),abs(this->pos.y-other_pos.y));
	if(dst<=this->radius+other_radius)
		return true;
	return false;
}

sf::Vector2f Curve::getPos(){
	return this->pos;
}
float Curve::getRadius(){
	return this->radius;
}
int Curve::getOldsLength(){
	return this->length;
}
sf::Vector2f Curve::getOldPos(int i){
	if(i>=0 && i<this->length){
		return olds[i].first;
	}
	return sf::Vector2f(0,0);
}
float Curve::getOldRadius(int i){
	if(i>=0 && i<this->length){
		return olds[i].second;
	}
	return 0;
}