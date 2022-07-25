#pragma once
#include "MovingObjects.h"
class gameObject;
class StaticObject;

class Player : public MovingObjects
{
public:

	Player(const sf::Texture& texture, int x, int y);
	virtual void draw(sf::RenderWindow& window);
	virtual void move(sf::Event& event, int& counterWalking, float& delta, sf::Clock& clock);
	sf::Vector2f getPosition();
	sf::Vector2f getNextStep();
	virtual int getDirection();
	virtual void gotDamage(int damage);
	int getDamage();
	void updateDamage(int damageBonus);
	void updateArmor(int armorBonus);
	virtual int getHP();
	int getArmor();

	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;

private:
	
	sf::Sprite m_sprite;

	float m_movementSpeed;
	int m_damage;
	int m_direction; // 1 = Up, 2 = Down, 3 = Left, 4 = Right
	int m_hp;
	int m_armor;
};