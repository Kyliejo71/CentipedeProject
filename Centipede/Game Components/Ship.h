#ifndef _Ship
#define _Ship

#include "TEAL\CommonElements.h"

class Mushroom;
class CmdSound;
class Spider;
class CentipedeBody;
class CentipedeHead;
class Flea;
class ShipStrategy;
class ShootStrategy;

class Ship : public GameObject
{
public:
	Ship() = default;
	~Ship() = default;
	Ship(const Ship&) = delete;
	Ship& operator=(const Ship&) = default;

	void Initialize(ShipStrategy* newStrat);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Spider* other);
	virtual void Collision(CentipedeBody* other);
	virtual void Collision(CentipedeHead* other);
	virtual void Collision(Flea* other);

	sf::Vector2f getpos();
	void attractorMode();
	void keyboardMode();
	void shootBullet();
	void setShootStrategy(ShootStrategy* newStrat);

	virtual void Alarm0();

private:

	int playerArea;
	int attractorRan;

	float SPEED;
	float HBORDER;
	float TBORDER;
	sf::Vector2f GunOffset_top;

	float offset;

	sf::Vector2f startingPos;
	sf::Vector2f Pos;
	sf::Vector2f Impulse;
	sf::Vector2f PrevPos;


	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	bool colliding;

	bool Attractor;

	CmdSound* pShot1;
	CmdSound* pShot2;
	CmdSound* pPlayerDeath;

	ShipStrategy* pStrategy;
	ShootStrategy* pShootStrat;
};

#endif _Ship
