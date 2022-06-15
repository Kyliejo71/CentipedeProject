#include "WaveManager.h"
#include "Wave.h"
#include "FleaSpawner.h"
#include "SpiderSpawner.h"
#include "ScorpSpawner.h"
#include "CentipedeSpawner.h"
#include "SoloHeadSpawner.h"
#include <fstream>
#include <sstream>
#include "Grid.h"

using namespace std;

WaveManager* WaveManager::ptrInstance = NULL;

WaveManager::WaveManager()
{
	waveList[20];

	currWave = nullptr;
	fSpawn = new FleaSpawner(currGrid);
	sSpawn = new SpiderSpawner(currGrid);
	scSpawn = new ScorpSpawner(currGrid);
	cSpawn = new CentipedeSpawner(currGrid);
	shSpawn = new SoloHeadSpawner(currGrid);

	currGrid = nullptr;

	totalWaves = 0;
	currWaveIndex = 0;
}

void WaveManager::privReadFiles()
{
	int waveNumber = 0;
	int thisWave;
	int streamIn;

	totalWaves = 0;
	currWaveIndex = 0;

	currGrid = nullptr;

	stringstream s;
	string info;

	ifstream wavefile;
	wavefile.open("wavetest.txt", ios::in);

	Wave* newWave;

	while(getline(wavefile, info, ':'))
	{	
		if(info == waveSettings.at(0)) // WAVE NUMBER
		{
			waveNumber++;

			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> thisWave;

			assert(waveNumber == thisWave && "Wave skipped!!!!");
			
			newWave = new Wave(thisWave);

			this->waveList[waveNumber -1] = newWave;
		}
		else if(info == waveSettings.at(1)) // CENTIPEDE LENGTH
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setCentiLength(streamIn);
		}
		else if (info == waveSettings.at(2)) //CENTIPEDE SPEED
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setCentiSpeed(streamIn);
		}
		else if (info == waveSettings.at(3)) //SOLO HEAD
		{
			getline(wavefile, info, '\n');
			if(info == " off")
			{
				newWave->setHeadSwitch(false);
			}
			else
			{
				newWave->setHeadSwitch(true);
			}
		}
		else if (info == waveSettings.at(4)) //SOLO HEAD SPEED
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setHeadSpeed(streamIn);
		}
		else if (info == waveSettings.at(5)) //SOLO HEAD COUNT
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setHeadCount(streamIn);
		}
		else if (info == waveSettings.at(6))//SOLO HEAD SPEED
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setHeadSpeed(streamIn);
		}
		else if (info == waveSettings.at(7))//SOLO HEAD PA SWITCH
		{
			getline(wavefile, info, '\n');
			if (info == " off")
			{
				newWave->setHeadPASwitch(false);
			}
			else
			{
				newWave->setHeadPASwitch(true);
			}
		}
		else if (info == waveSettings.at(8))//SOLO HEAD PA SPEED
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setHeadPASpeed(streamIn);
		}
		else if (info == waveSettings.at(9))//SOLO HEAD PA COUNT
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setHeadPACount(streamIn);
		}
		else if (info == waveSettings.at(10))//FLEA SWITCH
		{
			getline(wavefile, info, '\n');
			if (info == " off")
			{
				newWave->setFleaSwitch(false);
			}
			else
			{
				newWave->setFleaSwitch(true);
			}
		}
		else if (info == waveSettings.at(11))//FLEA MUSH TRIGGER VALUE
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setFleaMushTriggerValue(streamIn);
		}
		else if (info == waveSettings.at(12))//FLEA MUSH SPAWN PROBABILITY
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setFleaMushSpawnProbability(streamIn);
		}
		else if (info == waveSettings.at(13))//SCORP SWITCH
		{
			getline(wavefile, info, '\n');
			if (info == " off")
			{
				newWave->setScorpSwitch(false);
			}
			else
			{
				newWave->setScorpSwitch(true);
			}
		}
		else if (info == waveSettings.at(14))//SCORPION SPEED
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setScorpSpeed(streamIn);
		}
		else if (info == waveSettings.at(15))//SCORP SPAWN RATE
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setScorpSpawnRate(streamIn);
		}
		else if (info == waveSettings.at(16))//SPIDER SWITCH
		{
			getline(wavefile, info, '\n');
			if (info == " off")
			{
				newWave->setSpiderSwitch(false);
			}
			else
			{
				newWave->setSpiderSwitch(true);
			}
		}
		else if (info == waveSettings.at(17))//SPIDER SPEED
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setSpiderSpeed(streamIn);
		}
		else if (info == waveSettings.at(18))//SPIDER SPAWN RATE
		{
			getline(wavefile, info, '\n');
			stringstream s(info);
			s >> streamIn;
			newWave->setSpiderSpawnRate(streamIn);
		}
	}
	totalWaves = waveNumber;
	this->currWave = waveList[0];

	wavefile.close();
}

void WaveManager::privResetOnDeath()
{
	fSpawn->stopSpawning();
	sSpawn->stopSpawning();
	scSpawn->stopSpawning();

	if (currWave->getFleaSwitch())
	{
		fSpawn->startSpawning(currWave->getFleaMushTriggerValue(), currWave->getFleaMushSpawnProbability(), currGrid);
	}
	if (currWave->getSpiderSwitch())
	{
		sSpawn->startSpawning(currWave->getSpiderSpeed(), currWave->getSpiderSpawnRate(), currGrid);
	}
	if (currWave->getScorpSwitch())
	{
		scSpawn->startSpawning(currWave->getScorpSpeed(), currWave->getScorpSpawnRate(), currGrid);
	}
	if (currWave->getSoloHeadSwitch())
	{
		shSpawn->startSpawningTop(currWave->getSoloHeadSpeed(), currWave->getSoloHeadCount(), currGrid);
	}
	cSpawn->startSpawning(currWave->getCentiSpeed(), currWave->getCentLength(), currGrid);
}

void WaveManager::privNextWave()
{
	Wave* pNext;
	totalWaves--;

	if (totalWaves > 0)
	{
		currWaveIndex++;

		pNext = waveList[currWaveIndex];
		currWave = pNext;
	}

	if (currWave->getFleaSwitch())
	{
		fSpawn->startSpawning(currWave->getFleaMushTriggerValue(), currWave->getFleaMushSpawnProbability(), currGrid);
	}
	if (currWave->getSpiderSwitch())
	{
		sSpawn->startSpawning(currWave->getSpiderSpeed(), currWave->getSpiderSpawnRate(), currGrid);
	}
	if (currWave->getScorpSwitch())
	{
		scSpawn->startSpawning(currWave->getScorpSpeed(), currWave->getScorpSpawnRate(), currGrid);
	}
	if (currWave->getSoloHeadSwitch())
	{
		shSpawn->startSpawningTop(currWave->getSoloHeadSpeed(), currWave->getSoloHeadCount(), currGrid);
	}
	cSpawn->startSpawning(currWave->getCentiSpeed(), currWave->getCentLength(), currGrid);

}

void WaveManager::privStopSpawning()
{
	fSpawn->stopSpawning();
	sSpawn->stopSpawning();
	scSpawn->stopSpawning();
}

void WaveManager::privRestartGame(Grid* newGrid)
{
	currGrid = newGrid;

	currWaveIndex = 0; 
	currWave = waveList[currWaveIndex];

	if (currWave->getFleaSwitch())
	{
		fSpawn->startSpawning(currWave->getFleaMushTriggerValue(), currWave->getFleaMushSpawnProbability(), currGrid);
	}
	if (currWave->getSpiderSwitch())
	{
		sSpawn->startSpawning(currWave->getSpiderSpeed(), currWave->getSpiderSpawnRate(), currGrid);
	}
	if (currWave->getScorpSwitch())
	{
		scSpawn->startSpawning(currWave->getScorpSpeed(), currWave->getScorpSpawnRate(), currGrid);
	}
	if (currWave->getSoloHeadSwitch())
	{
		shSpawn->startSpawningTop(currWave->getSoloHeadSpeed(), currWave->getSoloHeadCount(), currGrid);
	}
	cSpawn->startSpawning(currWave->getCentiSpeed(), currWave->getCentLength(), currGrid);

}

void WaveManager::privStartSpawningPACenties()
{
	if(currWave->getSoloHeadPASwitch())
	{
		shSpawn->startSpawningPA(currWave->getSoloHeadPASpeed(), currWave->getSoloHeadPACount(), currGrid);
	}
}

void WaveManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
