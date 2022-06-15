#include "MoveRightandUp.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "Grid.h"
#include "TurnDownGoLeft.h"
#include "TurnUpGoLeft.h"
#include "GameController.h"
#include "CentipedeBase.h"

MoveRightandUp::MoveRightandUp()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
}

const MoveState* MoveRightandUp::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x + GameController::ScreenMult, Pos.y);

	if (nextPos.x - GameController::HalfScreenMult == WindowManager::Window().getView().getSize().x)
	{
		if (nextPos.y + GameController::HalfScreenMult == GameController::PlayerAreaTop)
		{
			pNextState = &MoveFSM::StateTurnDownGoLeft;
		}
		else
		{
			pNextState = &MoveFSM::StateTurnUpGoLeft;
		}
	}
	else if (grid->isThereAShroom(nextPos, cb))
	{
		if (nextPos.y + GameController::HalfScreenMult == GameController::PlayerAreaTop)
		{
			pNextState = &MoveFSM::StateTurnDownGoLeft;
		}
		else
		{
			pNextState = &MoveFSM::StateTurnUpGoLeft;
		}
	}
	else
	{
		pNextState = &MoveFSM::StateMoveRightandUp;
	}



	return pNextState;
}

void MoveRightandUp::Show() const
{
}
