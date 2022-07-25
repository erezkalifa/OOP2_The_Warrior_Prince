#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "FileManager/Textures.h"


sf::RectangleShape setShapeProp(float x, float y,
	const sf::Color& color, const sf::Vector2f& size);

sf::Text setFontProp(sf::Font& font, const sf::String& str,
	float x, float y, const unsigned int& size,
	const sf::Color& color);
