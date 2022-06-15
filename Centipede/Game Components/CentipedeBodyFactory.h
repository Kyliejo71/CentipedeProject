#ifndef _CentipedeBodyFactory
#define _CentipedeBodyFactory

#include "CentipedeBodyPool.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"

class GameObject;
class Grid;
class CentipedeBody;

class CentipedeBodyFactory
{
private:

	static CentipedeBodyFactory* ptrInstance;

	CentipedeBodyFactory() = default;
	CentipedeBodyFactory(const CentipedeBodyFactory&) = delete;
	CentipedeBodyFactory& operator=(const CentipedeBodyFactory&) = delete;
	~CentipedeBodyFactory() = default;

	static CentipedeBodyFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CentipedeBodyFactory();
		return *ptrInstance;
	};

	CentipedeBodyPool myBodyPool;

	CentipedeBody* privCreateBody(sf::Vector2f pos, Grid* grid, int speed);
	void privRecycleBody(GameObject* b);

public:

	static CentipedeBody* CreateBody(sf::Vector2f pos, Grid* grid, int speed) 
	{ 
		CentipedeBody* b;
		b = Instance().privCreateBody(pos, grid, speed); 
		return b;
	};
	static void RecycleBody(GameObject* b) { Instance().privRecycleBody(b); };

	static void Terminate();
};


#endif _CentipedeBodyFactory

