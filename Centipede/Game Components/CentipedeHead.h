#ifndef _CentipedeHead
#define _CentipedeHead

#include "TEAL\CommonElements.h"
#include "CentipedeBase.h"

class Grid;
class MoveState;
class Bullet;
class CmdSound;

class CentipedeHead : public CentipedeBase
{
public:
	CentipedeHead() = default;
	~CentipedeHead() = default;
	CentipedeHead(const CentipedeHead&) = delete;
	CentipedeHead& operator=(const CentipedeHead&) = default;

	void Initialize(sf::Vector2f Pos, Grid* myGrid, int currFrames, const MoveState* currState, int speed);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* other);
	virtual const void becomehead() override;


private:
	CmdSound* pSound;
	CmdSound* pDeathSound;

};
#endif _CentipedeHead