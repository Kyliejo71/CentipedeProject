#include "GameController.h"
#include "PlayerManager.h"
#include "Player.h"
#include "CritterManager.h"
#include "WaveManager.h"
#include "Ship.h"
#include "Grid.h"
#include "HighScoreManager.h"
#include "ShipFactory.h"
#include "HUD.h"
#include "ScoreManager.h"
#include "SoundManager.h"
#include "SoundStrategyMute.h"
#include "SoundStrategySound.h"
#include "ShipStrategyAttractor.h"
#include "ShipStrategyKeyboard.h"

GameController* GameController::ptrInstance = NULL;

void GameController::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

GameController::GameController()
{
	currPlayer = nullptr;
	currGrid = nullptr;
	playerShip = nullptr;

	gameEnded = false;

	pAttractorStrat = new ShipStrategyAttractor();
	pKeyboardStrat = new ShipStrategyKeyboard();
	pYesSound = new SoundStrategySound();
	pNoSound = new SoundStrategyMute();
}

void GameController::privAttractorStart()
{
	currStrat = pAttractorStrat;

	gameEnded = false;

	currPlayer = PlayerManager::returnCurrAttractor();
	currGrid = currPlayer->getGrid();

	SoundManager::SetStrategy(pNoSound);
	WaveManager::restartGame(currGrid);

	playerShip = ShipFactory::CreateShip(currStrat);
}

void GameController::privGameStart()
{
	currStrat = pKeyboardStrat;

	WaveManager::stopSpawning();
	CritterManager::EndOfRound();

	PlayerManager::playerOneStart();

	currPlayer = PlayerManager::returnCurrPlayer();
	currGrid = currPlayer->getGrid();

	playerShip = ShipFactory::CreateShip(currStrat);

	SoundManager::SetStrategy(pYesSound);
	WaveManager::restartGame(currGrid);
}

void GameController::privGameOver()
{
	gameEnded = true;

	WaveManager::stopSpawning();
	CritterManager::stopMoving();

	this->currGrid->regenShrooms();
}

void GameController::privLifeLost()
{
	if (!gameEnded)
	{
		WaveManager::stopSpawning();
		CritterManager::stopMoving();

		this->currGrid->regenShrooms();
	}
}

void GameController::privNextRound()
{
	WaveManager::stopSpawning();
	CritterManager::EndOfRound();

	WaveManager::nextWave();
}

void GameController::privnextRoundAfterDeath()
{
	HUD::LifeLost();
	CritterManager::EndOfRound();
	WaveManager::resetOnDeath();
	playerShip = ShipFactory::CreateShip(currStrat);
}

sf::Vector2f GameController::privGetCurrShipPos()
{
	return this->playerShip->getpos();
}

void GameController::privSetSpiderDeathPos(sf::Vector2f Pos)
{
	this->spiderDeathPos = Pos;
}

sf::Vector2f GameController::privGetSpiderDeathPos()
{
	return this->spiderDeathPos;
}

void GameController::privContinueGame()
{
	if(this->gameEnded) //If the game ended and there are no more lives
	{
		CritterManager::EndOfRound();

		HighScoreManager::checkForNewHS(this->currPlayer->getScore());
	}
	else
	{
		this->privnextRoundAfterDeath(); //If the game can still continue
	}
}

void GameController::privAttractorEnds()
{
	this->playerShip->MarkForDestroy();
}
