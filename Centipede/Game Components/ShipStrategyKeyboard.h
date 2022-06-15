#ifndef _ShipStrategyKeyboard
#define _ShipStrategyKeyboard

#include "TEAL/CommonElements.h"
#include "ShipStrategy.h"

class Ship;

class ShipStrategyKeyboard : public ShipStrategy
{
public:
	ShipStrategyKeyboard() = default;
	ShipStrategyKeyboard(const ShipStrategyKeyboard&) = delete;

	virtual void pickShipMode(Ship* myShip) override;

};

#endif _ShipStrategyKeyboard