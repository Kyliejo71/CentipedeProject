#ifndef _EnemyExplosions
#define _EnemyExplosions

#include "TEAL\CommonElements.h"

class EnemyExplosions : public GameObject
{
public:
	EnemyExplosions() = default;
	EnemyExplosions(const EnemyExplosions&) = delete;
	EnemyExplosions& operator=(const EnemyExplosions&) = delete;
	~EnemyExplosions() = default;

	void Initialize(sf::Vector2f p);

	virtual void Update();
	virtual void Draw();

private:
	AnimatedSprite MainSprite;
};


#endif _EnemyExplosions
