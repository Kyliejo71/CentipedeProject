#ifndef _CentipedeSpawner
#define _CentipedeSpawner

#include "TEAL\CommonElements.h"

class Grid;
class CmdSound;

class CentipedeSpawner : public GameObject
{
public:
	CentipedeSpawner(Grid* myGrid);
	~CentipedeSpawner() = default;
	CentipedeSpawner(const CentipedeSpawner&) = delete;
	CentipedeSpawner& operator=(const CentipedeSpawner&) = default;

	void startSpawning(int speed, int length, Grid* newGrid);

private:

	Grid* myGrid;

	int speed;
	int length;

	sf::Vector2f startingPos;

	CmdSound* pCentiLoop;

};

#endif _CentipedeSpawner
