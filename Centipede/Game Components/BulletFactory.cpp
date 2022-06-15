#include "BulletFactory.h"
#include "TEAL\CommonElements.h"
#include "BulletPool.h"
#include "Bullet.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

void BulletFactory::privCreateBullet(sf::Vector2f pos, Ship* ship)
{
	Bullet* b = myBulletPool.GetBullet();

	b->SetExternalManagement(RecycleBullet);

	b->Initialize(pos, ship);
}

void BulletFactory::privRecycleBullet(GameObject* b)
{
	myBulletPool.ReturnBullet(static_cast<Bullet*>(b));
}

void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}