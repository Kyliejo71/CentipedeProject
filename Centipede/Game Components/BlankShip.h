#ifndef _BlankShip
#define _BlankShip

#include "TEAL\CommonElements.h"

class BlankShip : public GameObject
{
public:
	BlankShip()  = default;
	~BlankShip() = default;
	BlankShip(const BlankShip&) = delete;
	BlankShip& operator=(const BlankShip&) = default;

	BlankShip(sf::Vector2f Pos);

	virtual void Update();
	virtual void Draw();

private:

	AnimatedSprite MainSprite;
};

#endif _BlankShip

