#include "TurnUpGoLeft.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "Grid.h"
#include "TurnUpGoRight.h"
#include "MoveLeftandUp.h"
#include "GameController.h"
#include "CentipedeBase.h"

TurnUpGoLeft::TurnUpGoLeft()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnUpEndLeft;
}

const MoveState* TurnUpGoLeft::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y);
	if (nextPos.x + GameController::HalfScreenMult == GameController::LeftOfScreen)
	{
		pNextState = &MoveFSM::StateTurnUpGoRight;
	}
	else if (grid->isThereAShroom(nextPos, cb))
	{
		pNextState = &MoveFSM::StateTurnUpGoRight;
	}
	else
	{
		pNextState = &MoveFSM::StateMoveLeftandUp;
	}



	return pNextState;
}

void TurnUpGoLeft::Show() const
{
}
