#pragma once

#ifndef _Grid
#define _Grid

#include "TEAL\CommonElements.h"
#include <list>

class Mushroom;
class FleaSpawner;
class SpiderSpawner;
class ScorpSpawner;
class CentipedeBase;
class CentipedeHead;
class CentipedeSpawner;

class Grid : public GameObject
{
public:
	
	Grid();
	~Grid() = default;
	Grid(const Grid&) = delete;
	Grid& operator=(const Grid&) = default;

	virtual void Destroy();

	void removeShroom(Mushroom* removeMe, int x, int y);
	void addShroomFlea(int col, int i, int prob);
	void noMoreShrooms();
	void startAddingShrooms();
	bool isThereAShroom(sf::Vector2f P, CentipedeBase* cb);
	void addShroomHere(sf::Vector2f P);
	bool playerAreaShrooms(int val);
	void regenShrooms();
	void scorpMovingThrough(sf::Vector2f p);

	virtual void Alarm1();
	virtual void Alarm2();

private:
	
	Mushroom* mushField[30][31];
	std::list<Mushroom*> regenList;

	float startingTotal;
	int PAVal;
	int xPos;
	int yPos;
	int totalShrooms;
	int totalPAShrooms;
	int fleaSpawnProb;
	bool addShrooms;
};

#endif _Grid