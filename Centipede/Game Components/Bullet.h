// Bullet
// Andre Berthiaume, Aug 2012

#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"
#include "Ship.h"

//Forward declarations
class Mushroom;
class Flea;
class Ship;
class Scorp;
class CentipedeHead;
class CentipedeBody;
class Spider;

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet() = default;
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = default;

	void Initialize(sf::Vector2f p, Ship* ship);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *go){};
	virtual void Collision(Mushroom* other);
	virtual void Collision(Flea* other);
	virtual void Collision(Scorp* other);
	virtual void Collision(CentipedeHead* other);
	virtual void Collision(CentipedeBody* other);
	virtual void Collision(Spider* other);

private:
	float SPEED;

	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	Ship* myShip;
	
};

#endif _Bullet