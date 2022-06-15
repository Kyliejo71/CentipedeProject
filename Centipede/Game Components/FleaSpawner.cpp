#include "FleaSpawner.h"
#include "FleaFactory.h"
#include "GameController.h"

FleaSpawner::FleaSpawner(Grid* grid)
	: myGrid(grid)
{

	col = 0;
	triggerVal = 0;
	spawnProb = 0;
}

void FleaSpawner::startSpawning(int trigVal, int spawn, Grid* newGrid)
{
	myGrid = newGrid;

	triggerVal = trigVal;
	spawnProb = spawn;

	SetAlarm(0, 2);
}

void FleaSpawner::stopSpawning()
{
	AlarmCancel(0);
}

void FleaSpawner::Alarm0()
{
	if (myGrid->playerAreaShrooms(triggerVal))
	{
		col = rand() % GameController::GridW;
		myGrid->startAddingShrooms();
		myGrid->addShroomFlea(col, 0, spawnProb);

		FleaFactory::CreateFlea(sf::Vector2f((float)((col * GameController::ScreenMult) + GameController::ScreenMult), 10.0f), myGrid);

	}
	SetAlarm(0, 5);
}
