#include "EnemyExplosionPool.h"
#include "TEAL\CommonElements.h"
#include "EnemyExplosions.h"

EnemyExplosionPool::~EnemyExplosionPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

EnemyExplosions* EnemyExplosionPool::GetEnemyExplosion()
{
	EnemyExplosions* e;

	if (recycledItems.empty())
	{
		e = new EnemyExplosions();
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();

		e->RegisterToCurrentScene();
	}

	return e;
}

void EnemyExplosionPool::ReturnEnemyExplosion(EnemyExplosions* e)
{
	recycledItems.push(static_cast<EnemyExplosions*>(e));
}
