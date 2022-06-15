#ifndef _MoveLeftandDown
#define _MoveLeftandDown

#include "TEAL\CommonElements.h"
#include "MoveState.h"

struct OffsetArray;
class CentipedeBase;

class MoveLeftandDown : public MoveState
{
public:
	MoveLeftandDown();
	~MoveLeftandDown() = default;
	MoveLeftandDown(const MoveLeftandDown&) = delete;
	MoveLeftandDown& operator=(const MoveLeftandDown&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _MoveLeftandDown