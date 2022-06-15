#include "MushroomPool.h"
#include "TEAL\CommonElements.h"
#include "Mushroom.h"

MushroomPool::MushroomPool()
{
}

MushroomPool::~MushroomPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Mushroom* MushroomPool::GetMushroom()
{
	Mushroom* m;

	if (recycledItems.empty())
	{
		m = new Mushroom();
	}
	else
	{
		m = recycledItems.top();
		recycledItems.pop();	

		m->RegisterToCurrentScene();
	}

	return m;
}

void MushroomPool::ReturnMushroom(Mushroom* m)
{
	recycledItems.push(static_cast<Mushroom*>(m));
}