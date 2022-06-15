#include "EnemyExplosions.h"

void EnemyExplosions::Initialize(sf::Vector2f p)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("EnemyExplosion"), 3, 2, 60);
	MainSprite.SetAnimation(0, 5);
	MainSprite.scale(4, 4);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(p);
}

void EnemyExplosions::Update()
{
	if (MainSprite.IsLastAnimationFrame())
	{
		MarkForDestroy();
	}

	MainSprite.Update();
}

void EnemyExplosions::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
