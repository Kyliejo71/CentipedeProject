#include "CmdScoreByDistance.h"
#include "ScoreManager.h"
#include "GameController.h"
#include "SpiderNumbersFactory.h"

int CmdScoreByDistance::distanceCalc(int x1, int y1, int x2, int y2)
{
	return (int)(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) * 1.0));
}

CmdScoreByDistance::CmdScoreByDistance(int dn, int dm, int df,
	int vn, int vm, int vf)
	: dNear(dn), dMed(dm), dFar(df), vNear(vn), vMed(vm), vFar(vf)
{
	finalVal = 0;
}

void CmdScoreByDistance::Execute()
{
	shipPos = GameController::getCurrShipPos();
	spiderPos = GameController::getSpiderDeathPos();

	int ans = distanceCalc((int)shipPos.x, (int)shipPos.y, (int)spiderPos.x, (int)spiderPos.y);

	
	if (ans <= dNear)
	{
		ScoreManager::AddScore(vNear);
		finalVal = vNear;
	}
	else if (ans <= dMed)
	{
		ScoreManager::AddScore(vMed);
		finalVal = vMed;
	}
	else
	{
		ScoreManager::AddScore(vFar);
		finalVal = vFar;
	}

	SetAlarm(0, 0.1f);
}

void CmdScoreByDistance::Alarm0()
{
	SpiderNumbersFactory::CreateSpiderNumbers(spiderPos, finalVal);
}
