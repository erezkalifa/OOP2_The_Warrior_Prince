#pragma once
#include "Objects/MovingObjects/MovingObjects.h"
#include "Random.h"

class Monster : public MovingObjects
{
public:
	Monster(const sf::Texture& texture, int x, int y);
	Monster() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void move(sf::Event& event, int& counterWalking, float& delta, sf::Clock& clock) = 0;
	virtual int getDirection() = 0;
	virtual void gotDamage(int damage) = 0;
	virtual int getHP() = 0;

private:
	
	sf::Sprite m_sprite;

	Random random;
	int m_direction;
	float m_movementSpeed;
};