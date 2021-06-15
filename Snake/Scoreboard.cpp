#include "Scoreboard.h"

Scoreboard::Scoreboard(float width, float height, sf::Vector2f pos, sf::Color color){
	this->width=width;
	this->height=height;
	this->box.setSize(sf::Vector2f(width,height));
	this->pos=pos;
	this->box.setPosition(this->pos);
	this->box.setFillColor(color);
	this->numOfLines=0;
	Interspace padding;
	padding.top=padding.right=padding.bottom=padding.left=0;
	this->padding=padding;
}
void Scoreboard::setPosition(sf::Vector2f pos){
	this->pos=pos;
	this->box.setPosition(this->pos);
}
	
void Scoreboard::setPosition(float posx, float posy){
	this->pos=sf::Vector2f(posx,posy);
	this->box.setPosition(this->pos);
}

void Scoreboard::setSize(float width, float height){
	this->box.setSize(sf::Vector2f(width,height));
}

void Scoreboard::setColor(sf::Color color){
	this->box.setFillColor(color);
}

void Scoreboard::setTexture(const sf::Texture *texture){
	this->box.setTexture(texture);
}

void Scoreboard::draw(sf::RenderWindow &window){
	window.draw(box);
	for(int i=0;i<numOfLines;i++){
		window.draw(lines[i]);
	}
}

void Scoreboard::UpdatePos(){
	for(int i=0;i<numOfLines;i++){
		if((this->lines_pos[i].x+lines[i].getLocalBounds().width)>(width-padding.right)){
			this->lines_pos[i].x=width-padding.right-lines[i].getLocalBounds().width;
			this->lines[i].setPosition(this->pos+lines_pos[i]);
		}
		if(this->lines_pos[i].x<padding.left){

			this->lines_pos[i].x=padding.left;
			this->lines[i].setPosition(this->pos+lines_pos[i]);
		}
		if((this->lines_pos[i].y+lines[i].getLocalBounds().top+lines[i].getLocalBounds().height)>(height-padding.bottom)){
			this->lines_pos[i].y=height-padding.top-(lines[i].getLocalBounds().top+lines[i].getLocalBounds().height);
			this->lines[i].setPosition(this->pos+lines_pos[i]);
		}
		if(this->lines_pos[i].y<padding.top){
			this->lines_pos[i].y=padding.top;
			this->lines[i].setPosition(this->pos+lines_pos[i]);
		}
	}
}

void Scoreboard::setPadding(float top, float right, float bottom, float left){
	this->padding.top=top;
	this->padding.right=right;
	this->padding.bottom=bottom;
	this->padding.left=left;
	UpdatePos();
}
void Scoreboard::setPadding(float padding){
	this->padding.top=this->padding.right=this->padding.bottom=this->padding.left=padding;
	this->UpdatePos();
}

void Scoreboard::addLine(sf::Font *font){
	this->numOfLines++;
	this->lines.push_back(sf::Text("",*font));

	this->lines_pos.push_back(sf::Vector2f(padding.left,padding.right));
	this->lines[numOfLines-1].setPosition(this->pos+lines_pos[numOfLines-1]);
	
}
void Scoreboard::addLine(std::string text, sf::Font *font){
	this->numOfLines++;
	this->lines.push_back(sf::Text(text,*font));

	this->lines_pos.push_back(sf::Vector2f(padding.left,padding.right));
	this->lines[numOfLines-1].setPosition(this->pos+lines_pos[numOfLines-1]);
}

void Scoreboard::addLine(std::string text, sf::Font *font, unsigned int size){
	this->numOfLines++;
	this->lines.push_back(sf::Text(text,*font,size));

	this->lines_pos.push_back(sf::Vector2f(padding.left,padding.right));
	this->lines[numOfLines-1].setPosition(this->pos+lines_pos[numOfLines-1]);
	
}

void Scoreboard::setLineText(int i, std::string text){
	if(i>=0 && i<numOfLines){
		this->lines[i].setString(text);
	}
}

void Scoreboard::setLinePosition(int i, sf::Vector2f offset){
	if(i>=0 && i<numOfLines){
		this->lines_pos[i]=offset;
		this->lines[i].setPosition(this->pos+this->lines_pos[i]);
		UpdatePos();
	}
}

void Scoreboard::setLinePosition(int i, std::string pos){
	if(i>=0 && i<numOfLines){
		if(pos=="center"){
			float offsetX=(this->width-lines[i].getLocalBounds().width)/2;
			this->lines_pos[i]=sf::Vector2f(offsetX,this->lines_pos[i].y);
			this->lines[i].setPosition(this->pos+this->lines_pos[i]);
		}
		if(pos=="left"){
			float offsetX=padding.left;
			this->lines_pos[i]=sf::Vector2f(offsetX,this->lines_pos[i].y);
			this->lines[i].setPosition(this->pos+this->lines_pos[i]);
		}
		if(pos=="right"){
			float offsetX=width-padding.right-lines[i].getLocalBounds().width;
			this->lines_pos[i]=sf::Vector2f(offsetX,this->lines_pos[i].y);
			this->lines[i].setPosition(this->pos+this->lines_pos[i]);
		}
		UpdatePos();
	}
}

void Scoreboard::setLineTextColor(int i,sf::Color color){
	if(i>=0 && i<numOfLines){
		this->lines[i].setFillColor(color);
	}
}

void Scoreboard::setLineTextSize(int i, unsigned int size){
	if(i>=0 && i<numOfLines){
		this->lines[i].setCharacterSize(size);
	}
}

sf::Vector2f Scoreboard::getPos(){
	return this->pos;
}
float Scoreboard::getWidth(){
	return this->width;
}
float Scoreboard::getheight(){
	return this->height;
}
int Scoreboard::getNumOfLines(){
	return this->numOfLines;
}

sf::Vector2f Scoreboard::getLinePos(int i){
	if(i>=0 && i<numOfLines){
		return this->lines_pos[i];
	}
	return sf::Vector2f(0,0);
}
float Scoreboard::getLineHeight(int i){
	if(i>=0 && i<numOfLines){
		return this->lines[i].getLocalBounds().top+this->lines[i].getLocalBounds().height;
	}
	return 0;
}
float Scoreboard::getLineWidth(int i){
	if(i>=0 && i<numOfLines){
		return this->lines[i].getLocalBounds().width;
	}
	return 0;
}