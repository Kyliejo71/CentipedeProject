#ifndef _CentipedeBase
#define _CentipedeBase

#include "TEAL\CommonElements.h"
#include "Critter.h"

class MoveState;
class Grid;
class MoveState;
class CmdScore;
class CmdSound;

class CentipedeBase : public Critter
{
public:

	CentipedeBase() = default;
	~CentipedeBase() {};
	CentipedeBase(const CentipedeBase&) = delete;
	CentipedeBase& operator=(const CentipedeBase&) = default;

	virtual void Update() {};
	virtual void Draw() {};
	virtual void Destroy() {};

	virtual const void setNext(CentipedeBase* p);
	virtual const void setPrev(CentipedeBase* p);
	virtual const void passState(const MoveState* ms);
	virtual const void becomehead() = 0;
	virtual const void poisonTime();
	virtual const bool amIpoision();
	virtual const void noMorePoison();

protected:

	sf::Vector2f Pos;

	int speed;

	int frames;
	int MaxFrames;

	Grid* myGrid;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap* bitmap;

	const MoveState* pCurrentState;

	CentipedeBase* pNext;
	CentipedeBase* pPrev;

	bool hitPoisioned;

	CmdScore* pDeath;
	CmdSound* pDeathSound;

};

#endif _CentipedeBase