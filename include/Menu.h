#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

#include "FileManager/SoundHandle.h"
#include "FileManager/Textures.h"
#include "Macros.h"

class Menu
{
public:
	Menu();
	void openMenu(sf::RenderWindow& window);

private:

	sf::Font menuFont;
	sf::Font howToPlayFont;
	std::string theMenuFont = "pdark.ttf";
	std::string menuBackGround = "background.jpg";
	sf::Text NewGame;
	sf::Text Exit;
	sf::Text Characters;
	sf::Text Back;
	sf::Texture menuTexture;
	std::vector<sf::Texture> m_textures;
	sf::Texture arrowsTexture;
	sf::Texture SpaceTexture;
	sf::Sprite arrowsSprite;
	sf::Sprite spaceSprite;


	bool m_howToPlayPressed = false;
	float m_gridSizeF = 80.f;
};