#pragma once
#include "Objects/StaticObjects/Armor.h"

Armor::Armor(const sf::Texture& texture, int x, int y)
	: m_value(20), m_sprite(texture),  m_price(30)
{

	m_sprite.setTextureRect(sf::IntRect(3 * 40, 40, 30, 30));
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));

	font.loadFromFile("ARCADECLASSIC.TTF");

	setFontProp(font, std::to_string(m_price), (float)x, (float)y, 20, sf::Color::Yellow);
	priceText.setFont(font);
	priceText.setPosition((float)x, (float)y);
	priceText.setColor(sf::Color::Yellow);
	priceText.setCharacterSize(20);
	priceText.setString(std::to_string(m_price));

	
}

void Armor::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(priceText);
}

int Armor::getPrice()
{
	return m_price;
}
