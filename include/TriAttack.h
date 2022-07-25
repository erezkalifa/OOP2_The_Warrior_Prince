#pragma once
#include "Objects/StaticObjects/Weapon.h"
#include "Macros.h"

class TriAttack : public Weapon
{
public:
	TriAttack(const sf::Texture& texture, int x, int y);
	TriAttack(int x, int y);
	virtual void draw(sf::RenderWindow& window);
	virtual int getPrice();

private:

	sf::Sprite m_sprite;
	sf::Text priceText;
	sf::Font font;
	int m_price;
};