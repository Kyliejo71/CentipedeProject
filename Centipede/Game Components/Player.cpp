#include "Player.h"
#include "Grid.h"
#include "GameController.h"

Player::Player(int totalLives)
{
	Score = 0;
	Lives = totalLives;
	waveNumber = 1;

	totalExtraLives = 1; //Starts as one since * 0 would auto give an extra life

	myGrid = new Grid();
}

void Player::Destroy()
{
	this->myGrid->MarkForDestroy();
}

Grid* Player::getGrid()
{
	return this->myGrid;
}

void Player::addToScore(int points)
{
	this->Score += points;
}

void Player::lostLife()
{
	this->Lives--;
}

int Player::getLives()
{
	return this->Lives;
}

int Player::getScore()
{
	return this->Score;
}

void Player::addExtraLife()
{
	this->Lives += 1;
	this->totalExtraLives += 1;
}

int Player::getTotalExtraLives()
{
	return this->totalExtraLives;
}
