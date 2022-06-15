#include "Grid.h"
#include "MushroomFactory.h"
#include "GameController.h"
#include "Mushroom.h"
#include "FleaSpawner.h"
#include "SpiderSpawner.h"
#include "ScorpSpawner.h"
#include "CentipedeSpawner.h"
#include "CentipedeBase.h"

Grid::Grid()
{
	startingTotal = 40;
	PAVal = 23;
	totalShrooms = 0;
	totalPAShrooms = 0;
	addShrooms = true;
	fleaSpawnProb = 0;

	memset(mushField, 0, sizeof(mushField[0][0]) * GameController::GridW * GameController::GridH);

	Mushroom* newMush;

	for(float i = startingTotal; i >= 0; i--)
	{
		xPos = rand() % GameController::GridW;
		yPos = rand() % (GameController::GridH - 1) + 1;
		
		if (mushField[xPos][yPos] == 0)
		{
			newMush = Mushroomfactory::CreateMushroom(sf::Vector2f((float)((xPos * GameController::ScreenMult) + GameController::HalfScreenMult), (float)((yPos * GameController::ScreenMult) + GameController::HalfScreenMult)), xPos, yPos, this);
			mushField[xPos][yPos] = newMush;
			totalShrooms++;
			if(yPos > PAVal)
			{
				totalPAShrooms++;
			}
		}
		else
		{
			i += 1;
		}
	}
}

void Grid::Destroy()
{
	Mushroom* deleteMe;
	for (int x = 0; x < GameController::GridW; x++)
	{
		for (int y = 0; y < GameController::GridH; y++)
		{
			if(this->mushField[x][y] != nullptr)
			{
				deleteMe = mushField[x][y];
				deleteMe->MarkForDestroy();
			}
		}
	}
	AlarmCancel(1);
	AlarmCancel(2);
}

void Grid::removeShroom(Mushroom* removeMe, int x, int y)
{
	if (y > PAVal)
	{
		totalPAShrooms--;
	}
	this->mushField[x][y] = nullptr;
	totalShrooms--;

}

void Grid::addShroomFlea(int col, int i, int prob)
{
	fleaSpawnProb = prob;
	if(i < GameController::GridH && addShrooms)
	{
		SetAlarm(1, .084f);
		xPos = col;
		yPos = i;
	}
}

void Grid::noMoreShrooms()
{
	this->addShrooms = false;
}

void Grid::startAddingShrooms()
{
	this->addShrooms = true;
}

bool Grid::isThereAShroom(sf::Vector2f P, CentipedeBase* cb)
{
	int colPos = (((int)P.x) - GameController::HalfScreenMult) / GameController::ScreenMult;
	int rowPos = (((int)P.y) - GameController::HalfScreenMult) / GameController::ScreenMult;

	Mushroom* mush;

	if(mushField[colPos][rowPos] == nullptr)
	{
		return false;
	}
	else
	{
		mush = mushField[colPos][rowPos];
		if(mush->isMushPoison())
		{
			cb->poisonTime();
		}
		return true;
	}
}

void Grid::addShroomHere(sf::Vector2f P)
{
	int colPos = ((int)P.x - GameController::HalfScreenMult) / GameController::ScreenMult;
	int rowPos = ((int)P.y - GameController::HalfScreenMult) / GameController::ScreenMult;

	Mushroom* newMush;

	if (mushField[colPos][rowPos] == 0)
	{
		newMush = Mushroomfactory::CreateMushroom(sf::Vector2f((float)((colPos * GameController::ScreenMult) + GameController::HalfScreenMult), (float)((rowPos * GameController::ScreenMult) + GameController::HalfScreenMult)), colPos, rowPos, this);
		mushField[colPos][rowPos] = newMush;
		totalShrooms++;
		if (rowPos > PAVal)
		{
			totalPAShrooms++;
		}

	}
}

bool Grid::playerAreaShrooms(int val)
{
	if(totalPAShrooms <= val)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Grid::regenShrooms()
{
	Mushroom* regenMe;

	for(int x = 0; x < GameController::GridW; x++)
	{
		for(int y = 0; y < GameController::GridH; y++)
		{
			regenMe = this->mushField[x][y];
			if( regenMe != nullptr && (regenMe->getHealth() < 4 || regenMe->isMushPoison()))
			{
				regenList.push_front(regenMe);
			}
		}
	}
	SetAlarm(2, 0.6f);

}

void Grid::scorpMovingThrough(sf::Vector2f p)
{
	int colPos = (((int)p.x) - GameController::HalfScreenMult) / GameController::ScreenMult;
	int rowPos = (((int)p.y) - GameController::HalfScreenMult) / GameController::ScreenMult;

	Mushroom* mush;

	if (mushField[colPos][rowPos] != nullptr)
	{
		mush = mushField[colPos][rowPos];
		if(!mush->isMushPoison())
		{
			mush->poisonMe();
		}
	}
}

void Grid::Alarm1()
{
	Mushroom* newMush;
	int random = rand() % fleaSpawnProb;


	if ( random == 1 && mushField[xPos][yPos] == 0)
	{
		newMush = Mushroomfactory::CreateMushroom(sf::Vector2f((float)((xPos * GameController::ScreenMult) + GameController::HalfScreenMult), (float)((yPos * GameController::ScreenMult) + GameController::HalfScreenMult)), xPos, yPos, this);

		mushField[xPos][yPos] = newMush;
		totalShrooms++;
		if (yPos > PAVal)
		{
			totalPAShrooms++;
		}
	}
	yPos++;
	this->addShroomFlea(xPos, yPos, fleaSpawnProb);

}

void Grid::Alarm2()
{
	Mushroom* regenMe;
	if (regenList.size() > 0)
	{
		regenMe = regenList.front();
		regenMe->regenShroom();
		regenList.pop_front();

		SetAlarm(2, 0.15f);
	}
	else
	{
		GameController::ContinueGame();
	}
}
