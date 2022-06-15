#include "MoveLeftandDown.h"
#include "MoveFSM.h"
#include "TurnDownGoRight.h"
#include "Grid.h"
#include "MovementCollection.h"
#include "TurnUpGoRight.h"
#include "GameController.h"
#include "CentipedeBase.h"
#include "MoveDownPoison.h"
#include "WaveManager.h"

MoveLeftandDown::MoveLeftandDown()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightLeft;
}

const MoveState* MoveLeftandDown::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y);


	if (nextPos.x + GameController::HalfScreenMult == GameController::LeftOfScreen)
	{
		if (nextPos.y + GameController::HalfScreenMult == GameController::BottomOfShrooms)
		{
			pNextState = &MoveFSM::StateTurnUpGoRight;
			WaveManager::startSpawningPACenties();
		}
		else
		{
			pNextState = &MoveFSM::StateTurnDownGoRight;
		}
	}
	else if (grid->isThereAShroom(nextPos, cb))
	{
		if(cb->amIpoision())
		{
			pNextState = &MoveFSM::StateMoveDownPoison;
		}
		else if (nextPos.y + GameController::HalfScreenMult == GameController::BottomOfShrooms)
		{
			pNextState = &MoveFSM::StateTurnUpGoRight;
			WaveManager::startSpawningPACenties();
		}
		else
		{
			pNextState = &MoveFSM::StateTurnDownGoRight;
		}
	}
	else
	{
		pNextState = &MoveFSM::StateMoveLeftandDown;
	}



	return pNextState;
}

void MoveLeftandDown::Show() const
{
}
