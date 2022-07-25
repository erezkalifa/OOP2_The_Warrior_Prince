#include "Objects/MovingObjects/Monsters/Monster.h"
#pragma once

Monster::Monster(const sf::Texture& texture, int x, int y)
	:m_sprite(texture)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
	m_direction = 0;
	m_movementSpeed = (float)0.10;
}

void Monster::draw(sf::RenderWindow& window)
{
}
