#pragma once
#include "Objects/GameObject.h"
#include "FileManager/Fonts.h"

class Gear :public GameObject
{
public:
	Gear();
	virtual void draw(sf::RenderWindow& window);
	virtual int getPrice() = 0;

private:

};