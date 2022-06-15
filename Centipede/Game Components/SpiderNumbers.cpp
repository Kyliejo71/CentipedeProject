#include "SpiderNumbers.h"

void SpiderNumbers::Initialize(sf::Vector2f p, int value)
{
	if (value == 900)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("SheetForNumbers"), 14, 77);
		MainSprite.SetAnimation(34, 34);
		MainSprite.scale(3, 3);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		MainSprite.setPosition(p);
	}
	else if (value == 600)
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("SheetForNumbers"), 14, 77);
		MainSprite.SetAnimation(20, 20);
		MainSprite.scale(3, 3);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		MainSprite.setPosition(p);
	}
	else
	{
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("SheetForNumbers"), 14, 77);
		MainSprite.SetAnimation(6, 6);
		MainSprite.scale(3, 3);
		MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
		MainSprite.setPosition(p);
	}
	SetAlarm(0, 1);
}

void SpiderNumbers::Update()
{
	MainSprite.Update();
}

void SpiderNumbers::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void SpiderNumbers::Alarm0()
{
	MarkForDestroy();
}
