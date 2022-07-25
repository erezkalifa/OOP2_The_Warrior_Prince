#pragma once
#include "StaticObjects.h"
#include "FileManager/Textures.h"

class Wall : public StaticObjects
{
public:
	Wall(const sf::Texture& texture, int x, int y);
	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition();

private:
	
	sf::Sprite m_sprite;
};