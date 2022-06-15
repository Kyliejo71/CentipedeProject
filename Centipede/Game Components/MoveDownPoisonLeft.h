#ifndef _MoveDownPoisonLeft
#define _MoveDownPoisonLeft

#include "TEAL\CommonElements.h"
#include "MoveState.h"

//struct OffsetArray;
class MoveState;
class Grid;
class CentipedeBase;

class MoveDownPoisonLeft : public MoveState
{
public:
	MoveDownPoisonLeft();
	~MoveDownPoisonLeft() = default;
	MoveDownPoisonLeft(const MoveDownPoisonLeft&) = delete;
	MoveDownPoisonLeft& operator=(const MoveDownPoisonLeft&) = default;

	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const override;
	virtual void Show() const override;
};

#endif _MoveDownPoisonLeft