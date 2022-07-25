#include "Objects/StaticObjects/Gate.h"

Gate::Gate(const sf::Texture& texture, int x, int y)
	:m_sprite(texture)
{
	m_sprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
	m_sprite.setPosition((float)x, (float)y);
	m_rect.setPosition((float)x, float(y));
	m_rect.setSize(sf::Vector2f(25.f, 25.f));
	
}


void Gate::draw(sf::RenderWindow& window)
{
	time = clock.getElapsedTime();
	for (int times = 0; times < 4; times++)
	{
		m_sprite.setTextureRect(sf::IntRect(0, (25 * counterAnimation), 25, 25));
		window.draw(m_sprite);
		if (time.asSeconds() >= 0.3)
		{
			clock.restart();
			counterAnimation++;
		}
		if (counterAnimation == 3)
		{
			counterAnimation = 0;
		}
	}
}

sf::Vector2f Gate::getPosition()
{
	return m_rect.getPosition();
}
