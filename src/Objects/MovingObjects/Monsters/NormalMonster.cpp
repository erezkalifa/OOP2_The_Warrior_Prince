#include "Objects/MovingObjects/Monsters/NormalMonster.h"
#pragma once

NormalMonster::NormalMonster(const sf::Texture& texture, int x, int y)
	:m_sprite(texture)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
	m_direction = 0;
	m_movementSpeed = (float)0.10;
	counter = 0;
	m_damage = 2;
	m_hp = 5;

	
}

void NormalMonster::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void NormalMonster::move(sf::Event& event, int& counterWalking, float& delta, sf::Clock& clock)
{
	if (m_direction == 1)
	{
		if (canMoveUp == true)
		{
			m_rect.move(0, -m_movementSpeed * delta);
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}

	else if (m_direction == 2)
	{
		if (canMoveDown == true)
		{
			m_rect.move(0, m_movementSpeed * delta);
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}

	else if (m_direction == 3)
	{
		if (canMoveLeft == true)
		{
			m_rect.move(-m_movementSpeed * delta, 0);
			m_sprite.setTextureRect(sf::IntRect((49 * 4) + 49 * counterWalking, 1, 49, 49));
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}

	else if (m_direction == 4)
	{
		if (canMoveRight == true)
		{
			m_rect.move(m_movementSpeed * delta, 0);
			m_sprite.setTextureRect(sf::IntRect((49 * 6) + 49 * counterWalking, 1, 49, 49));
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}

	counter++;
	if (counter >= 200)
	{
		m_direction = random.generateRandom(4);
		counter = 0;
	}
	m_sprite.setPosition(m_rect.getPosition());
}

int NormalMonster::getDirection()
{
	return m_direction;
}

void NormalMonster::gotDamage(int damage)
{
	m_hp -= damage;
}

int NormalMonster::getHP()
{
	return m_hp;
}
