#pragma once
#include "Objects/GameObject.h"

class Weapon : public GameObject
{
public:
	Weapon();
	virtual void draw(sf::RenderWindow& window);

private:

};