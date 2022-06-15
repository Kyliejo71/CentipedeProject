#ifndef _ShootStrategy
#define _ShootStrategy

#include "TEAL/CommonElements.h"

class Ship;

class ShootStrategy : public GameObject
{
public:
	ShootStrategy() = default;
	ShootStrategy(const ShootStrategy&) = delete;
	virtual ShootStrategy& operator=(const ShootStrategy&) = default;
	virtual ~ShootStrategy() = default;

	virtual void doIShoot(Ship* myShip) = 0;

};

#endif _ShootStrategy

