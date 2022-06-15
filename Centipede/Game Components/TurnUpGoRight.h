#ifndef _TurnUpGoRight
#define _TurnUpGoRight

#include "TEAL\CommonElements.h"
#include "MoveState.h"

struct OffsetArray;
class CentipedeBase;

class TurnUpGoRight : public MoveState
{
public:
	TurnUpGoRight();
	~TurnUpGoRight() = default;
	TurnUpGoRight(const TurnUpGoRight&) = delete;
	TurnUpGoRight& operator=(const TurnUpGoRight&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _TurnUpGoRight
