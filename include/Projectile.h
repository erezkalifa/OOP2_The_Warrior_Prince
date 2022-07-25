#pragma once
#include "Objects/GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile();
	virtual void draw(sf::RenderWindow& window);
	void update(float delta);
	int direction;

private:
	float m_movementSpeed;
	int m_damage;

};