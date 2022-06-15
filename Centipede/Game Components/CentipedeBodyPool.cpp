#include "CentipedeBodyPool.h"
#include "TEAL\CommonElements.h"
#include "CentipedeBody.h"

CentipedeBodyPool::CentipedeBodyPool()
{
}

CentipedeBodyPool::~CentipedeBodyPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeBody* CentipedeBodyPool::GetBody()
{
	CentipedeBody* b;

	if (recycledItems.empty())
	{
		b = new CentipedeBody();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void CentipedeBodyPool::ReturnBody(CentipedeBody* b)
{
	recycledItems.push(static_cast<CentipedeBody*>(b));
}
