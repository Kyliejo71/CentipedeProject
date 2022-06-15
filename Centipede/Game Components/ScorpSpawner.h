#ifndef _ScorpSpawner
#define _ScorpSpawner

#include "TEAL\CommonElements.h"
#include "Scorp.h"
#include "Grid.h"

class Grid;

class ScorpSpawner : public GameObject
{
public:
	ScorpSpawner(Grid* myGrid);
	~ScorpSpawner() = default;
	ScorpSpawner(const ScorpSpawner&) = delete;
	ScorpSpawner& operator=(const ScorpSpawner&) = default;

	void startSpawning(int speed, int rate, Grid* newGrid);
	void stopSpawning();

	virtual void Alarm4();

private:
	int row;
	int right;

	int disFromleft;
	int disFromRight;

	int speed;
	int spawnRate;

	bool isRight;

	Grid* myGrid;
};

#endif _ScorpSpawner
