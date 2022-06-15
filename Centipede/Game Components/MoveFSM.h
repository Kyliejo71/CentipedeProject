#ifndef _MoveFSM
#define _MoveFSM

#include "TEAL\CommonElements.h"
#include "MoveState.h"

class MoveState;
class MoveRightandDown;
class MoveRightandUp;
class MoveLeftandDown;
class MoveLeftandUp;
class TurnDownGoLeft;
class TurnDownGoRight;
class TurnUpGoLeft;
class TurnUpGoRight;
class MoveDownPoison;
class MoveDownPoisonLeft;

class MoveFSM
{
public:
	MoveFSM() = default;
	~MoveFSM() = default;
	MoveFSM(const MoveFSM&) = delete;
	MoveFSM& operator=(const MoveFSM&) = default;

	static const MoveRightandDown StateMoveRightandDown;
	static const MoveRightandUp StateMoveRightandUp;
	static const MoveLeftandDown StateMoveLeftandDown;
	static const MoveLeftandUp StateMoveLeftandUp;
	static const TurnDownGoLeft StateTurnDownGoLeft;
	static const TurnDownGoRight StateTurnDownGoRight;
	static const TurnUpGoLeft StateTurnUpGoLeft;
	static const TurnUpGoRight StateTurnUpGoRight;
	static const MoveDownPoison StateMoveDownPoison;
	static const MoveDownPoisonLeft StateMoveDownPoisonLeft;


};

#endif _MoveFSM