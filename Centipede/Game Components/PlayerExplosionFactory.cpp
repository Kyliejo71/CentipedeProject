#include "PlayerExplosionFactory.h"
#include "TEAL\CommonElements.h"
#include "PlayerExplosionPool.h"
#include "PlayerExplosions.h"

PlayerExplosionFactory* PlayerExplosionFactory::ptrInstance = nullptr;

void PlayerExplosionFactory::privCreatePlayerExplosion(sf::Vector2f pos)
{
	PlayerExplosions* p = myPlayerExplosionPool.GetPlayerExplosion();

	p->SetExternalManagement(RecyclePlayerExplosion);

	p->Initialize(pos);
}

void PlayerExplosionFactory::privRecyclePlayerExplosion(GameObject* p)
{
	myPlayerExplosionPool.ReturnPlayerExplosion(static_cast<PlayerExplosions*>(p));
}

void PlayerExplosionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
