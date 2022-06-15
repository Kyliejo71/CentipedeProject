// GameStart.cpp
// Andre Berthiaume, July 2019

#include "Game.h"
#include "../BulletFactory.h"
#include "../FleaFactory.h"
#include "../ScorpFactory.h"
#include "../SpiderFactory.h"
#include "../MushroomFactory.h"
#include "../CentipedeBodyFactory.h"
#include "../CentipedeHeadFactory.h"
#include "../PlayerManager.h"
#include "../CritterManager.h"
#include "../WaveManager.h"
#include "../HighScoreManager.h"
#include "../ShipFactory.h"
#include "../EnemyExplosionFactory.h"
#include "../PlayerExplosionFactory.h"
#include "../SpiderNumbersFactory.h"

void Game::GameEnd()
{
	BulletFactory::Terminate();
	FleaFactory::Terminate();
	ScorpFactory::Terminate();
	SpiderFactory::Terminate();
	Mushroomfactory::Terminate();
	CentipedeBodyFactory::Terminate();
	CentipedeHeadFactory::Terminate();
	PlayerManager::Terminate();
	CritterManager::Terminate();
	WaveManager::Terminate();
	HighScoreManager::Terminate();
	ShipFactory::Terminate();
	EnemyExplosionFactory::Terminate();
	PlayerExplosionFactory::Terminate();
	SpiderNumbersFactory::Terminate();
}