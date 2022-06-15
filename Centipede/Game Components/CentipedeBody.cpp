#include "CentipedeBody.h"
#include "MovementCollection.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "MoveLeftandDown.h"
#include "CentipedeHead.h"
#include "CentipedeHeadFactory.h"
#include "ScoreManager.h"
#include "MoveDownPoison.h"
#include "MoveDownPoisonLeft.h"
#include "MoveRightandDown.h"
#include "SoundManager.h"
#include "CritterManager.h"
#include "EnemyExplosionFactory.h"
#include "MoveLeftandUp.h"
#include "GameController.h"
#include "MoveRightandUp.h"

void CentipedeBody::Initialize(sf::Vector2f P, Grid* grid, int s)
{
	Pos = P;
	speed = s;

	myGrid = grid;

	pNext = nullptr;
	pPrev = nullptr;

	STOP = false;

	bitmap = &ResourceManager::GetTextureBitmap("CentiB");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentiB"), 8, 2, 30.0F, 0, 7, true, true);

	MainSprite.setScale(4, 4);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	SetCollider(MainSprite, *bitmap);
	RegisterCollision<CentipedeBody>(*this);

	frames = 0;
	MaxFrames = 12 - speed;

	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentiBodyKilled);

	pCurrentState = &MoveFSM::StateMoveLeftandDown;

	pDeathSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::EnemyDeath);

	CritterManager::AddCritter(this);
}

void CentipedeBody::Update()
{
	if (!STOP)
	{
		if (frames < MaxFrames)
		{
			Pos.x += pCurrentState->GetMoveOffsets()->rowoffset * speed;
			Pos.y += pCurrentState->GetMoveOffsets()->coloffset * speed;
			//MainSprite.rotate(pCurrentState->GetMoveOffsets()->rotation * speed);

			frames++;
		}
		else
		{
			frames = 0;
		}
	}

	MainSprite.setPosition(Pos);
	MainSprite.Update();

}

void CentipedeBody::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeBody::Destroy()
{
	DeregisterCollision<CentipedeBody>(*this);
}

void CentipedeBody::Collision(Bullet* other)
{
	EnemyExplosionFactory::CreateEnemyExplosion(Pos);

	if (this->pCurrentState == &MoveFSM::StateMoveLeftandDown || this->pCurrentState == &MoveFSM::StateMoveLeftandUp || this->pCurrentState == &MoveFSM::StateMoveDownPoisonLeft)
	{
		myGrid->addShroomHere(sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y));
	}
	else if(this->pCurrentState == &MoveFSM::StateMoveRightandDown || this->pCurrentState == &MoveFSM::StateMoveRightandUp || this->pCurrentState == &MoveFSM::StateMoveDownPoison)
	{
		myGrid->addShroomHere(sf::Vector2f(Pos.x + GameController::ScreenMult, Pos.y));
	}
	else
	{
		myGrid->addShroomHere(this->Pos);
	}

	if (this->pNext != nullptr)
	{
		this->pNext->becomehead();
	}
	if (this->pPrev != nullptr)
	{
		this->pPrev->setNext(nullptr);
	}

	ScoreManager::SendScoreCmd(pDeath);
	SoundManager::SendSoundCmd(pDeathSound);
	CritterManager::RemoveCritter(this);
	CritterManager::removeCenties();

	MarkForDestroy();
}

const void CentipedeBody::becomehead()
{
	CentipedeBase* pHead;
	const MoveState* newState;
	if(pCurrentState == &MoveFSM::StateMoveDownPoison)
	{
		while(frames < MaxFrames)
		{
			Pos.x += pCurrentState->GetMoveOffsets()->rowoffset * speed;
			Pos.y += pCurrentState->GetMoveOffsets()->coloffset * speed;

			frames++;
		}
		newState = &MoveFSM::StateMoveRightandDown;
	}
	else if(pCurrentState == &MoveFSM::StateMoveDownPoisonLeft)
	{
		while (frames < MaxFrames)
		{
			Pos.x += pCurrentState->GetMoveOffsets()->rowoffset * speed;
			Pos.y += pCurrentState->GetMoveOffsets()->coloffset * speed;

			frames++;
		}
		newState = &MoveFSM::StateMoveLeftandDown;
	}
	else
	{
		newState = pCurrentState;
	}
	pHead = CentipedeHeadFactory::CreateHead(Pos, myGrid, frames, newState, speed);
	if (this->pNext != nullptr)
	{
		pHead->setNext(this->pNext);
		this->pNext->setPrev(pHead);
	}

	MarkForDestroy();
}
