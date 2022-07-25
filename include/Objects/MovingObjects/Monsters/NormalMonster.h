#pragma once
#include "Monster.h"

class NormalMonster : public Monster
{
public:

	NormalMonster(const sf::Texture& texture, int x, int y);
	virtual void draw(sf::RenderWindow& window);
	virtual void move(sf::Event& event, int& counterWalking, float& delta, sf::Clock& clock);
	int getDirection();
	int getDamage() { return m_damage; }
	virtual void gotDamage(int damage);
	virtual int getHP();

	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;

private:
	
	sf::Sprite m_sprite;

	Random random;
	int m_direction;
	float m_movementSpeed;

	int counter;
	int m_damage;
	int m_hp;
};