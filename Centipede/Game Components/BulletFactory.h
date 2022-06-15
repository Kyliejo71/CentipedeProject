#ifndef _BulletFactory
#define _BulletFactory

#include "BulletPool.h"
#include "SFML/Graphics.hpp"
#include "Ship.h"

class GameObject;

class BulletFactory
{
private:

	static BulletFactory* ptrInstance;			

	BulletFactory() = default;												
	BulletFactory(const BulletFactory&) = delete;				
	BulletFactory& operator=(const BulletFactory&) = delete;	
	~BulletFactory() = default;									

	static BulletFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new BulletFactory();
		return *ptrInstance;
	};

	BulletPool myBulletPool;  // Back to be a non-static member instance

	
	void privCreateBullet(sf::Vector2f pos, Ship* ship);
	void privRecycleBullet(GameObject* b);

public:

	static void CreateBullet(sf::Vector2f pos, Ship* ship ) { Instance().privCreateBullet(pos, ship); };
	static void RecycleBullet(GameObject* b) { Instance().privRecycleBullet(b); };

	static void Terminate();
};


#endif _BulletFactory
