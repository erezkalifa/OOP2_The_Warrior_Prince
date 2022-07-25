#include "Macros.h"


sf::RectangleShape setShapeProp(float x, float y,
	const sf::Color& color, const sf::Vector2f& size) {

	sf::RectangleShape rec;
	rec.setPosition(x, y);
	rec.setFillColor(color);
	rec.setSize(size);
	return rec;
}


sf::Text setFontProp(sf::Font& font, const sf::String& str,
	float x, float y, const unsigned int& size,
	const sf::Color& color) {

	sf::Text txt;
	txt.setFont(font);
	txt.setString(str);
	txt.setPosition(x, y);
	txt.setCharacterSize(size);
	txt.setFillColor(color);
	return txt;

}