#include "PlayerExplosions.h"
#include "PlayerManager.h"

void PlayerExplosions::Initialize(sf::Vector2f p)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("PlayerExplosion"), 4, 2, 20);
	MainSprite.SetAnimation(0, 7);
	MainSprite.scale(4, 4);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(p);
}

void PlayerExplosions::Update()
{
	if (MainSprite.IsLastAnimationFrame())
	{
		PlayerManager::removeLife();
		MarkForDestroy();
	}

	MainSprite.Update();
}

void PlayerExplosions::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
