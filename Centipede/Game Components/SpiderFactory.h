#ifndef _SpiderFactory
#define _SpiderFactory

#include "SpiderPool.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"

class GameObject;

class SpiderFactory
{
private:

	static SpiderFactory* ptrInstance;

	SpiderFactory() = default;								
	SpiderFactory(const SpiderFactory&) = delete;			
	SpiderFactory& operator=(const SpiderFactory&) = delete;
	~SpiderFactory() = default;								

	static SpiderFactory& Instance()	    
	{
		if (!ptrInstance)
			ptrInstance = new SpiderFactory();
		return *ptrInstance;
	};

	SpiderPool mySpiderPool;

	void privCreateSpider(sf::Vector2f p, Grid* grid, bool isRightw, int speed);
	void privRecycleSpider(GameObject* b);

public:

	// Services/API as STATIC METHODS
	//    Usually just a pass-through arguments to private instance methods
	static void CreateSpider(sf::Vector2f p, Grid* grid, bool isRightw, int speed) { Instance().privCreateSpider(p, grid, isRightw, speed); };
	static void RecycleSpider(GameObject* s) { Instance().privRecycleSpider(s); };

	static void Terminate();
};


#endif _BulletFactoryWithRecycling