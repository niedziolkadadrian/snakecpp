#include "KeyBindings.h"

KeyBindings::KeyBindings(int numOfSlots){
	if(numOfSlots>0){
		this->numOfKeySlots=numOfSlots;
		this->keys.resize(numOfSlots);
	}
	else{
		this->numOfKeySlots=1;
		this->keys.resize(1);
	}
}


void KeyBindings::mapAction(std::string action, sf::Keyboard::Key key, int slot){
	InputCodes codes={key,-10,-10};
	this->keys[slot].emplace(action,codes);
}
void KeyBindings::mapAction(std::string action, sf::Mouse::Button key, int slot){
	InputCodes codes={-10,key,-10};
	this->keys[slot].emplace(action,codes);
}
void KeyBindings::mapAction(std::string action, sf::Mouse::Wheel key, int slot){
	InputCodes codes={-10,-10,key};
	this->keys[slot].emplace(action,codes);
}

int KeyBindings::getNumOfSlots(){
	return this->numOfKeySlots;
}
InputCodes KeyBindings::getActionKey(std::string action, int slot){
	return this->keys[slot][action];
}

void KeyBindings::setNumOfSlots(int number){
	if(number>0){
		this->numOfKeySlots=number;
		this->keys.resize(number);
	}
}
