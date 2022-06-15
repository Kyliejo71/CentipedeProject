#ifndef _MoveDownPoison
#define _MoveDownPoison

#include "TEAL\CommonElements.h"
#include "MoveState.h"

//struct OffsetArray;
class MoveState;
class Grid;
class CentipedeBase;

class MoveDownPoison : public MoveState
{
public:
	MoveDownPoison();
	~MoveDownPoison() = default;
	MoveDownPoison(const MoveDownPoison&) = delete;
	MoveDownPoison& operator=(const MoveDownPoison&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _MoveDownPoison

