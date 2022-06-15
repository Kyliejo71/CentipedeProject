#ifndef _SoloHeadSpawner
#define _SoloHeadSpawner

#include "TEAL\CommonElements.h"

class Grid;
class CmdSound;

class SoloHeadSpawner : public GameObject
{
public:
	SoloHeadSpawner(Grid* myGrid);
	~SoloHeadSpawner() = default;
	SoloHeadSpawner(const SoloHeadSpawner&) = delete;
	SoloHeadSpawner& operator=(const SoloHeadSpawner&) = default;

	void startSpawningTop(int speed, int count, Grid* newGrid);
	void startSpawningPA(int speed, int count, Grid* newGrid);

private:

	Grid* myGrid;

	int totalPA;

	sf::Vector2f topPos;
	sf::Vector2f PAPos;

};

#endif _CentipedeSpawner
