#include "ShipFactory.h"
#include "TEAL\CommonElements.h"
#include "ShipPool.h"
#include "Ship.h"

ShipFactory* ShipFactory::ptrInstance = nullptr;

Ship* ShipFactory::privCreateShip(ShipStrategy* newStrat)
{
	Ship* s = myShipPool.GetShip();

	s->SetExternalManagement(RecycleShip);

	s->Initialize(newStrat);

	return s;
}

void ShipFactory::privRecycleShip(GameObject* s)
{
	myShipPool.ReturnShip(static_cast<Ship*>(s));
}

void ShipFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
