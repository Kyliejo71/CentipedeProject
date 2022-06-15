#include "Mushroomfactory.h"
#include "TEAL\CommonElements.h"
#include "MushroomPool.h"
#include "Mushroom.h"

Mushroomfactory* Mushroomfactory::ptrInstance = nullptr;

Mushroom* Mushroomfactory::privCreateMushroom(sf::Vector2f p, int x, int y, Grid* grid)
{
	Mushroom* m = myMushroomPool.GetMushroom();

	m->SetExternalManagement(RecycleMushroom);

	m->Initialize(p, x, y, grid);

	return m;
}

void Mushroomfactory::privRecycleMushroom(GameObject* m)
{
	myMushroomPool.ReturnMushroom(static_cast<Mushroom*>(m));
}

void Mushroomfactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
