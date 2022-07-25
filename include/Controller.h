#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <string>
#include <sstream>
#include "Objects/GameObject.h"
#include "Board.h" 
#include "Objects/StaticObjects/Weapon.h"
#include "Gear.h"
#include "Objects/StaticObjects/Wall.h"
#include "Objects/MovingObjects/Player.h"
#include "Objects/MovingObjects/Monsters/NormalMonster.h"
#include "Objects/MovingObjects/MovingObjects.h"
#include "Objects/MovingObjects/Monsters/Boss.h"
#include "Objects/StaticObjects/Armor.h"
#include "Objects/StaticObjects/Shield.h"
#include "Menu.h"
#include "TriAttack.h"
#include "FileManager/Textures.h"
#include "FileManager/SoundHandle.h"


class Controller
{
public:

	Controller();
	void run();

private:
	
	void createDataText();
	void runMenu();
	void runGame();

	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	sf::Sprite m_background;
	Fonts fonts;

	bool m_isPlaying = false;

	std::vector<sf::Font> m_fonts;

	sf::Text DataText;

};