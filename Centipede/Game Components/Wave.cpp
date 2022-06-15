#include "Wave.h"

Wave::Wave(int waveNum)
	:waveNumber(waveNum)
{
	centLength = 0;
	centiSpeed = 0;

	soloHeadSwitch = false;
	soloHeadCount = 0;
	soloHeadSpeed = 0;
	soloHeadPASwitch = false;
	soloHeadPASpeed = 0;
	soloHeadPACount = 0;

	fleaSwitch = false;
	fleaMushTriggerValue = 0;
	fleaMushSpawnProbability = 0;

	scorpSwitch = false;
	scorpSpeed = 0;
	scorpSpawnRate = 0;

	spiderSwitch = false;
	spiderSpeed = 0;
	spiderSpawnRate = 0;
}

void Wave::setFleaSwitch(bool Switch)
{
	this->fleaSwitch = Switch;
}

void Wave::setFleaMushTriggerValue(int value)
{
	this->fleaMushTriggerValue = value;
}

void Wave::setFleaMushSpawnProbability(int probability)
{
	this->fleaMushSpawnProbability = probability;
}

void Wave::setScorpSwitch(bool Switch)
{
	this->scorpSwitch = Switch;
}

void Wave::setScorpSpeed(int speed)
{
	this->scorpSpeed = speed;
}

void Wave::setScorpSpawnRate(int rate)
{
	this->scorpSpawnRate = rate;
}

void Wave::setSpiderSwitch(bool Switch)
{
	this->spiderSwitch = Switch;
}

void Wave::setSpiderSpeed(int speed)
{
	this->spiderSpeed = speed;
}

void Wave::setSpiderSpawnRate(int rate)
{
	this->spiderSpawnRate = rate;
}

int Wave::getCentLength()
{
	return this->centLength;
}

int Wave::getCentiSpeed()
{
	return this->centiSpeed;
}

bool Wave::getSoloHeadSwitch()
{
	return this->soloHeadSwitch;
}

int Wave::getSoloHeadCount()
{
	return this->soloHeadCount;
}

int Wave::getSoloHeadSpeed()
{
	return this->soloHeadSpeed;
}

bool Wave::getSoloHeadPASwitch()
{
	return this->soloHeadPASwitch;
}

int Wave::getSoloHeadPASpeed()
{
	return this->soloHeadPASpeed;
}

int Wave::getSoloHeadPACount()
{
	return this->soloHeadPACount;
}

bool Wave::getFleaSwitch()
{
	return this->fleaSwitch;
}

int Wave::getFleaMushTriggerValue()
{
	return this->fleaMushTriggerValue;
}

int Wave::getFleaMushSpawnProbability()
{
	return this->fleaMushSpawnProbability;
}

bool Wave::getScorpSwitch()
{
	return this->scorpSwitch;
}

int Wave::getScorpSpeed()
{
	return this->scorpSpeed;
}

int Wave::getScorpSpawnRate()
{
	return this->scorpSpawnRate;
}

bool Wave::getSpiderSwitch()
{
	return this->spiderSwitch;
}

int Wave::getSpiderSpeed()
{
	return this->spiderSpeed;
}

int Wave::getSpiderSpawnRate()
{
	return this->spiderSpawnRate;
}

void Wave::setCentiLength(int length)
{
	this->centLength = length;
}

void Wave::setCentiSpeed(int speed)
{
	this->centiSpeed = speed;
}

void Wave::setHeadSwitch(bool Switch)
{
	this->soloHeadSwitch = Switch;
}

void Wave::setHeadCount(int count)
{
	this->soloHeadCount = count;
}

void Wave::setHeadSpeed(int speed)
{
	this->soloHeadSpeed = speed;
}

void Wave::setHeadPASwitch(bool Switch)
{
	this->soloHeadPASwitch = Switch;
}

void Wave::setHeadPASpeed(int speed)
{
	this->soloHeadPASpeed = speed;
}

void Wave::setHeadPACount(int count)
{
	this->soloHeadPACount = count;
}
