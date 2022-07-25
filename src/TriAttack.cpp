#pragma once
#include "TriAttack.h"


TriAttack::TriAttack(const sf::Texture& texture, int x, int y)
	:m_sprite(texture)
{
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
	m_price = 50;

	font.loadFromFile("ARCADECLASSIC.TTF");

	priceText.setFont(font);
	priceText.setPosition((float)x, (float)y);
	priceText.setColor(sf::Color::Yellow);
	priceText.setCharacterSize(20);
	priceText.setString(std::to_string(m_price));
}

void TriAttack::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(priceText);
}

int TriAttack::getPrice()
{
	return m_price;
}
