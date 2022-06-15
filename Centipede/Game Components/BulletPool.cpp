#include "BulletPool.h"
#include "TEAL\CommonElements.h"
#include "Bullet.h"

BulletPool::BulletPool()
{
}

BulletPool::~BulletPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletPool::GetBullet()
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();	

		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletPool::ReturnBullet(Bullet* b)
{
	recycledItems.push(static_cast<Bullet*>(b));
}