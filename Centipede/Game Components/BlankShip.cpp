#include "BlankShip.h"

BlankShip::BlankShip(sf::Vector2f Pos)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spaceship"), 1, 1);
	MainSprite.scale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
}

void BlankShip::Update()
{
	MainSprite.Update();
}

void BlankShip::Draw()
{
	WindowManager::Window().draw(MainSprite);
}
