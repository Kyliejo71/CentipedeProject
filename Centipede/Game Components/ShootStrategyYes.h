#ifndef _ShootStrategyYes
#define _ShootStrategyYes

#include "TEAL/CommonElements.h"
#include "ShootStrategy.h"

class Ship;

class ShootStrategyYes : public ShootStrategy
{
public:
	ShootStrategyYes() = default;
	ShootStrategyYes(const ShootStrategyYes&) = delete;

	virtual void doIShoot(Ship* myShip) override;

};

#endif _ShootStrategyYes

