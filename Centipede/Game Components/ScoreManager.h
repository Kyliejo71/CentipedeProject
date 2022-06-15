#ifndef _ScoreManager
#define _ScoreManager

#include <queue>
#include "TEAL/CommonElements.h"

class CmdScore;

class ScoreManager : GameObject
{
private:
	// Score values;
	static const int FleaDeath = 200;
	static const int ScorpionDeath = 1000;
	static const int MushroomDeath = 1;
	static const int MushroomPoisonDeath = 1;
	static const int CentiHeadDeath = 100;
	static const int CentiBodyDeath = 10;

	static const int SpiderDeathFar = 300;			
	static const int SpiderDistFar = 400;			
													
	static const int SpiderDeathMedium = 600;		
	static const int SpiderDistMedium = 150;		
													
	static const int SpiderDeathNear = 900;			
	static const int SpiderDistNear = 65;		

	static const int HighScoreMult = 12000;

	std::queue<CmdScore*> QueueCmds;

	static ScoreManager* ptrInstance;

	ScoreManager();
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
	~ScoreManager() = default;

	static ScoreManager& Instance()	    
	{
		if (!ptrInstance)
			ptrInstance = new ScoreManager;
		return *ptrInstance;
	};

	int lastFinalScore;

	void privProcessScore();
	void privSetLastFinalScore(int val);
	std::string privGetLastFinalScore();

public:
	// events
	virtual void Update();

	enum class ScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, MushroomPoisonKilled, SpiderKilled, CentiHeadKilled, CentiBodyKilled };

	static void AddScore(int val);

	static CmdScore* GetScoreCommand(ScoreEvents ev);

	static void SendScoreCmd(CmdScore* c);
	static void ProcessScores();
	static void Terminate();
	static void setLastFinalScore(int val) { Instance().privSetLastFinalScore(val); };
	static std::string getLastFinalScore() { return Instance().privGetLastFinalScore(); };
};

#endif _ScoreManager
