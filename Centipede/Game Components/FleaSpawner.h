#ifndef _FleaSpawner
#define _FleaSpawner

#include "TEAL\CommonElements.h"

class Grid;

class FleaSpawner : public GameObject
{
public:
	FleaSpawner(Grid *myGrid);
	~FleaSpawner() = default;
	FleaSpawner(const FleaSpawner&) = delete;
	FleaSpawner& operator=(const FleaSpawner&) = default;

	void startSpawning(int trigVal, int spawn, Grid* newGrid);
	void stopSpawning();

	virtual void Alarm0();

private:

	int col;

	int triggerVal;
	int spawnProb;

	Grid* myGrid;
};

#endif _FleaSpawner
