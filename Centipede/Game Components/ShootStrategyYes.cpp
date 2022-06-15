#include "ShootStrategyYes.h"
#include "Ship.h"

void ShootStrategyYes::doIShoot(Ship* myShip)
{
	myShip->shootBullet();
}
