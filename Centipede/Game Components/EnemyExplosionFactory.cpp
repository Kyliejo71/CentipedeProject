#include "EnemyExplosionFactory.h"
#include "TEAL\CommonElements.h"
#include "EnemyExplosionPool.h"
#include "EnemyExplosions.h"

EnemyExplosionFactory* EnemyExplosionFactory::ptrInstance = nullptr;

void EnemyExplosionFactory::privCreateEnemyExplosion(sf::Vector2f pos)
{
	EnemyExplosions* e = myEnemyExplosionPool.GetEnemyExplosion();

	e->SetExternalManagement(RecycleEnemyExplosion);

	e->Initialize(pos);
}

void EnemyExplosionFactory::privRecycleEnemyExplosion(GameObject* e)
{
	myEnemyExplosionPool.ReturnEnemyExplosion(static_cast<EnemyExplosions*>(e));
}

void EnemyExplosionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
