#ifndef _TurnDownGoRight
#define _TurnDownGoRight

#include "TEAL\CommonElements.h"
#include "MoveState.h"

struct OffsetArray;
class CentipedeBase;

class TurnDownGoRight : public MoveState
{
public:
	TurnDownGoRight();
	~TurnDownGoRight() = default;
	TurnDownGoRight(const TurnDownGoRight&) = delete;
	TurnDownGoRight& operator=(const TurnDownGoRight&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _TurnDownGoRight
