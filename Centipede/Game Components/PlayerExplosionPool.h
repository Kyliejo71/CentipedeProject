#ifndef _PlayerExplosionPool
#define _PlayerExplosionPool

#include <stack>
class PlayerExplosions;

class PlayerExplosionPool
{
private:
	std::stack<PlayerExplosions*> recycledItems;

public:
	PlayerExplosionPool() = default;
	PlayerExplosionPool(const PlayerExplosionPool&) = delete;
	PlayerExplosionPool& operator=(const PlayerExplosionPool&) = delete;
	~PlayerExplosionPool();

	PlayerExplosions* GetPlayerExplosion();

	void ReturnPlayerExplosion(PlayerExplosions* e);
};


#endif _PlayerExplosionPool

