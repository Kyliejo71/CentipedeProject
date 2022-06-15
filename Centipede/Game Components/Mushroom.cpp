#include "Mushroom.h"
#include "ScoreManager.h"
#include "EnemyExplosionFactory.h"
#include "SoundManager.h"

void Mushroom::Initialize(sf::Vector2f p, int x, int y, Grid* grid)
{
	Pos = p;
	xPos = x;
	yPos = y;
	myGrid = grid;

	health = 4;

	isPoisoned = false;

	bitmap = &ResourceManager::GetTextureBitmap("Mushroom");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);
	MainSprite.setScale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	SetCollider(MainSprite, *bitmap);

	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
	pBonus = SoundManager::GetSoundCommand(SoundManager::SoundEvents::MushBonus);

	RegisterCollision<Mushroom>(*this);

	SetDrawOrder(-1000);
}
void Mushroom::Update()
{
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}
void Mushroom::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>(*this);
}

void Mushroom::Collision(Bullet* other)
{
	health--;
	if(isPoisoned)
	{
		if (health == 3)
		{
			MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 5, 5);
			MainSprite.setScale(2, 2);
			MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		}
		else if (health == 2)
		{
			MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 6, 6);
			MainSprite.setScale(2, 2);
			MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		}
		else if (health == 1)
		{
			MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 7, 7);
			MainSprite.setScale(2, 2);
			MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		}
		else 
		{
			myGrid->removeShroom(this, xPos, yPos);
			ScoreManager::SendScoreCmd(pDeath);
			MarkForDestroy();
		}
	}
	else
	{
		if (health == 3)
		{
			MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 1);
			MainSprite.setScale(2, 2);
			MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		}
		else if (health == 2)
		{
			MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 2);
			MainSprite.setScale(2, 2);
			MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		}
		else if (health == 1)
		{
			MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 3);
			MainSprite.setScale(2, 2);
			MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		}
		else
		{
			myGrid->removeShroom(this, xPos, yPos);
			ScoreManager::SendScoreCmd(pDeath);
			MarkForDestroy();
		}
	}
}

void Mushroom::Collision(Spider* other)
{
	myGrid->removeShroom(this, xPos, yPos);
	MarkForDestroy();
}

bool Mushroom::isMushPoison()
{
	return isPoisoned;
}

void Mushroom::regenShroom()
{
	SoundManager::SendSoundCmd(pBonus);
	EnemyExplosionFactory::CreateEnemyExplosion(Pos);
	this->health = 4;

	this->isPoisoned = false;

	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);
	MainSprite.setScale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.Update();
	MainSprite.setPosition(Pos);
}

int Mushroom::getHealth()
{
	return this->health;
}

void Mushroom::poisonMe()
{
	isPoisoned = true;
	if (health == 4)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 4, 4);
		MainSprite.setScale(2, 2);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		MainSprite.setPosition(Pos);
		MainSprite.Update();
	}
	else if (health == 3)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 5, 5);
		MainSprite.setScale(2, 2);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		MainSprite.setPosition(Pos);
		MainSprite.Update();
	}
	else if (health == 2)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 6, 6);
		MainSprite.setScale(2, 2);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		MainSprite.setPosition(Pos);
		MainSprite.Update();
	}
	else if (health == 1)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 60.0F, 7, 7);
		MainSprite.setScale(2, 2);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		MainSprite.setPosition(Pos);
		MainSprite.Update();
	}
}
