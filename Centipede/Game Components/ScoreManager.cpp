#include "ScoreManager.h"
#include "CmdScoreValue.h"
#include "CmdScoreByDistance.h"
#include "PlayerManager.h"
#include "Player.h"
#include "HUD.h"

ScoreManager* ScoreManager::ptrInstance = NULL;

ScoreManager::ScoreManager()
{
	lastFinalScore = 0;
}

CmdScore* ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	CmdScore* pCmd = nullptr;

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		pCmd = new CmdScoreValue(FleaDeath);
		break;
	case ScoreEvents::ScorpionKilled:
		pCmd = new CmdScoreValue(ScorpionDeath);
		break;
	case ScoreEvents::MushroomKilled:
		pCmd = new CmdScoreValue(MushroomDeath);
		break;
	case ScoreEvents::SpiderKilled:
		pCmd = new CmdScoreByDistance(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
			SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		break;
	case ScoreEvents::MushroomPoisonKilled:
		pCmd = new CmdScoreValue(MushroomPoisonDeath);
		break;
	case ScoreEvents::CentiHeadKilled:
		pCmd = new CmdScoreValue(CentiHeadDeath);
		break;
	case ScoreEvents::CentiBodyKilled:
		pCmd = new CmdScoreValue(CentiBodyDeath);
		break;
	default:
		break;
	}

	return pCmd;
}

void ScoreManager::AddScore(int val)
{
	Player* addToMe = PlayerManager::returnCurrPlayer();

	addToMe->addToScore(val);

	HUD::ScoreUpdate(addToMe->getScore());

	if(addToMe->getScore() >= (HighScoreMult * addToMe->getTotalExtraLives()))
	{
		addToMe->addExtraLife();
		HUD::ExtraLife();
	}
}

void ScoreManager::SendScoreCmd(CmdScore* c)
{
	Instance().QueueCmds.push(c);
}

void ScoreManager::ProcessScores()
{
	Instance().privProcessScore();
}

void ScoreManager::privProcessScore()
{
	CmdScore* c;

	while (!QueueCmds.empty())
	{
		c = QueueCmds.front();
		c->Execute();

		QueueCmds.pop();
	}
}

void ScoreManager::privSetLastFinalScore(int val)
{
	this->lastFinalScore = val;
}

std::string ScoreManager::privGetLastFinalScore()
{
	std::string newString;
	if(lastFinalScore == 0)
	{
		newString = std::to_string(lastFinalScore) + "0";
	}
	else
	{
		newString = std::to_string(lastFinalScore);
	}

	return newString;
}

void ScoreManager::Update()
{
	this->ProcessScores();
}

void ScoreManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
