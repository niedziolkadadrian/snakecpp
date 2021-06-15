#include "Button.h"
#include <iostream>
using namespace std;

Button::Button(float width,float height, sf::Vector2f pos, sf::Color color){
	this->box.setSize(sf::Vector2f(width,height));
	this->box.setFillColor(color);
	this->width=width;
	this->height=height;
	this->pos=pos;
	this->textOffsetX=0;
	this->textOffsetY=0;
	this->padding_top=0;
	this->padding_right=0;
	this->padding_bottom=0;
	this->padding_left=0;
	setTextAlign("center");
}

Button::Button(float width,float height, float posx, float posy, sf::Color color){
	this->box.setSize(sf::Vector2f(width,height));
	this->box.setFillColor(color);
	this->width=width;
	this->height=height;
	this->pos=sf::Vector2f(posx,posy);
	this->textOffsetX=0;
	this->textOffsetY=0;
	this->padding_top=0;
	this->padding_right=0;
	this->padding_bottom=0;
	this->padding_left=0;
	setTextAlign("center");
}

void Button::setPosition(float x, float y){
	this->pos=sf::Vector2f(x,y);
	this->setElementsPositions();
}

void Button::setPosition(sf::Vector2f pos){
	this->pos=pos;
	this->setElementsPositions();
}

void Button::setElementsPositions(){
	this->box.setPosition(pos.x,pos.y);
	this->text.setPosition(pos.x+textOffsetX, pos.y+textOffsetY);
}

//SET FONT
void Button::setFont(sf::Font *font){
	this->text.setFont(*font);
}
//SET TEXT
void Button::setText(sf::Text text, sf::Font *font, sf::Color color, unsigned int size){
	this->text.setFont(*font);
	this->text=text;
	this->text.setColor(color);
	if(size>0  && size<=(unsigned int)(height-(this->padding_top+this->padding_bottom))){
		this->text_size=size;
		this->text.setCharacterSize(this->text_size);
	}
	else{
		this->text_size=(unsigned int)(height-(this->padding_top+this->padding_bottom));
		this->text.setCharacterSize(this->text_size);
	}
}
void Button::setText(std::string text, sf::Font *font, sf::Color color, unsigned int size){
	this->text.setFont(*font);
	this->text=sf::Text(text,*font);
	this->text.setColor(color);
	if(size>0  && size<=(unsigned int)(height-(this->padding_top+this->padding_bottom))){
		this->text_size=size;
		this->text.setCharacterSize(this->text_size);
	}
	else{
		this->text_size=(int)(height-(this->padding_top+this->padding_bottom));
		this->text.setCharacterSize(this->text_size);
	}
}
//SET TEXT SIZE
void Button::setTextSize(unsigned int size){
	if(size>0  && size<=(unsigned int)(height-(this->padding_top+this->padding_bottom))){
		this->text_size=size;
		this->text.setCharacterSize(this->text_size);
	}
	else{
		this->text_size=(unsigned int)(height-(this->padding_top+this->padding_bottom));
		this->text.setCharacterSize(this->text_size);
	}
}
//SET TEXT COLOR
void Button::setTextColor(sf::Color color){
	this->text.setColor(color);
}

//CHANGE TEXT
void Button::changeText(std::string text){
	if(this->text.getFont()){
		this->text.setString(text);
	}
	else{
		cout<<"ERROR NO FONT ASSIGNED!"<<endl;
	}
}
void Button::changeText(sf::Text text){
	if(this->text.getFont()){
		this->text.setString(text.getString());
	}
	else{
		cout<<"ERROR NO FONT ASSIGNED!"<<endl;
	}
}
//TEXT ALIGN
void Button::setTextAlign(std::string align){
	this->alignment=align;
	if(align=="center"){
		this->textOffsetX=(width-text.getLocalBounds().width)/2;
		this->textOffsetY=(height-(text.getLocalBounds().height+text.getLocalBounds().top))/2;
	}
	else if(align=="top"){
		this->textOffsetX=(width-text.getLocalBounds().width)/2;
		this->textOffsetY=-text.getLocalBounds().top+padding_top;
	}
	else if(align=="bottom"){
		this->textOffsetX=(width-text.getLocalBounds().width)/2;
		this->textOffsetY=height-(text.getLocalBounds().height+text.getLocalBounds().top)-padding_bottom;
	}
	else if(align=="left"){
		this->textOffsetX=padding_left;
		this->textOffsetY=(height-(text.getLocalBounds().height+text.getLocalBounds().top))/2;
	}
	else if(align=="right"){
		this->textOffsetX=width-text.getLocalBounds().width-padding_right;
		this->textOffsetY=(height-(text.getLocalBounds().height+text.getLocalBounds().top))/2;
	}
	else if(align=="bottom-left"){
		this->textOffsetX=padding_left;
		this->textOffsetY=height-(text.getLocalBounds().height+text.getLocalBounds().top)-padding_bottom;
	}
	else if(align=="top-left"){
		this->textOffsetX=padding_left;
		this->textOffsetY=-text.getLocalBounds().top+padding_top;
	}
	else if(align=="bottom-right"){
		this->textOffsetX=width-text.getLocalBounds().width-padding_right;
		this->textOffsetY=height-(text.getLocalBounds().height+text.getLocalBounds().top)-padding_bottom;
	}
	else if(align=="top-right"){
		this->textOffsetX=width-text.getLocalBounds().width-padding_right;
		this->textOffsetY=-text.getLocalBounds().top+padding_top;
	}
	this->setElementsPositions();
}

void Button::setPadding(float padding_top, float padding_right, float padding_bottom, float padding_left){
	this->padding_top=padding_top;
	this->padding_right=padding_right;
	this->padding_bottom=padding_bottom;
	this->padding_left=padding_left;
	setTextSize(this->text_size);
	setTextAlign(this->alignment);
}
void Button::setPadding(float padding){
	this->padding_top=this->padding_right=this->padding_bottom=this->padding_left=padding;
	setTextSize(this->text_size);
	setTextAlign(this->alignment);
}

void Button::setColor(sf::Color color){
	this->box.setFillColor(color);
}

void Button::setTexture(const sf::Texture *texture){
	this->box.setTexture(texture);
}

sf::Vector2f Button::getPos(){
	return this->pos;
}

float Button::getWidth(){
	return this->width;
}
float Button::getheight(){
	return this->height;
}

//DRAW
void Button::draw(sf::RenderWindow &window){
	window.draw(box);
	window.draw(text);
}

bool Button::isPressed(const sf::Window &window, sf::Event &event){
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if((mousePos.x>=this->pos.x && mousePos.x<=this->pos.x+this->width) && (mousePos.y>=this->pos.y && mousePos.y<=this->pos.y+this->height)){
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left){
			return true;
		}
	}	
	return false;
}
bool Button::isMouseOver(const sf::Window &window){
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if((mousePos.x>=this->pos.x && mousePos.x<=this->pos.x+this->width) && (mousePos.y>=this->pos.y && mousePos.y<=this->pos.y+this->height)){
		return true;
	}
	return false;
}