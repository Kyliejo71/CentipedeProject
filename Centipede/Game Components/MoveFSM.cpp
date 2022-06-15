#include "MoveFSM.h"
#include "MoveState.h"
#include "MoveLeftandDown.h"
#include "MoveLeftandUp.h"
#include "MoveRightandDown.h"
#include "MoveRightandUp.h"
#include "TurnDownGoLeft.h"
#include "TurnDownGoRight.h"
#include "TurnUpGoLeft.h"
#include "TurnUpGoRight.h"
#include "MoveDownPoison.h"
#include "MoveDownPoisonLeft.h"

const MoveRightandDown MoveFSM::StateMoveRightandDown;
const MoveRightandUp MoveFSM::StateMoveRightandUp;
const MoveLeftandDown MoveFSM::StateMoveLeftandDown;
const MoveLeftandUp MoveFSM::StateMoveLeftandUp;
const TurnDownGoLeft MoveFSM::StateTurnDownGoLeft;
const TurnDownGoRight MoveFSM::StateTurnDownGoRight;
const TurnUpGoLeft MoveFSM::StateTurnUpGoLeft;
const TurnUpGoRight MoveFSM::StateTurnUpGoRight;
const MoveDownPoison MoveFSM::StateMoveDownPoison;
const MoveDownPoisonLeft MoveFSM::StateMoveDownPoisonLeft;