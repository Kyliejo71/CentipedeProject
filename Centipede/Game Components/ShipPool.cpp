#include "ShipPool.h"
#include "Ship.h"

ShipPool::~ShipPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Ship* ShipPool::GetShip()
{
	Ship* s;

	if (recycledItems.empty())
	{
		s = new Ship();
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();

		s->RegisterToCurrentScene();
	}

	return s;
}

void ShipPool::ReturnShip(Ship* s)
{
	recycledItems.push(static_cast<Ship*>(s));
}
