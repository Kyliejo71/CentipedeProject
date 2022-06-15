#ifndef _WaveManager
#define _WaveManager

#include "TEAL\CommonElements.h"
#include <array>
#include <string>
#include <list>

class Wave;
class Grid;
class FleaSpawner;
class SpiderSpawner;
class ScorpSpawner;
class CentipedeSpawner;
class SoloHeadSpawner;

class WaveManager
{
private:
	static WaveManager* ptrInstance;

	WaveManager();
	WaveManager(const WaveManager&) = delete;
	WaveManager& operator=(const WaveManager&) = delete;
	~WaveManager() = default;

	static WaveManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new WaveManager;
		return *ptrInstance;
	};

	std::array<std::string, 19> waveSettings = { "Wave", "CentipedeLength", "CentipedeSpeed", "SoloHead", "SoloHeadSpeed", "SoloHeadCount", "SoloHeadSpeed",
							  "SoloHeadPlayerArea", "SoloHeadPlayerAreaSpeed", "SoloHeadPlayerAreaCount", "Flea", "FleaMushroomTriggerValue",
							  "FleaMushroomSpawnProbability", "Scorpion", "ScorpionSpeed", "ScorpionSpawnRate", "Spider", "SpiderSpeed", "SpiderSpawnRate" };

	Wave* waveList[20];

	Wave* currWave;
	FleaSpawner* fSpawn;
	SpiderSpawner* sSpawn;
	ScorpSpawner* scSpawn;
	CentipedeSpawner* cSpawn;
	SoloHeadSpawner* shSpawn;

	Grid* currGrid;

	int totalWaves;
	int currWaveIndex;

	void privReadFiles();
	void privResetOnDeath();
	void privNextWave();
	void privStopSpawning();
	void privRestartGame(Grid* currgrid);
	void privStartSpawningPACenties();

public:

	static void readFiles() { Instance().privReadFiles(); };
	static void resetOnDeath() { Instance().privResetOnDeath(); };
	static void nextWave() { Instance().privNextWave(); };
	static void stopSpawning() { Instance().privStopSpawning(); };
	static void restartGame(Grid* currGrid) { Instance().privRestartGame(currGrid); };
	static void startSpawningPACenties() { Instance().privStartSpawningPACenties(); };
	static void Terminate();
};

#endif _WaveManager
