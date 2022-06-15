#include "SpiderSpawner.h"
#include "SpiderFactory.h"
#include "GameController.h"
#include "SoundManager.h"

SpiderSpawner::SpiderSpawner(Grid* grid)
	:myGrid(grid)
{
	whichWay = 0;
	xPos = 0;
	yPos = 0;

	spawnRate = 0;
	speed = 0;

	pSpiderSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::SpiderSound);
}

void SpiderSpawner::startSpawning(int sSpeed, int spawn, Grid* newGrid)
{
	myGrid = newGrid;

	speed = sSpeed;
	spawnRate = spawn;

	SetAlarm(2, (float)spawnRate);
}

void SpiderSpawner::stopSpawning()
{
	AlarmCancel(2);
}

void SpiderSpawner::Alarm2()
{
	whichWay = rand() % 2;
	yPos = rand() % 700 + 600;
	bool isRight;
	if(whichWay == 0)
	{
		isRight = false;
		xPos = 10;
		//left	
	}
	else
	{
		isRight = true;
		xPos = GameController::RightOfScreen - 10;
		//right
	}
	if(yPos > 700)
	{
		yPos = 700;
	}
	SpiderFactory::CreateSpider(sf::Vector2f((float)xPos, (float)yPos), myGrid, isRight, speed);
	SoundManager::SendSoundCmd(pSpiderSound);

	SetAlarm(2, (float)(spawnRate * 2)); // after first, spiders don't show up as often
}
