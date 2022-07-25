#pragma once
#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(1200, 800), "The Warrior Prince"),
	m_background(Textures::use().getTexture(textures_type::background))
{}

void Controller::run() {

	while (m_window.isOpen())
	{
		m_isPlaying ? runGame() : runMenu();
	}
}



void Controller::runMenu()
{
	m_menu.openMenu(m_window);
	m_isPlaying = true;
}

void Controller::runGame()
{

	m_window.clear();

	Fonts fonts;
	m_fonts = fonts.getFonts();

	sf::Font font;
	font = m_fonts[0];

	DataText.setFont(font);

	createDataText();

	int counterWalking = 0, projectileCounter = 0;

	sf::Clock clock , textClock, DamageClock;
	sf::Time counterTime, textTime, DamageTime;


	sf::Text damageText = setFontProp(font, std::to_string(m_board.getDamagePlayer()),
		200, 400, 40, sf::Color::Red);

	bool isHit = false;

	sf::Clock clockCheck, projectileClock, ProClock;
	sf::Time projectileTime, ProTime;

	Gate gate(Textures::use().getTexture(textures_type::gate), m_window.getSize().x / 2, m_window.getSize().y / 2);

	if (SoundHandle::instance().getSoundStatus())
		SoundHandle::instance().startGameMusic();

	while (m_window.isOpen())
	{
		projectileCounter = 0;
		m_window.clear();
		auto event = sf::Event{};

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

	
		m_window.draw(m_background);
		

		DataText.setString(m_board.updateData().str());

		m_window.draw(DataText);

		m_board.drawObjects(m_window);

		if (m_board.checkIfNextLevel()) {		
			gate.draw(m_window);
			if(m_board.moveToNextLevel(m_window, gate)){
				m_isPlaying = true;
					return;
			}
		}
		
		if (m_board.CheckIfGameNotOver(m_window)) {
			m_isPlaying = true;
			return;
		}

		//update Time
		counterTime = clock.getElapsedTime();
		textTime = textClock.getElapsedTime();
		DamageTime = DamageClock.getElapsedTime();
		float delta = clockCheck.getElapsedTime().asMilliseconds();
		projectileTime = projectileClock.getElapsedTime();
		ProTime = ProClock.getElapsedTime();

		//Move Objects
		m_board.moveObjects(m_window, event, counterWalking, delta, clockCheck);
		
		m_board.collision(counterTime, clock);

		//Attack
		m_board.attackFire(ProTime, ProClock);
		
		//Draw Projectile
		m_board.drawProjectile(m_window, projectileCounter, delta);

		//hit the enemy collistion
		m_board.projectileCollide(m_window, projectileCounter, damageText, isHit, DamageTime, DamageClock);

		//projectile hit ememy text
		if (textTime.asSeconds() >= 0.5)
		{
			clock.restart();
			if (isHit == true)
			{
				damageText.move(0, -0.5);
				m_window.draw(damageText);
			}
		}
		else
		{
			isHit = false;

		}

		
		m_board.projectileErase(projectileCounter);

		counterWalking++;
		m_board.animationCounter(counterWalking);

		m_window.display();
	}
}


void Controller::createDataText()
{
	DataText.setPosition(0, 0);
	DataText.setCharacterSize(30);
	DataText.setColor(sf::Color::White);
}

