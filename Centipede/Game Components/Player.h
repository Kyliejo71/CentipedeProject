#ifndef _Player
#define _Player

#include "TEAL\CommonElements.h"

class Grid;
class Mushroom;

class Player : public GameObject
{
public:
	Player(int totalLives);
	~Player() = default;
	Player(const Player&) = delete;
	Player& operator=(const Player&) = default;

	virtual void Destroy();

	Grid* getGrid();
	void addToScore(int points);
	void lostLife();
	int getLives();
	int getScore();
	void addExtraLife();
	int getTotalExtraLives();

private:

	int Score;
	int Lives;
	int waveNumber;

	int totalExtraLives;

	Grid* myGrid;

};

#endif _Player
