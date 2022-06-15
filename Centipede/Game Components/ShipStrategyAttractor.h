#ifndef _ShipStrategyAttractor
#define _ShipStrategyAttractor

#include "TEAL/CommonElements.h"
#include "ShipStrategy.h"

class Ship;

class ShipStrategyAttractor : public ShipStrategy
{
public:
	ShipStrategyAttractor() = default;
	ShipStrategyAttractor(const ShipStrategyAttractor&) = delete;

	virtual void pickShipMode(Ship* myShip) override;

};

#endif _ShipStrategyAttractor
