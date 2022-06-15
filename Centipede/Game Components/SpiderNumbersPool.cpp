#include "SpiderNumbersPool.h"
#include "TEAL\CommonElements.h"
#include "SpiderNumbers.h"

SpiderNumbersPool::~SpiderNumbersPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

SpiderNumbers* SpiderNumbersPool::GetSpiderNumbers()
{
	SpiderNumbers* s;

	if (recycledItems.empty())
	{
		s = new SpiderNumbers();
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();

		s->RegisterToCurrentScene();
	}

	return s;
}

void SpiderNumbersPool::ReturnSpiderNumbers(SpiderNumbers* s)
{
	recycledItems.push(static_cast<SpiderNumbers*>(s));
}
