#pragma once
#include "StaticObjects.h"

class Coin : public StaticObjects
{

public:

	Coin(const sf::Texture& texture, int x, int y, int value);
	virtual void draw(sf::RenderWindow& window);
	virtual sf::Vector2f getPosition();
	int getValue() { return m_value; }
	
private:
	
	sf::Sprite m_sprite;
	sf::Clock clock;
	sf::Time time;

	int counterAnimation = 0;
	int m_value;
};