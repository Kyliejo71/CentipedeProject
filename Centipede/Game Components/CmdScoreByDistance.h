#ifndef _CmdScoreByDistance
#define _CmdScoreByDistance

#include "CmdScore.h"

class CmdScoreByDistance : public CmdScore 
{
private:
	int dNear;
	int dMed;
	int dFar;
	int vNear;
	int vMed;
	int vFar;
	int finalVal;

	sf::Vector2f shipPos;
	sf::Vector2f spiderPos;

	int distanceCalc(int x1, int y1, int x2, int y2);

public:
	CmdScoreByDistance() = default;
	CmdScoreByDistance(const CmdScoreByDistance&) = delete;
	CmdScoreByDistance& operator=(const CmdScoreByDistance&) = delete;
	~CmdScoreByDistance() = default;

	CmdScoreByDistance(int dNear, int dMed, int dFar,
		int vNear, int vMed, int vFar);

	virtual void Execute() override;
	virtual void Alarm0();


};

#endif _CmdScoreByDistance