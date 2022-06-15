#ifndef _PlayerExplosionFactory
#define _PlayerExplosionFactory

#include "PlayerExplosionPool.h"
#include "SFML/Graphics.hpp"
#include "PlayerExplosions.h"

class GameObject;

class PlayerExplosionFactory
{
private:

	static PlayerExplosionFactory* ptrInstance;

	PlayerExplosionFactory() = default;
	PlayerExplosionFactory(const PlayerExplosionFactory&) = delete;
	PlayerExplosionFactory& operator=(const PlayerExplosionFactory&) = delete;
	~PlayerExplosionFactory() = default;

	static PlayerExplosionFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new PlayerExplosionFactory();
		return *ptrInstance;
	};

	PlayerExplosionPool myPlayerExplosionPool;  // Back to be a non-static member instance


	void privCreatePlayerExplosion(sf::Vector2f pos);
	void privRecyclePlayerExplosion(GameObject* p);

public:

	static void CreatePlayerExplosion(sf::Vector2f pos) { Instance().privCreatePlayerExplosion(pos); };
	static void RecyclePlayerExplosion(GameObject* p) { Instance().privRecyclePlayerExplosion(p); };

	static void Terminate();
};


#endif _PlayerExplosionFactory