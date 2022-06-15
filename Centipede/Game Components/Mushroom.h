#pragma once

#ifndef _Mushroom
#define _Mushroom

#include "TEAL\CommonElements.h"
#include "Grid.h"

class Bullet;
class Grid;
class Spider;
class Scorp;
class CmdScore;
class CmdSound;

class Mushroom : public GameObject
{
public:
	Mushroom() = default;
	~Mushroom() = default;
	Mushroom(const Mushroom&) = delete;
	Mushroom& operator=(const Mushroom&) = default;

	void Initialize(sf::Vector2f p, int x, int y, Grid* grid);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet *other);
	virtual void Collision(Spider *other);

	bool isMushPoison();

	void regenShroom();
	int getHealth();
	void poisonMe();

private:

	bool isPoisoned;

	int health;
	int xPos;
	int yPos;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;

	Grid *myGrid;

	CmdScore* pDeath;
	CmdSound* pBonus;
};

#endif _Mushroom