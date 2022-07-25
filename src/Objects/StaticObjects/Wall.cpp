#pragma once
#include "Objects/StaticObjects/Wall.h"

Wall::Wall(const sf::Texture& texture, int x, int y)
	:m_sprite(texture)
{
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
	
}


void Wall::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::Vector2f Wall::getPosition()
{
	return m_sprite.getPosition();
}
