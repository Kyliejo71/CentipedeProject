#ifndef _FleaFactory
#define _FleaFactory

#include "FleaPool.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"

class GameObject;
class Grid;

class FleaFactory
{
private:

	static FleaFactory* ptrInstance;			

	FleaFactory() = default;								
	FleaFactory(const FleaFactory&) = delete;				
	FleaFactory& operator=(const FleaFactory&) = delete;	
	~FleaFactory() = default;								

	static FleaFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new FleaFactory();
		return *ptrInstance;
	};

	FleaPool myFleaPool;

	void privCreateFlea(sf::Vector2f pos, Grid* grid);
	void privRecycleFlea(GameObject* b);

public:

	static void CreateFlea(sf::Vector2f pos, Grid* grid) { Instance().privCreateFlea(pos, grid); };
	static void RecycleFlea(GameObject* b) { Instance().privRecycleFlea(b); };

	static void Terminate();
};


#endif _FleaFactory
