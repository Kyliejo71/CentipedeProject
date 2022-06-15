#ifndef _ShipStrategy
#define _ShipStrategy

#include "TEAL/CommonElements.h"

class Ship;

class ShipStrategy : public GameObject
{
public:
	ShipStrategy() = default;
	ShipStrategy(const ShipStrategy&) = delete;
	virtual ShipStrategy& operator=(const ShipStrategy&) = default;
	virtual ~ShipStrategy() = default;

	virtual void pickShipMode(Ship* myShip) = 0;

};

#endif _ShipStrategy
