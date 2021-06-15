#include "AssetsManager.h"

namespace aht{
	void AssetsManager::loadTexture(std::string name, std::string fileName){
		sf::Texture text;
		if(text.loadFromFile(fileName)){
			this->textures[name]=text;
		}
	}
	void AssetsManager::deleteTexture(std::string name){
		this->textures.erase(name);
	}
	sf::Texture &AssetsManager::getTexture(std::string name){
		return this->textures.at(name);
	}

	void AssetsManager::loadFont(std::string name, std::string fileName){
		sf::Font font;
		if(font.loadFromFile(fileName)){
			this->fonts[name]=font;
		}
	}
	void AssetsManager::deleteFont(std::string name){
		this->fonts.erase(name);
	}
	sf::Font &AssetsManager::getFont(std::string name){
		return this->fonts.at(name);
	}
}