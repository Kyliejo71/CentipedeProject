#include "TurnUpGoRight.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "Grid.h"
#include "TurnUpGoLeft.h"
#include "MoveRightandUp.h"
#include "GameController.h"
#include "CentipedeBase.h"


TurnUpGoRight::TurnUpGoRight()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnUpEndRight;
}

const MoveState* TurnUpGoRight::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x + GameController::ScreenMult, Pos.y);
	if (nextPos.x - GameController::HalfScreenMult == GameController::RightOfScreen)
	{
		pNextState = &MoveFSM::StateTurnUpGoLeft;
	}
	else if (grid->isThereAShroom(nextPos, cb))
	{
		pNextState = &MoveFSM::StateTurnUpGoLeft;
	}
	else
	{
		pNextState = &MoveFSM::StateMoveRightandUp;
	}



	return pNextState;
}

void TurnUpGoRight::Show() const
{
}
