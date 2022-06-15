#ifndef _TurnDownGoLeft
#define _TurnDownGoLeft

#include "TEAL\CommonElements.h"
#include "MoveState.h"
#

//struct OffsetArray;
class MoveState;
class Grid;
class CentipedeBase;

class TurnDownGoLeft : public MoveState
{
public:
	TurnDownGoLeft();
	~TurnDownGoLeft() = default;
	TurnDownGoLeft(const TurnDownGoLeft&) = delete;
	TurnDownGoLeft& operator=(const TurnDownGoLeft&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _TurnDownGoLeft
