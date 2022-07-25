#pragma once
#include "Objects/MovingObjects/Player.h"

Player::Player(const sf::Texture& texture, int x, int y)
	  : m_sprite(texture), m_movementSpeed((float)0.15), m_direction(0), m_hp(10), m_damage(2),
	m_armor(0)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::move(sf::Event& event, int& counterWalking, float& delta, sf::Clock& clock)
{
	if (canMoveUp == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_rect.move(0, -m_movementSpeed * delta);
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
			m_direction = 1;
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}

	if (canMoveDown == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_rect.move(0, m_movementSpeed * delta);
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
			m_direction = 2;
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}

	if (canMoveLeft == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_rect.move(-m_movementSpeed * delta, 0);
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
			m_direction = 3;
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}
	
	if (canMoveRight == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_rect.move(m_movementSpeed * delta, 0);
			m_sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
			m_direction = 4;
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
	}
	clock.restart();
	m_sprite.setPosition(m_rect.getPosition());
}



sf::Vector2f Player::getPosition()
{
	return m_sprite.getPosition();
}

sf::Vector2f Player::getNextStep()
{
	return sf::Vector2f();
}

int Player::getDirection()
{
	return m_direction;
}

void Player::gotDamage(int damage)
{
	if(m_armor > 0)
	{
		m_armor -= damage;
	}
	else
	{
		m_armor = 0;
		m_hp -= damage;
	}
}

void Player::updateDamage(int damageBonus)
{
	m_damage += damageBonus;
}

void Player::updateArmor(int armorBonus)
{
	m_armor += armorBonus;
}

int Player::getHP()
{
	return m_hp;
}

int Player::getArmor()
{
	return m_armor;
}

int Player::getDamage()
{
	return m_damage;
}
