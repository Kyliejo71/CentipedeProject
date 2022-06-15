#include "CritterManager.h"
#include "Spider.h"
#include "Flea.h"
#include "Scorp.h"
#include "CentipedeBody.h"
#include "CentipedeHead.h"
#include "GameController.h"
#include "SoundManager.h"

CritterManager* CritterManager::ptrInstance = NULL;

CritterManager::CritterManager()
{
	totalCenti = 0;
	totalSpiders = 0;
	pStopCenti = SoundManager::GetSoundCommand(SoundManager::SoundEvents::StopCentiLoop);
	pStopSpider = SoundManager::GetSoundCommand(SoundManager::SoundEvents::StopSpiderLoop);
}

void CritterManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

void CritterManager::privAddCritter(Critter* addMe)
{
	this->onScreenCritters.push_back(addMe);
}

void CritterManager::privRemoveCritter(Critter* removeMe)
{
	this->onScreenCritters.remove(removeMe);
}

void CritterManager::privEndOfRound()
{
	SoundManager::SendSoundCmd(pStopCenti);
	SoundManager::SendSoundCmd(pStopSpider);

	totalCenti = 0;
	totalSpiders = 0;

	Critter* removeThis;

	for(int i = this->onScreenCritters.size(); i > 0; i--)
	{
		removeThis = this->onScreenCritters.front();
		removeThis->MarkForDestroy();
		this->onScreenCritters.pop_front();
	}
}

void CritterManager::privAddCenties()
{
	this->totalCenti += 1;
}

void CritterManager::privRemoveCenties()
{
	this->totalCenti -= 1;
	if(totalCenti <= 0)
	{
		SoundManager::SendSoundCmd(pStopCenti);
		GameController::nextRound();
	}
}

void CritterManager::privAddSpiders()
{
	this->totalSpiders += 1;
}

void CritterManager::privRemoveSpiders()
{
	this->totalSpiders -= 1;
	if (totalSpiders <= 0)
	{
		SoundManager::SendSoundCmd(pStopSpider);
	}
}

void CritterManager::privStopMoving()
{
	SoundManager::SendSoundCmd(pStopCenti);
	SoundManager::SendSoundCmd(pStopSpider);

	std::list<Critter*> backUp;
	backUp = onScreenCritters;
	for (int i = backUp.size(); i > 0; i--)
	{
		if (backUp.front() != nullptr)
		{
			backUp.front()->stopMoving();
			backUp.pop_front();
		}
	}

}
