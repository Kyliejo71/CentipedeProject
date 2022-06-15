#ifndef _ShipFactory
#define _ShipFactory

#include "ShipPool.h"
#include "SFML/Graphics.hpp"
#include "Ship.h"

class GameObject;

class ShipFactory
{
private:

	static ShipFactory* ptrInstance;

	ShipFactory() = default;
	ShipFactory(const ShipFactory&) = delete;
	ShipFactory& operator=(const ShipFactory&) = delete;
	~ShipFactory() = default;

	static ShipFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new ShipFactory();
		return *ptrInstance;
	};

	ShipPool myShipPool;  // Back to be a non-static member instance

	Ship* privCreateShip(ShipStrategy* newStrat);
	void privRecycleShip(GameObject* b);

public:

	static Ship* CreateShip(ShipStrategy* newStrat)
	{
		Ship* s;
		s = Instance().privCreateShip(newStrat);
		return s; 
	};
	static void RecycleShip(GameObject* s) { Instance().privRecycleShip(s); };

	static void Terminate();
};


#endif _ShipFactory
