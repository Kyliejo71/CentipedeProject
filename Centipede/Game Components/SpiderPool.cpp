#include "SpiderPool.h"
#include "TEAL\CommonElements.h"
#include "Spider.h"

SpiderPool::SpiderPool()
{
}

SpiderPool::~SpiderPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Spider* SpiderPool::GetSpider()
{
	Spider* s;

	if (recycledItems.empty())
	{
		s = new Spider();
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();	

		s->RegisterToCurrentScene();
	}

	return s;
}

void SpiderPool::ReturnSpider(Spider* s)
{
	recycledItems.push(static_cast<Spider*>(s));
}