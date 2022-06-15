#include "ScorpPool.h"
#include "TEAL\CommonElements.h"
#include "Scorp.h"

ScorpPool::ScorpPool()
{
}

ScorpPool::~ScorpPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Scorp* ScorpPool::GetScorp()
{
	Scorp* s;

	if (recycledItems.empty())
	{
		s = new Scorp();
	}
	else
	{

		s = recycledItems.top();
		recycledItems.pop();	

		s->RegisterToCurrentScene();
	}

	return s;
}

void ScorpPool::ReturnScorp(Scorp* s)
{
	recycledItems.push(static_cast<Scorp*>(s));
}