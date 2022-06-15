#include "CentipedeHeadPool.h"
#include "TEAL\CommonElements.h"
#include "CentipedeHead.h"

CentipedeHeadPool::CentipedeHeadPool()
{
}

CentipedeHeadPool::~CentipedeHeadPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeHead* CentipedeHeadPool::GetHead()
{
	CentipedeHead* h;

	if (recycledItems.empty())
	{
		h = new CentipedeHead();
	}
	else
	{
		h = recycledItems.top();
		recycledItems.pop();
		h->RegisterToCurrentScene();
	}

	return h;
}

void CentipedeHeadPool::ReturnHead(CentipedeHead* h)
{
	recycledItems.push(static_cast<CentipedeHead*>(h));
}