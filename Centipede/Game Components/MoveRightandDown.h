#ifndef _MoveRightandDown
#define _MoveRightandDown

#include "TEAL\CommonElements.h"
#include "MoveState.h"

struct OffsetArray;
class CentipedeBase;

class MoveRightandDown : public MoveState
{
public:
	MoveRightandDown();
	~MoveRightandDown() = default;
	MoveRightandDown(const MoveRightandDown&) = delete;
	MoveRightandDown& operator=(const MoveRightandDown&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _MoveRightandDown
