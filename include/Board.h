#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Objects/StaticObjects/Wall.h"
#include "Objects/MovingObjects/Player.h"
#include "Projectile.h"
#include "Objects/MovingObjects/Monsters/NormalMonster.h"
#include "Objects/MovingObjects/MovingObjects.h"
#include "FileManager/Fonts.h"
#include "Objects/StaticObjects/Coin.h"
#include "Objects/StaticObjects/Gate.h"
#include "Objects/MovingObjects/Monsters/Boss.h"
#include "Objects/StaticObjects/Armor.h"
#include "Objects/StaticObjects/Shield.h"
#include "Menu.h"
#include "TriAttack.h"
#include "FileManager/Textures.h"
#include "FileManager/SoundHandle.h"




class Board
{
public:
	Board();
	void createBoard();
	
	std::stringstream updateData();
	void moveObjects(sf::RenderWindow& window, sf::Event event,
		int counterWalking, float delta, sf::Clock& clock);
	
	int getDamagePlayer();
	
	void drawObjects(sf::RenderWindow& window);
	
	void collision(sf::Time counterTime, sf::Clock& clock);
	void attackFire(sf::Time time, sf::Clock& clock);
	void fire(int size1, int size2);
	void drawProjectile(sf::RenderWindow& window, int& counter, float delta);
	void projectileCollide(sf::RenderWindow& window, int& counter, sf::Text& text, bool& isHit,
		sf::Time time, sf::Clock& clock);
	void projectileErase(int& counter);
	void animationCounter(int& counter);
	bool checkIfNextLevel();
	bool moveToNextLevel(sf::RenderWindow& window, Gate& gate);
	bool CheckIfGameNotOver(sf::RenderWindow& window);

private:

	void resetGameData();

	//Draw objects
	void drawCoins(sf::RenderWindow& window);
	void drawArmor(sf::RenderWindow& window);
	void drawShield(sf::RenderWindow& window);
	void drawTriAttack(sf::RenderWindow& window);
	void drawStatic(sf::RenderWindow& window);

	//Move objects
	void movePlayer(sf::RenderWindow& window, sf::Event event,
		int counterWalking, float delta, sf::Clock& clock);
	void moveBoss(sf::RenderWindow& window, sf::Event& event,
		int& counterWalking, float& delta, sf::Clock& clock);
	void moveMonster(sf::RenderWindow& window, sf::Event& event,
		int& counterWalking, float& delta, sf::Clock& clock);

	void updateBoardData();
	void updateArmor();
	void updateShields();
	void updateCoins();
	void updateTriAttack();

	bool endingScreen(sf::RenderWindow& window);
	void winningScreen(sf::RenderWindow& window);
	void nextLevel();
	void resetData();

	void playerNextMove(int direction);
	void readLevels();

	int m_levels;
	int m_levelRows;
	bool m_PowerUp;

	std::vector<std::string> m_levelsName;

	Projectile projectile;
	std::vector<Projectile>::const_iterator iter;
	std::vector<Projectile> projectileArray; 
	std::vector<Projectile>::const_iterator iterBoss;
	std::vector<Projectile> BossProjectileArray;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;
	std::vector<std::shared_ptr<NormalMonster>> m_MovingObjects;
	std::unique_ptr<Player> m_player;
	std::vector<std::unique_ptr<Boss>> m_boss;
	std::vector<std::unique_ptr<Armor>> m_armor;
	std::vector<std::unique_ptr<Shield>> m_shield;
	std::vector<std::unique_ptr<TriAttack>> m_triAttack;
	std::vector<std::shared_ptr<Coin>> m_coins;

	int m_gridSize;
	int m_level;
	int m_gold;
	bool m_nextLevel;
	int m_normalMonsterValue;
	int m_BossValue;
	int m_levelAmount;

	sf::Text DataText;

};