#ifndef KEYBINDINGS_H
#define KEYBINDINGS_H
#include <SFML\Window.hpp>
#include <map>
#include <vector>

struct InputCodes{
	int KeyboardKey;
	int MouseButton;
	int MouseWheel;
};

class KeyBindings{
private:
	std::vector<std::map<std::string, InputCodes>> keys;

	int numOfKeySlots;
public:
	KeyBindings(int numOfSlots=1);
	~KeyBindings(){}

	
	void mapAction(std::string action, sf::Keyboard::Key key, int slot=0);
	void mapAction(std::string action, sf::Mouse::Button key, int slot=0);
	void mapAction(std::string action, sf::Mouse::Wheel key, int slot=0);
	void unmapAction(std::string action);
	void unmapActionKey(std::string action, int slot);
	
	void setNumOfSlots(int number);
	int getNumOfSlots();
	InputCodes getActionKey(std::string action, int slot=0);
};
#endif