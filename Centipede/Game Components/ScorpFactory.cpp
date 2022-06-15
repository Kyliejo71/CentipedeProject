#include "ScorpFactory.h"
#include "TEAL\CommonElements.h"
#include "ScorpPool.h"
#include "Scorp.h"

ScorpFactory* ScorpFactory::ptrInstance = nullptr;

void ScorpFactory::privCreateScorp(sf::Vector2f pos, Grid* grid, bool isRight, int speed)
{
	Scorp* s = myScorpPool.GetScorp();

	s->SetExternalManagement(RecycleScorp);

	s->Initialize(pos, grid, isRight, speed);
}

void ScorpFactory::privRecycleScorp(GameObject* s)
{
	myScorpPool.ReturnScorp(static_cast<Scorp*>(s));
}

void ScorpFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}