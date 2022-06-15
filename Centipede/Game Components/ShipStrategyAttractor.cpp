#include "ShipStrategyAttractor.h"
#include "Ship.h"

void ShipStrategyAttractor::pickShipMode(Ship* myShip)
{
	myShip->attractorMode();
}
