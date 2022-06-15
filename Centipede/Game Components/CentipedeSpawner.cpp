#include "CentipedeSpawner.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeBodyFactory.h"
#include "MoveLeftandDown.h"
#include "MoveFSM.h"
#include "SoundManager.h"
#include "GameController.h"
#include "CritterManager.h"


CentipedeSpawner::CentipedeSpawner(Grid* grid)
	:myGrid(grid)
{
	speed = 0;
	length = 0;

	startingPos = sf::Vector2f(816, 48);

	pCentiLoop = SoundManager::GetSoundCommand(SoundManager::SoundEvents::CentipedeSound);
}

void CentipedeSpawner::startSpawning(int s, int len, Grid* newGrid)
{
	myGrid = newGrid;

	speed = s;
	length = len;

	CentipedeBase* pHead = CentipedeHeadFactory::CreateHead(startingPos, myGrid, 0, &MoveFSM::StateMoveLeftandDown, speed);
	CritterManager::addcenties();
	CentipedeBase* pBody;

	for(int i = 1; i < length; i ++)
	{
		pBody = CentipedeBodyFactory::CreateBody(sf::Vector2f(startingPos.x + (GameController::ScreenMult * i), startingPos.y), myGrid, speed);

		pHead->setNext(pBody);
		pBody->setPrev(pHead);

		pHead = pBody;
		CritterManager::addcenties();
	}
	SoundManager::SendSoundCmd(pCentiLoop);
}
