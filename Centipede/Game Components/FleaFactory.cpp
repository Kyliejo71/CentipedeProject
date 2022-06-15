#include "FleaFactory.h"
#include "TEAL\CommonElements.h"
#include "FleaPool.h"
#include "Flea.h"
#include "Grid.h"

FleaFactory* FleaFactory::ptrInstance = nullptr;

void FleaFactory::privCreateFlea(sf::Vector2f pos, Grid* grid)
{
	Flea* f = myFleaPool.GetFlea();

	f->SetExternalManagement(RecycleFlea);

	f->Initialize(pos, grid);
}

void FleaFactory::privRecycleFlea(GameObject* f)
{
	myFleaPool.ReturnFlea(static_cast<Flea*>(f));
}

void FleaFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}