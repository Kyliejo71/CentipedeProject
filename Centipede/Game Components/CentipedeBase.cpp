#include "CentipedeBase.h"

const void CentipedeBase::setNext(CentipedeBase* p)
{
	this->pNext = p;
}

const void CentipedeBase::setPrev(CentipedeBase* p)
{
	this->pPrev = p;
}

const void CentipedeBase::passState(const MoveState* ms)
{
	if (this->pNext != nullptr)
	{
		this->pNext->passState(pCurrentState);
	}
	pCurrentState = ms;
}

const void CentipedeBase::poisonTime()
{
	this->hitPoisioned = true;
}

const bool CentipedeBase::amIpoision()
{
	return hitPoisioned;
}

const void CentipedeBase::noMorePoison()
{
	hitPoisioned = false;
}
