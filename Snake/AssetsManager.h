#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include <SFML\Graphics.hpp>
#include <string>
#include <map>

namespace aht{
	class AssetsManager{
	private:
		std::map<std::string,sf::Texture> textures;
		std::map<std::string,sf::Font> fonts;
	public:
		void loadTexture(std::string name, std::string fileName);
		void deleteTexture(std::string name);
		sf::Texture &getTexture(std::string name);

		void loadFont(std::string name, std::string fileName);
		void deleteFont(std::string name);
		sf::Font &getFont(std::string name);
	};
}
#endif