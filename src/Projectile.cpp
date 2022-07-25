#include "Projectile.h"

Projectile::Projectile()
{
	m_movementSpeed = 0.5;
	m_damage = 5;
	direction = 0;
	m_rect.setSize(sf::Vector2f(10, 10));
	m_rect.setPosition(0, 0);
	m_rect.setFillColor(sf::Color::Black);
}

void Projectile::draw(sf::RenderWindow& window)
{
}

void Projectile::update(float delta)
{
	if (direction == 1)
	{
		m_rect.move(0, -m_movementSpeed * delta);
	}
	if (direction == 2)
	{
		m_rect.move(0, m_movementSpeed * delta);
	}
	if (direction == 3)
	{
		m_rect.move(-m_movementSpeed * delta, 0);
	}
	if (direction == 4)
	{
		m_rect.move(m_movementSpeed * delta, 0);
	}

}
