#ifndef _ScorpFactory
#define _ScorpFactory

#include "ScorpPool.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"

class GameObject;

class ScorpFactory
{
private:

	static ScorpFactory* ptrInstance;			

	ScorpFactory() = default;								
	ScorpFactory(const ScorpFactory&) = delete;				
	ScorpFactory& operator=(const ScorpFactory&) = delete;	
	~ScorpFactory() = default;								

	static ScorpFactory& Instance()	   
	{
		if (!ptrInstance)
			ptrInstance = new ScorpFactory();
		return *ptrInstance;
	};

	ScorpPool myScorpPool; 

	void privCreateScorp(sf::Vector2f pos, Grid* grid, bool isRight, int speed);
	void privRecycleScorp(GameObject* b);

public:

	static void CreateScorp(sf::Vector2f pos, Grid* grid, bool isRight, int speed) { Instance().privCreateScorp(pos, grid, isRight, speed); };
	static void RecycleScorp(GameObject* s) { Instance().privRecycleScorp(s); };

	static void Terminate();
};


#endif _BulletFactoryWithRecycling