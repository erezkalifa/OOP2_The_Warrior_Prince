#pragma once
#include "Objects/GameObject.h"

class MovingObjects : public GameObject
{
public:
	MovingObjects();
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void move(sf::Event& event, int& counterWalking, float& delta, sf::Clock& clock) = 0;
	virtual int getDirection() = 0;
	virtual void gotDamage(int damage) = 0;
	virtual int getHP() = 0;

private:

};