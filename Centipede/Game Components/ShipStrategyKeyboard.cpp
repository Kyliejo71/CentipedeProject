#include "ShipStrategyKeyboard.h"
#include "Ship.h"

void ShipStrategyKeyboard::pickShipMode(Ship* myShip)
{
	myShip->keyboardMode();
}
