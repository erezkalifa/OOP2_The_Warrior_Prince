#pragma once
#include "Gear.h"
#include "Macros.h"

class Shield : public Gear
{
public:
	Shield(const sf::Texture& texture, int x, int y);
	virtual void draw(sf::RenderWindow& window);
	int getValue() { return m_value; }
	virtual int getPrice();

private:
	
	sf::Sprite m_sprite;
	sf::Text priceText;

	sf::Font font;

	int m_value;
	int m_price;
};