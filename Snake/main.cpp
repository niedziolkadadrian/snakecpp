#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <ctime>
#include "Button.h"
#include "Snake.h"
#include "Food.h"
#include "Scoreboard.h"
#include "KeyBindings.h"
using namespace std;

//////////////////////////
// cos x -sin x
// sin x cos x
/////////////////////////

bool collisionDetection(Snake &snake){
	int size = snake.getSnakeSize();
	if(size>4){
		sf::Vector2f pos=snake.getPos();
		for(int i=4;i<size;i++){
			if(pos==snake.getElemPos(i))
				return true;
		}
	}
	return false;
}

bool foodColl(Snake &snake, Food &food){
	if(snake.getPos()==food.getPos())
		return true;
	return false;
}

void generateFood(Food &food, Snake &snake,float gameWidth,float gameHeight, float offsetX, float offsetY){
	float size=food.getSize();
	int maxW=gameWidth/size;
	int maxH=gameHeight/size;

	sf::Vector2f pos(offsetX+((rand()%maxW)*size),offsetY+((rand()%maxH)*size));
	bool available=true;
	for(int i=0;i<snake.getSnakeSize();i++){
		if(snake.getElemPos(i)==pos)
			available=false;
	}
	if(available){
		food.setPosition(pos);
	}
	else{
		generateFood(food, snake, gameWidth, gameHeight,offsetX,offsetY);
	}
}

void resetSnake(Food &food, Snake &snake, int snakeSize,float gameWidth,float gameHeight, float offsetX, float offsetY){
	float size=snake.getSqrSize();
	int maxW=gameWidth/size;
	int maxH=gameHeight/size;

	sf::Vector2f pos(offsetX+((rand()%maxW)*size),offsetY+((rand()%maxH)*size));
	snake.reset(pos,snakeSize);
	generateFood(food, snake, gameWidth, gameHeight,offsetX,offsetY);
}

int main(){
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(700,500),"Snake");
	sf::RectangleShape gameGrid(sf::Vector2f(500,500));
	gameGrid.setFillColor(sf::Color(188,188,188,255));

	Snake snake(10,3,sf::Vector2f(100,100));
	Food food(10,sf::Vector2f(300,300),sf::Color::Green);
	sf::Texture apple;
	apple.loadFromFile("pics/apple.png");
	//food.setTexture(&apple);
	int licz=0;
	bool end=false;
	bool dead=false;
	bool chgC=false;

	bool movingR=false, movingU=false;
	bool wait=false;

	sf::Clock clock;
	float tick=0.3;

	int pnts=0;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	Scoreboard scoreboard(200,500,sf::Vector2f(500,0),sf::Color(140,10,100,155));
	scoreboard.setPadding(20,10,20,10);
	scoreboard.addLine("Scoreboard",&font,30);
	scoreboard.setLineTextColor(0,sf::Color::Blue);
	scoreboard.setLinePosition(0,"center");
	scoreboard.addLine(&font);
	scoreboard.setLinePosition(1,sf::Vector2f(0,scoreboard.getLinePos(0).y+scoreboard.getLineHeight(0)));
	scoreboard.setLineTextSize(1,20);
	scoreboard.setLineText(1,"Wynik: "+to_string(pnts));

	
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::KeyPressed){
				cout<<event.key.code<<endl;
			}
			if(event.type==sf::Event::Closed)
				window.close();
			if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Z){
				snake.grow();
				tick=max(0.03,tick-0.01);
			}
			if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::R){
				resetSnake(food,snake,3,500,500,0,0);
				snake.setColor(sf::Color::Black);
				end=false;
				dead=false;
				pnts=0;
				scoreboard.setLineText(1,"Wynik: "+to_string(pnts));
				snake.moveDir(0,0);
				movingR=false;
				movingU=false;
				tick=0.3;
			}

			if(!movingR && !wait){
				if(event.type==sf::Event::KeyPressed && (event.key.code==sf::Keyboard::Right || event.key.code==sf::Keyboard::D)){
					snake.moveDir(0,10);
					movingR=true;
					movingU=false;
					wait=true;
				}
				if(event.type==sf::Event::KeyPressed && (event.key.code==sf::Keyboard::Left || event.key.code==sf::Keyboard::A)){
					snake.moveDir(0,-10);
					movingR=true;
					movingU=false;
					wait=true;
				}
			}
			if(!movingU && !wait){
				if(event.type==sf::Event::KeyPressed && (event.key.code==sf::Keyboard::Down || event.key.code==sf::Keyboard::S)){
					snake.moveDir(10,0);
					movingR=false;
					movingU=true;
					wait=true;
				}
				if(event.type==sf::Event::KeyPressed && (event.key.code==sf::Keyboard::Up || event.key.code==sf::Keyboard::W)){
					snake.moveDir(-10,0);
					movingR=false;
					movingU=true;
					wait=true;
				}
			}
		}
		window.clear(sf::Color::White);
		window.draw(gameGrid);
		
		scoreboard.draw(window);
		//Updating snake
		if(clock.getElapsedTime().asSeconds() > tick){
			if(!end){
				snake.update();
				wait=false;
				end = collisionDetection(snake);
				if(snake.getPos().x<0 || snake.getPos().y<0 || snake.getPos().x>500-10 || snake.getPos().y>500-10)
					end=true;
				if(foodColl(snake, food)){
					snake.grow();
					//Aktualizacja tablicy wyników
					pnts++;
					scoreboard.setLineText(1,"Wynik: "+to_string(pnts));
					//generowanie nowego jedzenia
					generateFood(food,snake,500,500,0,0);
					tick=max(0.03,tick-0.01);
				}
			}
			else{
				if(!dead){
					snake.updateDead();
					dead=true;
				}
				else{
					if(!chgC){
						snake.setColor(sf::Color(255,0,0,255));
						chgC=true;
					}
					else{
						snake.setColor(sf::Color(180,50,50,255));
						chgC=false;
					}
				}
			}
			clock.restart();
		}
		food.draw(window);
		snake.draw(window);
		window.display();
	}
	return 0;
}