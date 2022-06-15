#ifndef _Spider
#define _Spider

#include "TEAL\CommonElements.h"
#include "Grid.h"
#include "Critter.h"

class Bullet;
class Grid;
class CmdScore;
class CmdSound;

class Spider : public Critter
{
public:
	Spider() = default;
	~Spider() = default;
	Spider(const Spider&) = delete;
	Spider& operator=(const Spider&) = default;

	void Initialize(sf::Vector2f p, Grid* grid, bool isRight, int speed);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Bullet* other);

	virtual void Alarm3();

private:

	Grid* myGrid;

	int speed;

	bool isRight;

	int direction;
	int upperLimit;
	int lowerLimit;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;

	CmdScore* pDeath;
	CmdSound* pStartSound;
	CmdSound* pDeathSound;
};

#endif _Spider
