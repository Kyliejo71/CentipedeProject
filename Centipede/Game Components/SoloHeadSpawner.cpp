#include "SoloHeadSpawner.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeHead.h"
#include "MoveLeftandDown.h"
#include "MoveFSM.h"
#include "GameController.h"
#include "MoveRightandDown.h"
#include "CritterManager.h"

SoloHeadSpawner::SoloHeadSpawner(Grid* grid)
	:myGrid(grid)
{
	totalPA = 0;

	topPos = sf::Vector2f(752, 48);
	PAPos = sf::Vector2f(GameController::HalfScreenMult, GameController::PlayerAreaTop - GameController::HalfScreenMult);
}

void SoloHeadSpawner::startSpawningTop(int speed, int count, Grid* newGrid)
{
	sf::Vector2f nextPos;

	for(int i = 0; i < count; i++) //goes through and spawns in solo heads at start
	{
		nextPos = sf::Vector2f(topPos.x, topPos.y);
		CentipedeHeadFactory::CreateHead(nextPos, newGrid, 0, &MoveFSM::StateMoveLeftandDown, speed);
		topPos = sf::Vector2f(topPos.x - (GameController::ScreenMult * 2), topPos.y);
		CritterManager::addcenties();
	}
}

void SoloHeadSpawner::startSpawningPA(int speed, int count, Grid* newGrid)
{
	if(totalPA < count) //checks if less have been spawned in against the total
	{
		totalPA++;
		CentipedeHeadFactory::CreateHead(PAPos, newGrid, 0, &MoveFSM::StateMoveRightandDown, speed);
		CritterManager::addcenties();
	}
}
