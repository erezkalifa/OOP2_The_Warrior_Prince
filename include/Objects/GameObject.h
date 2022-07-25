#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "FileManager/Textures.h"

class GameObject
{
public:
	GameObject();
	virtual void draw(sf::RenderWindow& window) = 0;
	sf::RectangleShape m_rect;

private:

};