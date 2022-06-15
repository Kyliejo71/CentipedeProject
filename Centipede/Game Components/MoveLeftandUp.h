#ifndef _MoveLeftandUp
#define _MoveLeftandUp

#include "TEAL\CommonElements.h"
#include "MoveState.h"

struct OffsetArray;
class CentipedeBase;

class MoveLeftandUp : public MoveState
{
public:
	MoveLeftandUp();
	~MoveLeftandUp() = default;
	MoveLeftandUp(const MoveLeftandUp&) = delete;
	MoveLeftandUp& operator=(const MoveLeftandUp&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _MoveLeftandUp
