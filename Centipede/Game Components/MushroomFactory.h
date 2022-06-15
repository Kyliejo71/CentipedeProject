#ifndef _MushroomFactory
#define _MushroomFactory

#include "MushroomPool.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"

class GameObject;

class Mushroomfactory
{
private:

	static Mushroomfactory* ptrInstance;

	Mushroomfactory() = default;								
	Mushroomfactory(const Mushroomfactory&) = delete;			
	Mushroomfactory& operator=(const Mushroomfactory&) = delete;
	~Mushroomfactory() = default;								

	static Mushroomfactory& Instance()	  
	{
		if (!ptrInstance)
			ptrInstance = new Mushroomfactory();
		return *ptrInstance;
	};

	MushroomPool myMushroomPool;  

	Mushroom* privCreateMushroom(sf::Vector2f p, int x, int y, Grid* grid);
	void privRecycleMushroom(GameObject* b);

public:

	static Mushroom* CreateMushroom(sf::Vector2f p, int x, int y, Grid* grid) 
	{
		Mushroom* m;
		m = Instance().privCreateMushroom(p, x, y, grid); 
		return m;
	};
	static void RecycleMushroom(GameObject* m) { Instance().privRecycleMushroom(m); };

	static void Terminate();
};


#endif _MushroomFactory
