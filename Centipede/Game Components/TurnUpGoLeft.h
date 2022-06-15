#ifndef _TurnUpGoLeft
#define _TurnUpGoLeft

#include "TEAL\CommonElements.h"
#include "MoveState.h"

struct OffsetArray;
class CentipedeBase;
class Grid;

class TurnUpGoLeft : public MoveState
{
public:
	TurnUpGoLeft();
	~TurnUpGoLeft() = default;
	TurnUpGoLeft(const TurnUpGoLeft&) = delete;
	TurnUpGoLeft& operator=(const TurnUpGoLeft&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _TurnUpGoLeft
