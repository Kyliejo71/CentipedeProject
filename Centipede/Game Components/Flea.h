#ifndef _Flea
#define _Flea

#include "TEAL\CommonElements.h"
#include "Grid.h"
#include "Critter.h"

class Bullet;
class Grid;
class CmdScore;
class CmdSound;

class Flea : public Critter
{
public:
	Flea() = default;
	~Flea() = default;
	Flea(const Flea&) = delete;
	Flea& operator=(const Flea&) = default;

	void Initialize(sf::Vector2f p, Grid* grid);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Bullet* other);

private:

	Grid* myGrid;

	float health;
	float speed;
	float speedMult;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;

	CmdScore* pDeath;
	CmdSound* pStartSound;
	CmdSound* pDeathSound;
};

#endif _Flea