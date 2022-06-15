#include "SpiderFactory.h"
#include "TEAL\CommonElements.h"
#include "SpiderPool.h"
#include "Spider.h"

SpiderFactory* SpiderFactory::ptrInstance = nullptr;

void SpiderFactory::privCreateSpider(sf::Vector2f p, Grid* grid, bool isRightw, int speed)
{
	Spider* s = mySpiderPool.GetSpider();

	s->SetExternalManagement(RecycleSpider);
	
	s->Initialize(p, grid, isRightw, speed);
}

void SpiderFactory::privRecycleSpider(GameObject* s)
{
	mySpiderPool.ReturnSpider(static_cast<Spider*>(s));
}

void SpiderFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
