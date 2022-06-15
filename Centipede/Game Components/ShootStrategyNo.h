#ifndef _ShootStrategyNo
#define _ShootStrategyNo

#include "TEAL/CommonElements.h"
#include "ShootStrategy.h"

class Ship;

class ShootStrategyNo : public ShootStrategy
{
public:
	ShootStrategyNo() = default;
	ShootStrategyNo(const ShootStrategyNo&) = delete;

	virtual void doIShoot(Ship* myShip) override;

};

#endif _ShootStrategyNo
