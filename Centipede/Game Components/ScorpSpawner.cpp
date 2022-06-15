#include "ScorpSpawner.h"
#include "ScorpFactory.h"
#include "GameController.h"

ScorpSpawner::ScorpSpawner(Grid* grid)
	:myGrid(grid), row (0), right(0), disFromleft(10), isRight(false)
{
	disFromRight = GameController::RightOfScreen - 10;

	speed = 0;
	spawnRate = 0;

}

void ScorpSpawner::startSpawning(int s, int rate, Grid* newGrid)
{
	myGrid = newGrid;

	speed = s;
	spawnRate = rate;

	SetAlarm(4, (float)spawnRate);
}

void ScorpSpawner::stopSpawning()
{
	AlarmCancel(4);
}

void ScorpSpawner::Alarm4()
{
	row = rand() % 22 + 1;
	right = rand() % 1;

	if (right == 0)
	{
		isRight = false;
		ScorpFactory::CreateScorp(sf::Vector2f((float)disFromleft, (float)((row * GameController::ScreenMult) + GameController::HalfScreenMult)), myGrid, isRight, speed);
	}
	else
	{
		isRight = true;
		ScorpFactory::CreateScorp(sf::Vector2f((float)disFromRight, (float)((row * GameController::ScreenMult) + GameController::HalfScreenMult)), myGrid, isRight, speed);
	}

	SetAlarm(4, (float)(spawnRate * 2));

}
