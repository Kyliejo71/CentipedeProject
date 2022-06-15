#include "MoveRightandDown.h"
#include "MoveFSM.h"
#include "MovementCollection.h"
#include "Grid.h"
#include "TurnDownGoleft.h"
#include "TurnUpGoLeft.h"
#include "GameController.h"
#include "CentipedeBase.h"
#include "MoveDownPoisonLeft.h"
#include "WaveManager.h"

MoveRightandDown::MoveRightandDown()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
}

const MoveState* MoveRightandDown::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x + GameController::ScreenMult, Pos.y);

	if (nextPos.x - GameController::HalfScreenMult == GameController::RightOfScreen)
	{
		if (nextPos.y + GameController::HalfScreenMult == GameController::BottomOfShrooms)
		{
			pNextState = &MoveFSM::StateTurnUpGoLeft;
			WaveManager::startSpawningPACenties();
		}
		else
		{
			pNextState = &MoveFSM::StateTurnDownGoLeft;
		}
	}
	else if (grid->isThereAShroom(nextPos, cb))
	{
		if(cb->amIpoision())
		{
			pNextState = &MoveFSM::StateMoveDownPoisonLeft;
		}
		else if (nextPos.y + GameController::HalfScreenMult == GameController::BottomOfShrooms)
		{
			pNextState = &MoveFSM::StateTurnUpGoLeft;
			WaveManager::startSpawningPACenties();
		}
		else
		{
			pNextState = &MoveFSM::StateTurnDownGoLeft;
		}
	}
	else
	{
		pNextState = &MoveFSM::StateMoveRightandDown;
	}



	return pNextState;
}

void MoveRightandDown::Show() const
{
}
