#ifndef _MoveState
#define _MoveState

#include "TEAL\CommonElements.h"

struct OffsetArray;
class CentipedeBase;
class Grid;

class MoveState
{
public:
	MoveState();
	~MoveState();
	MoveState(const MoveState&) = delete;
	MoveState& operator=(const MoveState&) = default;

	const OffsetArray* GetMoveOffsets() const { return MyMoveOffsets; }
	virtual const MoveState* GetNextState(sf::Vector2f Pos, Grid* grid, CentipedeBase* cb) const = 0;
	virtual void Show() const = 0;;

protected:

	const OffsetArray* MyMoveOffsets;

};

#endif _MoveState

