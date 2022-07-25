#pragma once
#include "Objects/MovingObjects/Monsters/Boss.h"

Boss::Boss(const sf::Texture& texture, int x, int y)
	:m_sprite(texture)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
	m_direction = 0;
	m_movementSpeed = (float)0.15;
	counter = 0;
	m_damage = 3;
	m_hp = 20;
	
}


void Boss::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Boss::move(sf::Event& event, int& counterWalking, float& delta, sf::Clock& clock)
{
	if (m_direction == 1)
	{
		if (canMoveUp == true)
		{
			m_rect.move(0, -m_movementSpeed * delta);
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
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
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
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
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
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
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
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

int Boss::getDirection()
{
	return m_direction;
}

void Boss::gotDamage(int damage)
{
	m_hp -= damage;
}

int Boss::getHP()
{
	return m_hp;
}

int Boss::getDamage()
{
	return m_damage;
}
