#ifndef _MoveRightandUp
#define _MoveRightandUp

#include "TEAL\CommonElements.h"
#include "MoveState.h"

struct OffsetArray;
class CentipedeBase;

class MoveRightandUp : public MoveState
{
public:
	MoveRightandUp();
	~MoveRightandUp() = default;
	MoveRightandUp(const MoveRightandUp&) = delete;
	MoveRightandUp& operator=(const MoveRightandUp&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _MoveRightandUp

