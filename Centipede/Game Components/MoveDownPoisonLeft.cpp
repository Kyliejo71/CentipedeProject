#include "MoveDownPoisonLeft.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "Grid.h"
#include "CentipedeBase.h"
#include "GameController.h"
#include "MoveLeftandUp.h"
#include "MoveDownPoison.h"

MoveDownPoisonLeft::MoveDownPoisonLeft()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndLeft;
}

const MoveState* MoveDownPoisonLeft::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y);

	if (nextPos.y + GameController::HalfScreenMult == GameController::BottomOfShrooms)
	{
		pNextState = &MoveFSM::StateMoveLeftandUp;
		cb->noMorePoison();
	}
	else
	{
		pNextState = &MoveFSM::StateMoveDownPoison;
	}


	return pNextState;
}

void MoveDownPoisonLeft::Show() const
{
}
