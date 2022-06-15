#include "Flea.h"
#include "GameController.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "CritterManager.h"
#include "EnemyExplosionFactory.h"

void Flea::Initialize(sf::Vector2f p, Grid* grid)
{
	Pos = p;
	myGrid = grid;

	health = 2;
	speed = 350;

	STOP = false;

	bitmap = &ResourceManager::GetTextureBitmap("Flea");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2, 10.0F, 0, 3, true, true);

	MainSprite.setScale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	SetCollider(MainSprite, *bitmap);

	speedMult = 100;

	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);
	pStartSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::NewFlea);
	pDeathSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::EnemyDeath);

	SoundManager::SendSoundCmd(pStartSound);

	CritterManager::AddCritter(this);

	RegisterCollision<Flea>(*this);
}

void Flea::Update()
{
	if (!STOP)
	{
		Pos.y += Game::FrameTime() * speed;
	}

	if (Pos.y > GameController::BottomOfScreen) MarkForDestroy();

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Flea::Destroy()
{
	DeregisterCollision<Flea>(*this);
}

void Flea::Collision(Bullet* other)
{
	health--;
	if(health == 1)
	{
		this->myGrid->noMoreShrooms();
		speed += speedMult;
	}
	else if(health <= 0)
	{
		EnemyExplosionFactory::CreateEnemyExplosion(Pos);
		ScoreManager::SendScoreCmd(pDeath);
		SoundManager::SendSoundCmd(pDeathSound);
		CritterManager::RemoveCritter(this);
		MarkForDestroy();
	}

}
