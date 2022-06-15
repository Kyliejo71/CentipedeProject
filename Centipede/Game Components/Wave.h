#ifndef _Wave
#define _Wave

#include "TEAL/CommonElements.h"

class Wave : GameObject
{
public:
	Wave() = delete;
	Wave(int waveNum);
	~Wave() = default;
	Wave(const Wave&) = delete;
	Wave& operator=(const Wave&) = default;

	void setCentiLength(int length);
	void setCentiSpeed(int speed);
	void setHeadSwitch(bool Switch);
	void setHeadCount(int count);
	void setHeadSpeed(int speed);
	void setHeadPASwitch(bool Switch);
	void setHeadPASpeed(int speed);
	void setHeadPACount(int count);
	void setFleaSwitch(bool Switch);
	void setFleaMushTriggerValue(int value);
	void setFleaMushSpawnProbability(int probability);
	void setScorpSwitch(bool Switch);
	void setScorpSpeed(int speed);
	void setScorpSpawnRate(int rate);
	void setSpiderSwitch(bool Switch);
	void setSpiderSpeed(int speed);
	void setSpiderSpawnRate(int rate);

	int  getCentLength();
	int  getCentiSpeed();
	bool getSoloHeadSwitch();
	int  getSoloHeadCount();
	int  getSoloHeadSpeed();
	bool getSoloHeadPASwitch();
	int  getSoloHeadPASpeed();
	int  getSoloHeadPACount();
	bool getFleaSwitch();
	int  getFleaMushTriggerValue();
	int  getFleaMushSpawnProbability();
	bool getScorpSwitch();
	int  getScorpSpeed();
	int  getScorpSpawnRate();
	bool getSpiderSwitch();
	int  getSpiderSpeed();
	int  getSpiderSpawnRate();

private:

	int waveNumber;

	int centLength;
	int centiSpeed;

	bool soloHeadSwitch;
	int soloHeadCount;
	int soloHeadSpeed;
	bool soloHeadPASwitch;
	int soloHeadPASpeed;
	int soloHeadPACount;

	bool fleaSwitch;
	int fleaMushTriggerValue;
	int fleaMushSpawnProbability;

	bool scorpSwitch;
	int scorpSpeed;
	int scorpSpawnRate;

	bool spiderSwitch;
	int spiderSpeed;
	int spiderSpawnRate;
};

#endif _Wave