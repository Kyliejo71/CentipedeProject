#include "SoundManager.h"
#include "CmdSoundPlay.h"
#include "CmdSoundPlayerDeath.h"
#include "CmdSoundExtraLife.h"
#include "CmdSoundShotOne.h"
#include "CmdSoundShotTwo.h"
#include "CmdSoundNewFlea.h"
#include "CmdSoundEnemyDeath.h"
#include "CmdSoundNewCenti.h"
#include "CmdSoundNewScorp.h"
#include "CmdSoundNewSpider.h"
#include "CmdSoundCentiSound.h"
#include "CmdSoundSpiderSound.h"
#include "CmdSoundStopCenti.h"
#include "CmdSoundStopSpider.h"
#include "SoundStrategy.h"
#include "SoundStrategyMute.h"

SoundManager* SoundManager::ptrInstance = NULL;

CmdSound* SoundManager::GetSoundCommand(SoundEvents ev)
{
	CmdSound* pCmd = nullptr;

	switch (ev)
	{
	case SoundEvents::CentipedeSound:
		pCmd = new CmdSoundCentiSound();
		break;
	case SoundEvents::MushBonus:
		pCmd = new CmdSoundPlay();
		break;
	case SoundEvents::PlayerDeath:
		pCmd = new CmdSoundPlayerDeath();
		break;
	case SoundEvents::ExtraLife:
		pCmd = new CmdSoundExtraLife();
		break;
	case SoundEvents::Shot1:
		pCmd = new CmdSoundShotOne();
		break;
	case SoundEvents::Shot2:
		pCmd = new CmdSoundShotTwo();
		break;
	case SoundEvents::NewFlea:
		pCmd = new CmdSoundNewFlea();
		break;
	case SoundEvents::EnemyDeath:
		pCmd = new CmdSoundEnemyDeath();
		break;
	case SoundEvents::NewCenti:
		pCmd = new CmdSoundNewCenti();
		break;
	case SoundEvents::NewScorp:
		pCmd = new CmdSoundNewScorp();
		break;
	case SoundEvents::NewSpider:
		pCmd = new CmdSoundNewSpider();
		break;
	case SoundEvents::SpiderSound:
		pCmd = new CmdSoundSpiderSound();
		break;
	case SoundEvents::StopCentiLoop:
		pCmd = new CmdSoundStopCenti();
		break;
	case SoundEvents::StopSpiderLoop:
		pCmd = new CmdSoundStopSpider();
		break;
	default:
		break;
	}

	return pCmd;
}

SoundManager::SoundManager()
{
	centiSound.setBuffer(ResourceManager::GetSound("CentiStep"));
	centiSound.setVolume(25);
	centiSound.setLoop(true);

	mushBonus.setBuffer(ResourceManager::GetSound("BonusMush"));
	mushBonus.setVolume(25);

	playerDeath.setBuffer(ResourceManager::GetSound("PlayerDeath"));
	playerDeath.setVolume(50);

	extraLife.setBuffer(ResourceManager::GetSound("ExtraLife"));
	extraLife.setVolume(25);

	shotOne.setBuffer(ResourceManager::GetSound("ShootOne"));
	shotOne.setVolume(25);

	shotTwo.setBuffer(ResourceManager::GetSound("ShootTwo"));
	shotTwo.setVolume(25);

	newFlea.setBuffer(ResourceManager::GetSound("NewFlea"));
	newFlea.setVolume(25);

	enemyDeath.setBuffer(ResourceManager::GetSound("EnemyDeath"));
	enemyDeath.setVolume(25);

	newCenti.setBuffer(ResourceManager::GetSound("NewCenti"));
	newCenti.setVolume(25);

	newScorp.setBuffer(ResourceManager::GetSound("NewScorp"));
	newScorp.setVolume(25);

	newSpider.setBuffer(ResourceManager::GetSound("NewSpider"));
	newSpider.setVolume(25);

	spiderSound.setBuffer(ResourceManager::GetSound("SpiderSong"));
	spiderSound.setVolume(25);
	spiderSound.setLoop(true);

	isSpiderOn = false;
	isCentiOn = false;

	myStrategy = new SoundStrategyMute();
}

void SoundManager::Update()
{
	this->ProcessSound();
}

void SoundManager::privAddSoundCentiLoop()
{
	if (!isCentiOn)
	{
		centiSound.play();
		isCentiOn = true;
	}
}

void SoundManager::privAddSoundMushBonus()
{
	mushBonus.play();
}

void SoundManager::privAddSoundPlayerDeath()
{
	playerDeath.play();
}

void SoundManager::privAddSoundExtraLife()
{
	extraLife.play();
}

void SoundManager::privAddSoundShotOne()
{
	shotOne.play();
}

void SoundManager::privAddSoundShotTwo()
{
	shotTwo.play();
}

void SoundManager::privAddSoundNewFlea()
{
	newFlea.play();
}

void SoundManager::privAddSoundEnemyDeath()
{
	enemyDeath.play();
}

void SoundManager::privAddSoundNewCenti()
{
	newCenti.play();
}

void SoundManager::privAddSoundNewScorp()
{
	newScorp.play();
}

void SoundManager::privAddSoundNewSpider()
{
	newSpider.play();
}

void SoundManager::privAddSoundSpiderLoop()
{
	if (!isSpiderOn)
	{
		spiderSound.play();
		isSpiderOn = true;
	}
}

void SoundManager::privStopSoundCentiLoop()
{
	centiSound.stop();
	isCentiOn = false;
}

void SoundManager::privStopSoundSpiderLoop()
{
	spiderSound.stop();
	isSpiderOn = false;
}

void SoundManager::privSendSoundCommand(CmdSound* c)
{
	this->myStrategy->getCmdForSM(c);
}

void SoundManager::privSetStrategy(SoundStrategy* newStrat)
{
	this->myStrategy = newStrat;
}

void SoundManager::SendSoundCommandAfterStrategy(CmdSound* c)
{
	Instance().QueueCmds.push(c);
}

void SoundManager::ProcessSound()
{
	Instance().privProcessSound();
}

void SoundManager::privProcessSound()
{
	CmdSound* c;

	while (!QueueCmds.empty())
	{
		c = QueueCmds.front();
		c->Execute();

		QueueCmds.pop();
	}
}

void SoundManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
