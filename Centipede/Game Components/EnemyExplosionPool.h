#ifndef _EnemyExplosionPool
#define _EnemyExplosionPool

#include <stack>
class EnemyExplosions;

class EnemyExplosionPool
{
private:
	std::stack<EnemyExplosions*> recycledItems;

public:
	EnemyExplosionPool() = default;
	EnemyExplosionPool(const EnemyExplosionPool&) = delete;
	EnemyExplosionPool& operator=(const EnemyExplosionPool&) = delete;
	~EnemyExplosionPool();

	EnemyExplosions* GetEnemyExplosion();

	void ReturnEnemyExplosion(EnemyExplosions* e);
};


#endif _EnemyExplosionPool
