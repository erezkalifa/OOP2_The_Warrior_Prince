#include "Menu.h"

Menu::Menu()

{
	menuFont.loadFromFile(theMenuFont);
	menuTexture.loadFromFile(menuBackGround);
	howToPlayFont.loadFromFile("Logo Font.otf");
	
	NewGame = setFontProp(menuFont, "New Game", 200, 300, 40, sf::Color::Red);
	
	Exit = setFontProp(menuFont, "Exit", 200, 500, 40, sf::Color::Red);

	Characters = setFontProp(menuFont, "How to play", 200, 400, 40, sf::Color::Red);

	Back = setFontProp(menuFont, "Back", 20, 750, 40, sf::Color::White);

	arrowsTexture.loadFromFile("arrows.png");
	SpaceTexture.loadFromFile("space.png");

	arrowsSprite.setTexture(arrowsTexture);
	arrowsSprite.setPosition(600, 90);
	spaceSprite.setTexture(SpaceTexture);
	spaceSprite.setPosition(500, 190);
}

void Menu::openMenu(sf::RenderWindow& window)
{
	if(SoundHandle::instance().getSoundStatus())
	SoundHandle::instance().startGameMusic();

	sf::RectangleShape newGameRec, ExitRec, CharacterRec, BackRec;

	newGameRec = setShapeProp(200, 300, sf::Color::Transparent, sf::Vector2f(270, 60));
	ExitRec = setShapeProp(200, 500, sf::Color::Transparent, sf::Vector2f(100, 60));
	CharacterRec = setShapeProp(200, 400, sf::Color::Transparent, sf::Vector2f(280, 60));
	BackRec = setShapeProp(0, 750, sf::Color::Red, sf::Vector2f(200, 60));

	sf::Sprite backGroundSprite(menuTexture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				SoundHandle::instance().pauseMenuSound();
			}
		}

		
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (ExitRec.getGlobalBounds().contains(window.mapPixelToCoords
				(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
				{
					window.close();
					SoundHandle::instance().pauseMenuSound();
				}

				if (newGameRec.getGlobalBounds().contains(window.mapPixelToCoords
				(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
				{
					
					window.clear();
					return;
				}

				if (CharacterRec.getGlobalBounds().contains(window.mapPixelToCoords
				(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
				{
					m_howToPlayPressed = true;
				}
			}
		}

		
		if (m_howToPlayPressed == false)
		{
			window.draw(backGroundSprite);

			window.draw(newGameRec);
			window.draw(NewGame);

			window.draw(CharacterRec);
			window.draw(Characters);

			window.draw(ExitRec);
			window.draw(Exit);

			window.display();
		}
		else {
			window.draw(backGroundSprite);
			std::stringstream ss;
			ss << " Destroy all the invaders in order to win the game." << std::endl <<
				std::endl << " use keybord arrows for walk." << std::endl << std::endl
				<< " use space bar for attack." << std::endl <<
				std::endl << " In order to move forward to next level --> enter the gate " <<
				std::endl << " that will be visible after all the invaders will be destroyed"
				<< std::endl << std::endl <<
				" collect coins and buy some stuff that will make you stronger" << std::endl <<
				" Good luck!" << std::endl;
			sf::Text text;
			text.setCharacterSize(40);
			text.setFont(howToPlayFont);
			text.setString(ss.str());
			text.setFillColor(sf::Color::White);
			sf::Sprite sprite;
			
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (BackRec.getGlobalBounds().contains(window.mapPixelToCoords
					(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
					{
						m_howToPlayPressed = false;
					}
				}
			}
			window.draw(text);
			window.draw(arrowsSprite);
			window.draw(spaceSprite);
			window.draw(BackRec);
			window.draw(Back);
			window.display();
		}
	}

	window.clear();
}
