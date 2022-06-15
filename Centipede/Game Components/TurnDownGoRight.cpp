#include "TurnDownGoRight.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "Grid.h"
#include "TurnDownGoLeft.h"
#include "GameController.h"
#include "MoveRightandDown.h"
#include "CentipedeBase.h"
#include "MoveDownPoisonLeft.h"

TurnDownGoRight::TurnDownGoRight()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndRight;
}

const MoveState* TurnDownGoRight::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x + GameController::ScreenMult, Pos.y);

	if (nextPos.x - GameController::HalfScreenMult == GameController::RightOfScreen)
	{
		pNextState = &MoveFSM::StateTurnDownGoLeft;
	}
	else if (grid->isThereAShroom(nextPos, cb))
	{
		if(cb->amIpoision())
		{
			pNextState = &MoveFSM::StateMoveDownPoisonLeft;
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

void TurnDownGoRight::Show() const
{
}
