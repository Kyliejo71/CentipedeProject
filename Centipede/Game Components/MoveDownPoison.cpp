#include "MoveDownPoison.h"
#include "MoveFSM.h"
#include "MovementCollection.h"
#include "Grid.h"
#include "CentipedeBase.h"
#include "GameController.h"
#include "MoveDownPoisonLeft.h"
#include "MoveRightandUp.h"

MoveDownPoison::MoveDownPoison()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndRight;
}

const MoveState* MoveDownPoison::GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const
{
	const MoveState* pNextState;

	sf::Vector2f nextPos = sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y);

	if (nextPos.y + GameController::HalfScreenMult == GameController::BottomOfShrooms)
	{
		pNextState = &MoveFSM::StateMoveRightandUp;
		cb->noMorePoison();
	}
	else
	{
		pNextState = &MoveFSM::StateMoveDownPoison;
	}


	return pNextState;
}

void MoveDownPoison::Show() const
{
}
