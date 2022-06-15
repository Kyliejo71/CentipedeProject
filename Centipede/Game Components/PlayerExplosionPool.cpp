#include "PlayerExplosionPool.h"
#include "TEAL\CommonElements.h"
#include "PlayerExplosions.h"

PlayerExplosionPool::~PlayerExplosionPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

PlayerExplosions* PlayerExplosionPool::GetPlayerExplosion()
{
	PlayerExplosions* p;

	if (recycledItems.empty())
	{
		p = new PlayerExplosions();
	}
	else
	{
		p = recycledItems.top();
		recycledItems.pop();

		p->RegisterToCurrentScene();
	}

	return p;
}

void PlayerExplosionPool::ReturnPlayerExplosion(PlayerExplosions* p)
{
	recycledItems.push(static_cast<PlayerExplosions*>(p));
}
