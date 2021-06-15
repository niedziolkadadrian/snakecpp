#include "Snake.h"

Snake::Snake(float sqrSize, int snakeSize, sf::Vector2f pos, sf::Color color){
	this->sqrSize=sqrSize;
	this->snakeSize=snakeSize;
	this->snakeSqr.setSize(sf::Vector2f(sqrSize,sqrSize));
	this->snakeSqr.setFillColor(color);
	upDir=0;
	rightDir=0;
	for(int i=0;i<snakeSize;i++){
		positions.push_back(pos);
	}
}

void Snake::draw(sf::RenderWindow &window){
	for(int i=0; i<snakeSize;i++){
		snakeSqr.setPosition(positions[i]);
		window.draw(snakeSqr);
	}
}

void Snake::moveDir(int upDir, int rightDir){
	this->upDir=upDir;
	this->rightDir=rightDir;
}

void Snake::update(){
	tail=positions[snakeSize-1];
	for(int i=1;i<snakeSize;i++){
		positions[snakeSize-i]=positions[snakeSize-i-1];
	}
	positions[0].x+=rightDir;
	positions[0].y+=upDir;
}

void Snake::grow(){
	sf::Vector2f pos=positions[positions.size()-1];
	positions.push_back(pos);
	this->snakeSize++;
}

sf::Vector2f Snake::getPos(){
	return positions[0];
}

void Snake::setColor(sf::Color color){
	this->snakeSqr.setFillColor(color);
}

void Snake::updateDead(){
	setColor(sf::Color::Red);
	positions[0]=this->tail;
}

int Snake::getSnakeSize(){
	return this->snakeSize;
}

sf::Vector2f Snake::getElemPos(int i){
	if(i>=0 && i<snakeSize)
		return positions[i];
	return sf::Vector2f(0,0);
}

void Snake::setSqrSize(float sqrSize){
	this->sqrSize=sqrSize;
	this->snakeSqr.setSize(sf::Vector2f(sqrSize,sqrSize));
}

float Snake::getSqrSize(){
	return this->sqrSize;
}

void Snake::reset(sf::Vector2f pos, int size){
	this->snakeSize=size;
	this->positions.clear();
	for(int i=0;i<size;i++){
		positions.push_back(pos);
	}
}