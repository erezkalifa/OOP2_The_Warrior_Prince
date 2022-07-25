#pragma once
#include "Objects/GameObject.h"

class StaticObjects : public GameObject
{
public:
	StaticObjects();
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual sf::Vector2f getPosition() = 0;

private:

};