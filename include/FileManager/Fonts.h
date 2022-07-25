#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Fonts
{ 
public:
	Fonts();
	std::vector<sf::Font> getFonts() { return m_fonts; }

private:
	std::vector<sf::Font> m_fonts;
};