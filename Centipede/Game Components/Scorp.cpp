#include "Scorp.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "CritterManager.h"
#include "EnemyExplosionFactory.h"

void Scorp::Initialize(sf::Vector2f p, Grid* grid, bool isRightw, int s)
{
	Pos = p;
	myGrid = grid;
	isRight = isRightw;

	speed = s;

	STOP = false;

	bitmap = &ResourceManager::GetTextureBitmap("Scorp");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorp"), 4, 1, 10.0F, 0, 3, true, true);

	if(isRight)
	{
		MainSprite.setScale(2, 2);
	}
	else
	{
		MainSprite.setScale(-2, 2);
	}
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	SetCollider(MainSprite, *bitmap);



	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::ScorpionKilled);
	pStartSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::NewScorp);
	pDeathSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::EnemyDeath);

	SoundManager::SendSoundCmd(pStartSound);
	CritterManager::AddCritter(this);

	RegisterCollision<Scorp>(*this);
}

void Scorp::Update()
{
	if (!STOP)
	{
		if (isRight == true)
		{
			Pos.x -= Game::FrameTime() * speed;
			myGrid->scorpMovingThrough(Pos);
		}
		else
		{
			Pos.x += Game::FrameTime() * speed;
			myGrid->scorpMovingThrough(Pos);
		}
	}

	if (Pos.x > WindowManager::Window().getSize().x|| Pos.x < 0) MarkForDestroy();

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Scorp::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Scorp::Destroy()
{
	DeregisterCollision<Scorp>(*this);
}

void Scorp::Collision(Bullet* other)
{
	EnemyExplosionFactory::CreateEnemyExplosion(Pos);
	ScoreManager::SendScoreCmd(pDeath);
	SoundManager::SendSoundCmd(pDeathSound);
	CritterManager::RemoveCritter(this);
	MarkForDestroy();
}
