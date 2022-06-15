#include "CentipedeHeadFactory.h"
#include "TEAL\CommonElements.h"
#include "CentipedeHeadPool.h"
#include "CentipedeHead.h"
#include "Grid.h"

CentipedeHeadFactory* CentipedeHeadFactory::ptrInstance = nullptr;

CentipedeHead* CentipedeHeadFactory::privCreateHead(sf::Vector2f pos, Grid* grid, int currFrames, const MoveState* currState, int speed)
{
	CentipedeHead* h = myHeadPool.GetHead();

	h->SetExternalManagement(RecycleHead);

	h->Initialize(pos, grid, currFrames, currState, speed);

	return h;
}

void CentipedeHeadFactory::privRecycleHead(GameObject* h)
{
	myHeadPool.ReturnHead(static_cast<CentipedeHead*>(h));
}

void CentipedeHeadFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}