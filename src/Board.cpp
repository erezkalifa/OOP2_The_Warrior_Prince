#pragma once
#include "Board.h"


enum class ObjectType : char
{
	Player = 'P',
	NormalMonster = 'X',
	Boss = 'B',
	Wall = '#',
	Shield = 'S',
	Armor = 'A',
	TriAttack = 'T'
};


Board::Board()

{	
	m_gridSize = 25;
	m_level = 0;
	m_gold = 0;
	m_nextLevel = false;
	m_normalMonsterValue = 5;
	m_BossValue = 10;
	m_PowerUp = false;
	m_levelAmount = 4;
	readLevels();
	createBoard();

}





void Board::createBoard()
{

	std::ifstream boardFile;
	boardFile.open(m_levelsName[m_level]); 
	auto line = std::string();
	for (size_t i = 0; std::getline(boardFile, line); i++)
	{
		for (size_t j = 0; j < line.size(); j++)
		{

			switch (auto type = line[j])
			{
			case 'P':
				m_player = std::make_unique<Player>(Textures::use().getTexture(textures_type::spriteWalk),
					j * m_gridSize, i * m_gridSize);
				break;

			case 'X':
				m_MovingObjects.emplace_back(std::make_unique<NormalMonster>(Textures::use().getTexture(textures_type::enemySpriteSheet),
					j * m_gridSize, i * m_gridSize));
				break;

			case 'B':
				m_boss.emplace_back(std::make_unique<Boss>(Textures::use().getTexture(textures_type::boss),
					j * m_gridSize, i * m_gridSize));
				break;

			case '#':
					m_staticObjects.emplace_back(std::make_unique<Wall>(Textures::use().getTexture(textures_type::wall),
						j * m_gridSize, i * m_gridSize));
				break;

			case 'S':
				m_shield.emplace_back(std::make_unique<Shield>(Textures::use().getTexture(textures_type::Shield),
					j * m_gridSize, i * m_gridSize));
				break;

			case 'A':
				m_armor.emplace_back(std::make_unique<Armor>(Textures::use().getTexture(textures_type::Armor),
					j * m_gridSize, i * m_gridSize));
				break;

			case 'T':
				m_triAttack.emplace_back(std::make_unique<TriAttack>(Textures::use().getTexture(textures_type::staff),
					j * m_gridSize, i * m_gridSize));
				break;
			}
		}
	}

}


void Board::readLevels() {

	m_levelsName.push_back("level1.txt");
	m_levelsName.push_back("level2.txt");
	m_levelsName.push_back("level3.txt");
	m_levelsName.push_back("level4.txt");
	m_levels = m_levelsName.size();
	m_levelRows = 30;

}


void Board::moveObjects(sf::RenderWindow& window, sf::Event event,
	int counterWalking, float delta, sf::Clock& clock)
{
	movePlayer(window, event, counterWalking, delta, clock);
	moveBoss(window, event, counterWalking, delta, clock);
	moveMonster(window, event, counterWalking, delta, clock);
}

void Board::drawObjects(sf::RenderWindow& window)
{
	drawStatic(window);
	drawArmor(window);
	drawCoins(window);
	drawShield(window);
	drawTriAttack(window);
	
}


void Board::drawStatic(sf::RenderWindow& window)
{
	for (auto& object : m_staticObjects)
		object->draw(window);
}
void Board::drawArmor(sf::RenderWindow& window)
{
	for (auto& armor : m_armor)
		armor->draw(window);
}

void Board::drawShield(sf::RenderWindow& window)
{
	for (auto& shield : m_shield)
		shield->draw(window);
}

void Board::drawTriAttack(sf::RenderWindow& window)
{
	for (auto& triAttack : m_triAttack)
		triAttack->draw(window);
}

void Board::drawCoins(sf::RenderWindow& window)
{
	for (auto& coin : m_coins) {
		coin->draw(window);
	}
}

void Board::moveBoss(sf::RenderWindow& window, sf::Event& event,
	int& counterWalking, float& delta, sf::Clock& clock)
{
	for (auto& boss : m_boss) {
		boss->move(event, counterWalking, delta, clock);
		boss->draw(window);
	}
}


void Board::moveMonster(sf::RenderWindow& window, sf::Event& event,
	int& counterWalking, float& delta, sf::Clock& clock)
{
	for (auto& object : m_MovingObjects) {
		object->move(event, counterWalking, delta, clock);
		object->draw(window);
	}
}



void Board::collision(sf::Time counterTime, sf::Clock& clock)
{


	for (auto& staticObj : m_staticObjects)
	{
		//Player Collides with Wall
		if (staticObj->m_rect.getGlobalBounds().intersects(m_player->m_rect.getGlobalBounds()))
			playerNextMove(m_player->getDirection());

		for (auto& movingObj : m_MovingObjects) {
			//Monsters Collides with Wall
			if (movingObj->m_rect.getGlobalBounds().intersects(staticObj->m_rect.getGlobalBounds())) {
				if (movingObj->getDirection() == 1)
				{
					movingObj->canMoveUp = false;
					movingObj->m_rect.move(0, 1);
				}
				else if (movingObj->getDirection() == 2)
				{
					movingObj->canMoveDown = false;
					movingObj->m_rect.move(0, -1);
				}
				else if (movingObj->getDirection() == 3)
				{
					movingObj->canMoveLeft = false;
					movingObj->m_rect.move(1, 0);
				}
				else if (movingObj->getDirection() == 4)
				{
					movingObj->canMoveRight = false;
					movingObj->m_rect.move(-1, 0);
				}
			}
		}
		for (auto& bossObj : m_boss)
		{

			//Boss collide with Wall
			if (bossObj->m_rect.getGlobalBounds().intersects(staticObj->m_rect.getGlobalBounds()))
			{
				if (bossObj->getDirection() == 1)
				{
					bossObj->canMoveUp = false;
					bossObj->m_rect.move(0, 1);
				}
				else if (bossObj->getDirection() == 2)
				{
					bossObj->canMoveDown = false;
					bossObj->m_rect.move(0, -1);
				}
				else if (bossObj->getDirection() == 3)
				{
					bossObj->canMoveLeft = false;
					bossObj->m_rect.move(1, 0);
				}
				else if (bossObj->getDirection() == 4)
				{
					bossObj->canMoveRight = false;
					bossObj->m_rect.move(-1, 0);
				}
			}

		}

	}

	//Player collide with Monsters
	for (auto& movingObj : m_MovingObjects)
		if (counterTime.asMilliseconds() >= 2.5)
		{
			clock.restart();
			if (movingObj->m_rect.getGlobalBounds().intersects(
				m_player->m_rect.getGlobalBounds()))
			{
				SoundHandle::instance().hit();
				m_player->gotDamage(movingObj->getDamage());
			}
		}

	for (auto& bossObj : m_boss)
		if (counterTime.asMilliseconds() >= 2.5)
		{
			clock.restart();
			if (m_player->m_rect.getGlobalBounds().intersects(
				bossObj->m_rect.getGlobalBounds()))
			{
				SoundHandle::instance().hit();
				m_player->gotDamage(bossObj->getDamage());
			}
		}

	updateBoardData();

}

void Board::updateBoardData()
{
	updateArmor();
	updateShields();
	updateCoins();
	updateTriAttack();
}


void Board::updateTriAttack()
{
	auto counter = 0;

	for (auto& triAttack : m_triAttack) {
		if (m_player->m_rect.getGlobalBounds().intersects(triAttack->m_rect.getGlobalBounds()))
		{
			if (m_gold >= triAttack->getPrice())
			{
				m_gold -= triAttack->getPrice();
				m_PowerUp = true;
				m_triAttack.erase(m_triAttack.begin() + counter);

			}
		}
		counter++;
	}

}

void Board::updateCoins()
{

	for (int index = 0; index < m_coins.size(); index++)
	{
		if (m_player->m_rect.getGlobalBounds().intersects(m_coins[index]->m_rect.getGlobalBounds()))
		{			
			m_gold += m_coins[index]->getValue();
			m_coins.erase(m_coins.begin() + index);
			SoundHandle::instance().coinPickSound();
		}
	}
}


void Board::updateArmor() 
{
	auto counter = 0;
	for (auto& armor : m_armor) {
		if (m_player->m_rect.getGlobalBounds().intersects(armor->m_rect.getGlobalBounds()))
		{
			if (m_gold >= armor->getPrice())
			{
				m_gold -= armor->getPrice();
				m_player->updateArmor(armor->getValue());
				m_armor.erase(m_armor.begin() + counter);

			}
		}
		counter++;
	}
}

void Board::updateShields()
{
	auto counter = 0;
	for (auto& shield : m_shield) {
		if (m_player->m_rect.getGlobalBounds().intersects(shield->m_rect.getGlobalBounds()))
			if (m_gold >= shield->getPrice())
			{
				m_gold -= shield->getPrice();
				m_player->updateArmor(shield->getValue());
				m_shield.erase(m_shield.begin() + counter);

			}
		counter++;
	}
}






void Board::playerNextMove(int direction) {

	switch (direction) {
	case 1:
	{
		m_player->canMoveUp = false;
		m_player->m_rect.move(0, 1);
		break;
	}
	case 2:
	{
		m_player->canMoveDown = false;
		m_player->m_rect.move(0, -1);
		break;
	}
	case 3:
	{
		m_player->canMoveLeft = false;
		m_player->m_rect.move(1, 0);
		break;
	}
	case 4:
	{
		m_player->canMoveRight = false;
		m_player->m_rect.move(-1, 0);
		break;
	}
	
	}

}

void Board::attackFire(sf::Time time, sf::Clock& clock)
{
	if (time.asSeconds() >= 0.1)
	{
		clock.restart();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//If bought the stronger gun
			if (m_PowerUp == true)
			{
				if (m_player->getDirection() == 1)
				{
					fire(0, 15);
					fire(15, 0);
					fire(-15, 0);
					SoundHandle::instance().TriAttack();
				}
				if (m_player->getDirection() == 2)
				{
					fire(0, -15);
					fire(15, 0);
					fire(-15, 0);
					SoundHandle::instance().TriAttack();
				}
				if (m_player->getDirection() == 3)
				{
					fire(15, 0);
					fire(0, 15);
					fire(0, -15);
					SoundHandle::instance().TriAttack();
				}
				if (m_player->getDirection() == 4)
				{
					fire(-15, 0);
					fire(0, 15);
					fire(0, -15);
					SoundHandle::instance().TriAttack();
				}
			}
			else
			{
				//The regualer gun
				fire(0, 0);
				SoundHandle::instance().RegularAttack();
			}
		}
	}
}


void Board::fire(int size1, int size2) {

	projectile.direction = m_player->getDirection();
	projectile.m_rect.setPosition(m_player->m_rect.getPosition().x
		+ m_player->m_rect.getSize().x / 2 - projectile.m_rect.getSize().x / 2 - size1,
		m_player->m_rect.getPosition().y
		+ m_player->m_rect.getSize().y / 2 - projectile.m_rect.getSize().y - size2);
	projectileArray.push_back(projectile);

}


void Board::drawProjectile(sf::RenderWindow& window, int& counter, float delta)
{
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		projectileArray[counter].update(delta);
		window.draw(projectileArray[counter].m_rect);
		counter++;
	}

	counter = 0;
}


void Board::projectileCollide(sf::RenderWindow& window, int& counter, sf::Text& text, bool& isHit,
	sf::Time time, sf::Clock& clock)
{
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		for (int index = 0; index < m_MovingObjects.size(); index++)
		{
			if (projectileArray[counter].m_rect.getGlobalBounds().intersects(
				m_MovingObjects[index]->m_rect.getGlobalBounds()))
			{
				isHit = true;
				text.setPosition(m_MovingObjects[index]->m_rect.getPosition().x,
					m_MovingObjects[index]->m_rect.getPosition().y);
			}
			if (time.asMilliseconds() >= 20)
			{
				clock.restart();

				if (projectileArray[counter].m_rect.getGlobalBounds().intersects(
					m_MovingObjects[index]->m_rect.getGlobalBounds()))
				{
					m_MovingObjects[index]->gotDamage(m_player->getDamage());
				}
			}
			if (m_MovingObjects[index]->getHP() <= 0)
			{
				m_coins.push_back(std::make_shared<Coin>(Textures::use().getTexture(textures_type::goldCoin),
					m_MovingObjects[index]->m_rect.getPosition().x, m_MovingObjects[index]->m_rect.getPosition().y, m_normalMonsterValue));
				m_MovingObjects.erase(m_MovingObjects.begin() + index);
			}
		}
		counter++;
	}
	counter = 0;
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		for (int index = 0; index < m_boss.size(); index++)
		{
			if (projectileArray[counter].m_rect.getGlobalBounds().intersects(
				m_boss[index]->m_rect.getGlobalBounds()))
			{
				isHit = true;
				text.setPosition(m_boss[index]->m_rect.getPosition().x,
					m_boss[index]->m_rect.getPosition().y);
			}
			if (time.asMilliseconds() >= 30)
			{
				clock.restart();

				if (projectileArray[counter].m_rect.getGlobalBounds().intersects(
					m_boss[index]->m_rect.getGlobalBounds()))
				{
					m_boss[index]->gotDamage(m_player->getDamage());
				}
				if (m_boss[index]->getHP() <= 0)
				{
					m_coins.push_back(std::make_shared<Coin>(Textures::use().getTexture(textures_type::goldCoin),
						m_boss[index]->m_rect.getPosition().x, m_boss[index]->m_rect.getPosition().y, m_BossValue));
					m_boss.erase(m_boss.begin() + index);
				}
			}
		}
		counter++;
	}
	counter = 0;
}

std::stringstream Board::updateData()
{
	
	std::stringstream ss;
	ss << "HP: " << m_player->getHP() << " / " << m_player->getArmor()
		<< std::endl << "Gold: " << m_gold << std::endl
		<< "Level: " << (m_level + 1);
	return ss;
	
}

void Board::projectileErase(int& counter)
{
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		if (projectileArray[counter].m_rect.getPosition().x > 1200 ||
			projectileArray[counter].m_rect.getPosition().y > 800)
		{
			projectileArray.erase(iter);
			break;
		}
		counter++;
	}

	counter = 0;
}

void Board::animationCounter(int& counter)
{
	if (counter == 2)
	{
		counter = 0;
	}
}

void Board::movePlayer(sf::RenderWindow& window, sf::Event event,
	int counterWalking, float delta, sf::Clock& clock)
{
	m_player->move(event, counterWalking, delta, clock);
	m_player->draw(window);
}

int Board::getDamagePlayer()
{
	return m_player->getDamage();
}

bool Board::checkIfNextLevel()
{
	if (m_MovingObjects.size() == 0 && m_boss.size() == 0)
	{
		return m_nextLevel = true;
	}
	return false;
}

bool Board::moveToNextLevel(sf::RenderWindow& window, Gate& gate)
{
	
	if (m_player->m_rect.getGlobalBounds().intersects(gate.m_rect.getGlobalBounds()))
	{
		m_PowerUp = false;

		if (m_level < (m_levelAmount-1))
		{			
			SoundHandle::instance().pauseMenuSound();
			SoundHandle::instance().nextLevel();
			m_level++;
			m_nextLevel = false;
			nextLevel();
			return true;
		}
		else
			winningScreen(window);
	}
	return false;
}


void Board::nextLevel()
{
	resetData();
}


void Board::resetData()
{
	
	BossProjectileArray.clear();
	m_staticObjects.clear();
	m_MovingObjects.clear();
	m_player = NULL;
	m_boss.clear();
	m_armor.clear();
	m_shield.clear();
	m_coins.clear();
	m_triAttack.clear();

	createBoard();

}

bool Board::CheckIfGameNotOver(sf::RenderWindow& window)
{
	if (m_player->getHP() <= 0)
	{

		if (endingScreen(window)) {
			resetData();
			return true;
		}
	}
	return false;
}


void Board::winningScreen(sf::RenderWindow& window)
{
	window.clear();

	SoundHandle::instance().pauseMenuSound();
	SoundHandle::instance().winGame();

	sf::Texture winningTexture;
	winningTexture = Textures::use().getTexture(textures_type::winningGame);
	sf::Sprite winningSprite(winningTexture);



	sf::Font font;
	font.loadFromFile("ARCADECLASSIC.TTF");

	sf::RectangleShape playAgainRec = setShapeProp(200,
		500, sf::Color::Transparent, sf::Vector2f(220, 60));

	sf::RectangleShape exitRec = setShapeProp(550, 500, sf::Color::Transparent,
		sf::Vector2f(100, 60));

	sf::Text playAgainText = setFontProp(font, "play Again",
		200, 500, 40, sf::Color::Green);

	sf::Text exitText = setFontProp(font, "Exit", 550, 500, 40, sf::Color::Red);

	while (window.isOpen())
	{
	
		window.draw(playAgainRec);
		window.draw(exitRec);
		window.draw(playAgainText);
		window.draw(exitText);
		window.draw(winningSprite);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				exitRec.getGlobalBounds().contains(window.mapPixelToCoords
				(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
				window.close();


			if (playAgainRec.getGlobalBounds().contains(window.mapPixelToCoords
			(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
			{
				resetGameData();
			}

		}

		window.clear();
	}
}


bool Board::endingScreen(sf::RenderWindow& window)
{
	SoundHandle::instance().pauseMenuSound();
	SoundHandle::instance().gameOver();

	window.clear();
	sf::Texture gameOverTexture;

	gameOverTexture = Textures::use().getTexture(textures_type::gameOver);
	sf::Sprite gameOverSprite(gameOverTexture);

	sf::RectangleShape YesRec = setShapeProp(400, 600, sf::Color::Transparent,
		sf::Vector2f(100, 60));

	sf::RectangleShape NoRec = setShapeProp(700, 600, sf::Color::Transparent,
		sf::Vector2f(100, 60));


	
	while (window.isOpen())
	{
		window.draw(gameOverSprite);
		window.draw(YesRec);
		window.draw(NoRec);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
				NoRec.getGlobalBounds().contains(window.mapPixelToCoords
				(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
				window.close();


			if (YesRec.getGlobalBounds().contains(window.mapPixelToCoords
				(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
				return true;
			
		}
		window.clear();
		
	}

	return false;
}


void Board::resetGameData()
{
	resetData();
	m_level = 0;
	m_gold = 0;
	m_nextLevel = false;
	m_normalMonsterValue = 5;
	m_BossValue = 10;
	m_PowerUp = false;
	m_levelAmount = 4;

}
