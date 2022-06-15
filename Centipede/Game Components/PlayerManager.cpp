#include "PlayerManager.h"
#include "Player.h"
#include "GameController.h"

PlayerManager* PlayerManager::ptrInstance = NULL;

Player* PlayerManager::privReturnCurrAttractor()
{
	if(P1 != nullptr)
	{
		P1->MarkForDestroy();
	}
	
	Attractor = new Player(1000);
	currPlayer = Attractor;
	currGrid = Attractor->getGrid();

	return this->Attractor;
}

Player* PlayerManager::privReturnCurrPlayer()
{
	return this->currPlayer;
}

void PlayerManager::privRemoveLife()
{
	this->currPlayer->lostLife();

	if(currPlayer->getLives() <= 0)
	{
		GameController::gameOver();
	}
	else
	{
		GameController::lifeLost();
	}
}

void PlayerManager::privPlayerOneStart()
{
	Attractor->MarkForDestroy();
	P1 = new Player(3);

	currPlayer = P1;
	currGrid = P1->getGrid();
}

PlayerManager::PlayerManager()
{
	P1 = nullptr;
	Attractor = nullptr;

	currPlayer = nullptr;
	currGrid = nullptr;
}

void PlayerManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
