#include "TurnDownGoLeft.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "TurnDownGoRight.h"
#include "MoveLeftandDown.h"
#include "Grid.h"
#include "GameController.h"
#include "CentipedeBase.h"
#include "MoveDownPoison.h"

TurnDownGoLeft::TurnDownGoLeft()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndLeft;
}

const MoveState* TurnDownGoLeft::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y);
	if(nextPos.x + GameController::HalfScreenMult == GameController::LeftOfScreen)
	{
		pNextState = &MoveFSM::StateTurnDownGoRight;
	}
	else if(grid->isThereAShroom(nextPos, cb))
	{
		if(cb->amIpoision())
		{
			pNextState = &MoveFSM::StateMoveDownPoison;
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

void TurnDownGoLeft::Show() const
{
}
