#ifndef _SpiderNumbers
#define _SpiderNumbers

#include "TEAL\CommonElements.h"

class SpiderNumbers : public GameObject
{
public:
	SpiderNumbers() = default;
	SpiderNumbers(const SpiderNumbers&) = delete;
	SpiderNumbers& operator=(const SpiderNumbers&) = default;
	~SpiderNumbers() = default;

	void Initialize(sf::Vector2f p, int value);

	virtual void Update();
	virtual void Draw();
	virtual void Alarm0();

private:
	AnimatedSprite MainSprite;
};


#endif _SpiderNumbers
