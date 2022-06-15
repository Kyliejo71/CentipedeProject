// Bullet
// Andre Berthiaume, Aug 2012

#include "Bullet.h"
#include "GameController.h"
#include "ShootStrategyNo.h"
#include "ShootStrategyYes.h"
	
Bullet::Bullet()
{
	SPEED = 30;

	bitmap = ResourceManager::GetTextureBitmap("Shots");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Shots"), 1, 1, 120);
	MainSprite.setScale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	SetCollider(MainSprite, bitmap);
}

void Bullet::Initialize(sf::Vector2f p, Ship* ship)
{
	Pos = p;
	myShip = ship;
	myShip->setShootStrategy(new ShootStrategyNo());
	RegisterCollision<Bullet>(*this);
}

void Bullet::Update()
{
	MainSprite.Update();

	Pos.y -= SPEED;

	if (Pos.y <= GameController::TopOfScreen ) MarkForDestroy();

	MainSprite.setPosition(Pos);
}

void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Bullet::Destroy()
{
	myShip->setShootStrategy(new ShootStrategyYes());
	DeregisterCollision<Bullet>( *this );
}

void Bullet::Collision(Mushroom* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Flea* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Scorp* other)
{
	MarkForDestroy();
}

void Bullet::Collision(CentipedeHead* other)
{
	MarkForDestroy();
}

void Bullet::Collision(CentipedeBody* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Spider* other)
{
	MarkForDestroy();
}
