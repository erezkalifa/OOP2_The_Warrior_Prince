#include "FileManager/Fonts.h"

Fonts::Fonts()
{
	sf::Font font;
	font.loadFromFile("Heroes.ttf");
	m_fonts.push_back(font);

	font.loadFromFile("ARCADECLASSIC.TTF");
	m_fonts.push_back(font);
}
