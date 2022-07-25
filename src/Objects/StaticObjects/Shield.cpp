#pragma once
#include "Objects/StaticObjects/Shield.h"

Shield::Shield(const sf::Texture& texture, int x, int y) 
	:m_sprite(texture)
{
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
	m_value = 10;
	m_price = 15;

	font.loadFromFile("ARCADECLASSIC.TTF");

	priceText = setFontProp(font, std::to_string(m_price), (float)x, (float)y-10, 20, sf::Color::Yellow);
	

	
}

void Shield::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(priceText);
}

int Shield::getPrice()
{
	return m_price;
}
