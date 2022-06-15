#include "FleaPool.h"
#include "TEAL\CommonElements.h"
#include "Flea.h"

FleaPool::FleaPool()
{
}

FleaPool::~FleaPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Flea* FleaPool::GetFlea()
{
	Flea* f;

	if (recycledItems.empty())
	{
		f = new Flea();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();	
		f->RegisterToCurrentScene();
	}

	return f;
}

void FleaPool::ReturnFlea(Flea* f)
{
	recycledItems.push(static_cast<Flea*>(f));
}