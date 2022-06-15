
#ifndef _SpiderSpawner
#define _SpiderSpawner

#include "TEAL\CommonElements.h"
#include "Grid.h"
#include "Spider.h"

class Grid;
class CmdSound;

class SpiderSpawner : public GameObject
{
public:
	SpiderSpawner() = delete;
	SpiderSpawner(Grid* grid);
	~SpiderSpawner() = default;
	SpiderSpawner(const SpiderSpawner&) = delete;
	SpiderSpawner& operator=(const SpiderSpawner&) = default;

	void startSpawning(int sSpeed, int spawn, Grid* newGrid);
	void stopSpawning();

	virtual void Alarm2();

private:

	Grid* myGrid;
	int whichWay; //right 1, left 0
	int xPos;
	int yPos;

	int speed;
	int spawnRate;

	CmdSound* pSpiderSound;
};

#endif _Spider