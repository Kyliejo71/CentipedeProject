#ifndef _PlayerExplosions
#define _PlayerExplosions

#include "TEAL\CommonElements.h"

class PlayerExplosions : public GameObject
{
public:
	PlayerExplosions() = default;
	PlayerExplosions(const PlayerExplosions&) = delete;
	PlayerExplosions& operator=(const PlayerExplosions&) = delete;
	~PlayerExplosions() = default;

	void Initialize(sf::Vector2f p);

	virtual void Update();
	virtual void Draw();

private:
	AnimatedSprite MainSprite;
};


#endif _PlayerExplosions