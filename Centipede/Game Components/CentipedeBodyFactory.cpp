#include "CentipedeBodyFactory.h"
#include "TEAL\CommonElements.h"
#include "CentipedeBodyPool.h"
#include "CentipedeBody.h"
#include "Grid.h"

CentipedeBodyFactory* CentipedeBodyFactory::ptrInstance = nullptr;

CentipedeBody* CentipedeBodyFactory::privCreateBody(sf::Vector2f pos, Grid* grid, int speed)
{
	CentipedeBody* b = myBodyPool.GetBody();

	b->SetExternalManagement(RecycleBody);

	b->Initialize(pos, grid, speed);

	return b;
}

void CentipedeBodyFactory::privRecycleBody(GameObject* b)
{
	myBodyPool.ReturnBody(static_cast<CentipedeBody*>(b));
}

void CentipedeBodyFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}