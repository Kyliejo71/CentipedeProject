#ifndef _ShipPool
#define _ShipPool

#include <stack>
class Ship;

class ShipPool
{
private:
	std::stack<Ship*> recycledItems;

public:
	ShipPool() = default;
	ShipPool(const ShipPool&) = delete;
	ShipPool& operator=(const ShipPool&) = delete;
	~ShipPool();

	Ship* GetShip();

	void ReturnShip(Ship* s);
};


#endif _ShipPool
