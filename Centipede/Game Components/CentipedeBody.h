#ifndef _CentipedeBody
#define _CentipedeBody

#include "TEAL\CommonElements.h"
#include "Grid.h"
#include "CentipedeBase.h"

class Grid;
class MoveState;
class Bullet;

class CentipedeBody : public CentipedeBase
{
public:
	CentipedeBody() = default;
	~CentipedeBody() = default;
	CentipedeBody(const CentipedeBody&) = delete;
	CentipedeBody& operator=(const CentipedeBody&) = default;

	void Initialize(sf::Vector2f Pos, Grid* myGrid, int speed);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* other);

	virtual const void becomehead() override;

private:



};

#endif _CentipedeBody
