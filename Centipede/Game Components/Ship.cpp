#include "Ship.h"
#include "Bullet.h"
#include "GameController.h"
#include "BulletFactory.h"
#include "SoundManager.h"
#include "PlayerExplosionFactory.h"
#include "ShipStrategy.h"
#include "ShootStrategy.h"
#include "ShootStrategyYes.h"

void Ship::Destroy()
{
	AlarmCancel(0);
	DeregisterInput();
	DeregisterCollision<Ship>(*this);
}

void Ship::Initialize(ShipStrategy* newStrat)
{
	playerArea = 192;

	SPEED = 7;
	HBORDER = 15;
	TBORDER = 600;

	GunOffset_top = sf::Vector2f(0, -15);

	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spaceship"), 1, 1);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);
	MainSprite.setPosition(Pos);

	startingPos = sf::Vector2f(480, 976);
	Pos = startingPos;
	Impulse = sf::Vector2f(0, 0);

	bitmap = ResourceManager::GetTextureBitmap("Spaceship");
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Ship>(*this);

	SetDrawOrder(1000);

	RegisterInput(InputFlags::KeyPressed); // Recieve single-presses events

	colliding = false;
	Attractor = false;
	PrevPos = Pos;

	pShot1 = SoundManager::GetSoundCommand(SoundManager::SoundEvents::Shot1);
	pShot2 = SoundManager::GetSoundCommand(SoundManager::SoundEvents::Shot2);
	pPlayerDeath = SoundManager::GetSoundCommand(SoundManager::SoundEvents::PlayerDeath);

	pStrategy = newStrat;
	pShootStrat = new ShootStrategyYes();

	SetAlarm(0, 0.2);
}

void Ship::Update()
{
	pStrategy->pickShipMode(this);
	pShootStrat->doIShoot(this);

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Ship::Collision(Mushroom* other)
{
	colliding = true;
	Pos = PrevPos;
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Ship::Collision(Spider* other)
{
	PlayerExplosionFactory::CreatePlayerExplosion(Pos);
	SoundManager::SendSoundCmd(pPlayerDeath);
	MarkForDestroy();
}

void Ship::Collision(CentipedeBody* other)
{
	PlayerExplosionFactory::CreatePlayerExplosion(Pos);
	SoundManager::SendSoundCmd(pPlayerDeath);
	MarkForDestroy();
}

void Ship::Collision(CentipedeHead* other)
{
	PlayerExplosionFactory::CreatePlayerExplosion(Pos);
	SoundManager::SendSoundCmd(pPlayerDeath);
	MarkForDestroy();;
}

void Ship::Collision(Flea* other)
{
	PlayerExplosionFactory::CreatePlayerExplosion(Pos);
	SoundManager::SendSoundCmd(pPlayerDeath);
	MarkForDestroy();
}

sf::Vector2f Ship::getpos()
{
	return Pos;
}

void Ship::keyboardMode()
{
	Attractor = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) Impulse += sf::Vector2f(-SPEED, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) Impulse += sf::Vector2f(SPEED, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) Impulse += sf::Vector2f(0, -SPEED);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) Impulse += sf::Vector2f(0, SPEED);

	Pos += Impulse;
	Tools::Clamp<float>(Pos.x, (float)MainSprite.getTextureRect().width, WindowManager::Window().getView().getSize().x);
	Tools::Clamp<float>(Pos.y, GameController::PlayerAreaTop - GameController::HalfScreenMult, GameController::BottomOfShrooms - GameController::HalfScreenMult);

	if (!colliding)
	{
		PrevPos = Pos;
	}
	colliding = false;

	Impulse = sf::Vector2f(0, 0);
}

void Ship::shootBullet()
{
	int ran = rand() % 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || Attractor)
	{
		BulletFactory::CreateBullet(Pos + GunOffset_top, this);
		if (ran == 0)
		{
			SoundManager::SendSoundCmd(pShot1);
		}
		else
		{
			SoundManager::SendSoundCmd(pShot2);
		}
	}
}

void Ship::setShootStrategy(ShootStrategy* newStrat)
{
	this->pShootStrat = newStrat;
}

void Ship::attractorMode()
{
	Attractor = true;
	switch (attractorRan)
	{
	case 0:		//LEFT
		Impulse += sf::Vector2f(-SPEED, 0);
		break;
	case 1:		//RIGHT	
		Impulse += sf::Vector2f(SPEED, 0);
		break;
	case 2:		//UP
		Impulse += sf::Vector2f(0, -SPEED);
		break;
	case 3:		//DOWN
		Impulse += sf::Vector2f(0, SPEED);
		break;
	default:
		break;
	}

	Pos += Impulse;
	Tools::Clamp<float>(Pos.x, (float)MainSprite.getTextureRect().width, WindowManager::Window().getView().getSize().x);
	Tools::Clamp<float>(Pos.y, GameController::PlayerAreaTop - GameController::HalfScreenMult, GameController::BottomOfShrooms - GameController::HalfScreenMult);

	if (!colliding)
	{
		PrevPos = Pos;
	}
	colliding = false;

	Impulse = sf::Vector2f(0, 0);

	int ran = rand() % 2;
}

void Ship::Alarm0()
{
	attractorRan = rand() % 3;
	SetAlarm(0, 0.2);
}

void Ship::Draw()
{
	WindowManager::Window().draw(MainSprite);
}