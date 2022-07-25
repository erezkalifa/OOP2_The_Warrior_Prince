#pragma once
#include "StaticObjects.h"

class Gate : public StaticObjects
{
public:

	Gate(const sf::Texture& texture, int x, int y);
	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition();

private:
	
	sf::Sprite m_sprite;
	sf::Clock clock;
	sf::Time time;

	int counterAnimation = 0;
};