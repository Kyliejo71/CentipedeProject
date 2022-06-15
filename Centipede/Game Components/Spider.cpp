#include "Spider.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "CritterManager.h"
#include "EnemyExplosionFactory.h"
#include "GameController.h"

void Spider::Initialize(sf::Vector2f p, Grid* grid, bool isRightw, int s)
{
	Pos = p;
	myGrid = grid;
	isRight = isRightw;

	speed = s;

	direction = 4;

	STOP = false;

	upperLimit = 800;
	lowerLimit = 900;

	bitmap = &ResourceManager::GetTextureBitmap("Spider");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2, 10.0F, 0, 7, true, true);

	MainSprite.setScale(4, 4);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	SetCollider(MainSprite, *bitmap);

	RegisterCollision<Spider>(*this);
	SetAlarm(3, 1);

	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled);
	pStartSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::NewSpider);
	pDeathSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::EnemyDeath);

	SoundManager::SendSoundCmd(pStartSound);
	CritterManager::AddCritter(this);
	CritterManager::addSpiders();
	MainSprite.setPosition(Pos);
}

void Spider::Update()
{

	if (Pos.x > WindowManager::Window().getSize().x || Pos.x < 0) 
	{
		MarkForDestroy();
		CritterManager::removeSpiders();
	} 

	if (!STOP)
	{
		if (direction == 0) //up
		{
			Pos.y -= Game::FrameTime() * speed;
		}
		else if (direction == 1) //Down
		{
			Pos.y += Game::FrameTime() * speed;
		}
		else if (direction == 2) //Up Dia
		{
			if (isRight)
			{
				Pos.y -= Game::FrameTime() * speed;
				Pos.x -= Game::FrameTime() * speed;
			}
			else
			{
				Pos.y -= Game::FrameTime() * speed;
				Pos.x += Game::FrameTime() * speed;
			}
		}
		else if (direction == 3) //Down Dia
		{
			if (isRight)
			{
				Pos.y += Game::FrameTime() * speed;
				Pos.x -= Game::FrameTime() * speed;
			}
			else
			{
				Pos.y += Game::FrameTime() * speed;
				Pos.x += Game::FrameTime() * speed;
			}
		}
		else if (direction == 4) //Straight side
		{
			if (isRight)
			{
				Pos.x -= Game::FrameTime() * speed;
			}
			else
			{
				Pos.x += Game::FrameTime() * speed;
			}
		}
	}
	

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Spider::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Spider::Destroy()
{
	AlarmCancel(3);
	DeregisterCollision<Spider>(*this);
}

void Spider::Collision(Bullet* other)
{
	GameController::setSpiderDeathPos(Pos); //Sends death Pos to be used in score calc
	EnemyExplosionFactory::CreateEnemyExplosion(Pos);
	ScoreManager::SendScoreCmd(pDeath);
	SoundManager::SendSoundCmd(pDeathSound);
	CritterManager::RemoveCritter(this);
	CritterManager::removeSpiders();
	MarkForDestroy();
}

void Spider::Alarm3()
{
	// 0 = up, 1 = down, 2 = updia, 3 = downdia, 4 = side

	if(Pos.y < upperLimit)
	{
		direction = 1;
	}
	else if(Pos.y > lowerLimit)
	{
		direction = 0;
	}
	else
	{
		direction = rand() % 5;
	}
	float length = (float)(rand() % 1 + 0.5);
	SetAlarm(3, length);
}
