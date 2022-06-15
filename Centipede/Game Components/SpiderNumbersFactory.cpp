#include "SpiderNumbersFactory.h"
#include "TEAL\CommonElements.h"
#include "SpiderNumbersPool.h"
#include "SpiderNumbers.h"

SpiderNumbersFactory* SpiderNumbersFactory::ptrInstance = nullptr;


void SpiderNumbersFactory::privCreateSpiderNumbers(sf::Vector2f pos, int val)
{
	SpiderNumbers* s = mySpiderNumbersPool.GetSpiderNumbers();

	s->SetExternalManagement(RecycleSpiderNumbers);

	s->Initialize(pos, val);
}

void SpiderNumbersFactory::privRecycleSpiderNumbers(GameObject* s)
{
	mySpiderNumbersPool.ReturnSpiderNumbers(static_cast<SpiderNumbers*>(s));
}

void SpiderNumbersFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
