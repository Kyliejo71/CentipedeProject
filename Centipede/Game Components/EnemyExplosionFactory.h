#ifndef _EnemyExplosionFactory
#define _EnemyExplosionFactory

#include "EnemyExplosionPool.h"
#include "SFML/Graphics.hpp"
#include "EnemyExplosions.h"

class GameObject;

class EnemyExplosionFactory
{
private:

	static EnemyExplosionFactory* ptrInstance;

	EnemyExplosionFactory() = default;
	EnemyExplosionFactory(const EnemyExplosionFactory&) = delete;
	EnemyExplosionFactory& operator=(const EnemyExplosionFactory&) = delete;
	~EnemyExplosionFactory() = default;

	static EnemyExplosionFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new EnemyExplosionFactory();
		return *ptrInstance;
	};

	EnemyExplosionPool myEnemyExplosionPool;  // Back to be a non-static member instance


	void privCreateEnemyExplosion(sf::Vector2f pos);
	void privRecycleEnemyExplosion(GameObject* e);

public:

	static void CreateEnemyExplosion(sf::Vector2f pos) { Instance().privCreateEnemyExplosion(pos); };
	static void RecycleEnemyExplosion(GameObject* e) { Instance().privRecycleEnemyExplosion(e); };

	static void Terminate();
};


#endif _EnemyExplosionFactory

