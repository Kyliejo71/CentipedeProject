#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "MoveLeftandDown.h"
#include "Grid.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "CritterManager.h"
#include "EnemyExplosionFactory.h"
#include "GameController.h"
#include "MoveLeftandUp.h"
#include "MoveDownPoisonLeft.h"
#include "MoveRightandDown.h"
#include "MoveRightandUp.h"
#include "MoveDownPoison.h"

void CentipedeHead::Initialize(sf::Vector2f P, Grid* grid, int currFrames, const MoveState* currState, int s)
{
	Pos = P;

	myGrid = grid;

	frames = currFrames;

	pCurrentState = currState;

	pNext = nullptr;
	pPrev = nullptr;

	speed = s;
	MaxFrames = 12 - speed;

	hitPoisioned = false;
	STOP = false;

	pDeath = ScoreManager::GetScoreCommand(ScoreManager::ScoreEvents::CentiHeadKilled);


	bitmap = &ResourceManager::GetTextureBitmap("CentiH");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentiH"), 8, 2, 30.0F, 0, 7, true, true);

	MainSprite.setScale(4, 4);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	SetCollider(MainSprite, *bitmap);
	RegisterCollision<CentipedeHead>(*this);

	pDeathSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::EnemyDeath);
	pSound = SoundManager::GetSoundCommand(SoundManager::SoundEvents::NewCenti);
	SoundManager::SendSoundCmd(pSound);

	CritterManager::AddCritter(this);
}

void CentipedeHead::Update()
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
			if (this->pNext != nullptr)
			{
				this->pNext->passState(pCurrentState);
			}
			pCurrentState = pCurrentState->GetNextState(Pos, myGrid, this);

		}
	}

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void CentipedeHead::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeHead::Destroy()
{
	DeregisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::Collision(Bullet* other)
{
	EnemyExplosionFactory::CreateEnemyExplosion(Pos);

	if (this->pCurrentState == &MoveFSM::StateMoveLeftandDown || this->pCurrentState == &MoveFSM::StateMoveLeftandUp || this->pCurrentState == &MoveFSM::StateMoveDownPoisonLeft)
	{
		myGrid->addShroomHere(sf::Vector2f(Pos.x - GameController::ScreenMult, Pos.y));
	}
	else if (this->pCurrentState == &MoveFSM::StateMoveRightandDown || this->pCurrentState == &MoveFSM::StateMoveRightandUp || this->pCurrentState == &MoveFSM::StateMoveDownPoison)
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

	ScoreManager::SendScoreCmd(pDeath);
	SoundManager::SendSoundCmd(pDeathSound);
	CritterManager::RemoveCritter(this);
	CritterManager::removeCenties();

	MarkForDestroy();
}

const void CentipedeHead::becomehead()
{
}


