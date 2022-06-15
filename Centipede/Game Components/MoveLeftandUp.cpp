#include "MoveLeftandUp.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "Grid.h"
#include "TurnDownGoRight.h"
#include "TurnUpGoRight.h"
#include "GameController.h"
#include "CentipedeBase.h"

MoveLeftandUp::MoveLeftandUp()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightLeft;
}

const MoveState* MoveLeftandUp::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y);

	if (nextPos.x + GameController::HalfScreenMult == GameController::LeftOfScreen)
	{
		if (nextPos.y + GameController::HalfScreenMult == GameController::PlayerAreaTop)
		{
			pNextState = &MoveFSM::StateTurnDownGoRight;
		}
		else
		{
			pNextState = &MoveFSM::StateTurnUpGoRight;

		}
	}
	else if (grid->isThereAShroom(nextPos, cb))
	{
		if (nextPos.y + GameController::HalfScreenMult == GameController::PlayerAreaTop)
		{
			pNextState = &MoveFSM::StateTurnDownGoRight;
		}
		else
		{
			pNextState = &MoveFSM::StateTurnUpGoRight;
		}
	}
	else
	{
		pNextState = &MoveFSM::StateMoveLeftandUp;
	}



	return pNextState;
}

void MoveLeftandUp::Show() const
{
}
