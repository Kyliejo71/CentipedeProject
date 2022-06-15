#ifndef _Scorp
#define _Scorp

#include "TEAL\CommonElements.h"
#include "Grid.h"
#include "Critter.h"

class Bullet;
class Grid;
class CmdScore;
class CmdSound;

class Scorp : public Critter
{
public:
	Scorp() = default;
	~Scorp() = default;
	Scorp(const Scorp&) = delete;
	Scorp& operator=(const Scorp&) = default;

	void Initialize(sf::Vector2f p, Grid* grid, bool isRight, int speed);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Bullet* other);

private:

	Grid* myGrid;

	int speed;

	sf::Vector2f Pos;

	bool isRight;

	CmdScore* pDeath;
	CmdSound* pStartSound;
	CmdSound* pDeathSound;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;
};

#endif _Scorp