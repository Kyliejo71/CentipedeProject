#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory

#include "CentipedeHeadPool.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"

class GameObject;
class Grid;
class MoveState;

class CentipedeHeadFactory
{
private:

	static CentipedeHeadFactory* ptrInstance;

	CentipedeHeadFactory() = default;
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete;
	CentipedeHeadFactory& operator=(const CentipedeHeadFactory&) = delete;
	~CentipedeHeadFactory() = default;

	static CentipedeHeadFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CentipedeHeadFactory();
		return *ptrInstance;
	};

	CentipedeHeadPool myHeadPool;

	CentipedeHead* privCreateHead(sf::Vector2f pos, Grid* grid, int currFrames, const MoveState* currState, int speed);
	void privRecycleHead(GameObject* h);

public:

	static CentipedeHead* CreateHead(sf::Vector2f pos, Grid* grid, int currFrames, const MoveState* currState, int speed)
	{
		CentipedeHead* h;
		h = Instance().privCreateHead(pos, grid, currFrames, currState, speed);

		return h;
	};
	static void RecycleHead(GameObject* h) { Instance().privRecycleHead(h); };

	static void Terminate();
};


#endif _CentipedeHeadFactory

