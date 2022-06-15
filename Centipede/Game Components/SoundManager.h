#ifndef _SoundManager
#define _SoundManager

#include <queue>
#include "TEAL\CommonElements.h"

class CmdSound;
class SoundStrategy;

class SoundManager : GameObject
{
public:
	// events

	virtual void Update();

	enum class SoundEvents {
		CentipedeSound, MushBonus, PlayerDeath,
		ExtraLife, Shot1, Shot2, NewFlea, EnemyDeath,
		NewCenti, NewScorp, NewSpider, SpiderSound, StopCentiLoop, StopSpiderLoop
	};

	static void AddSoundCentiLoop() { Instance().privAddSoundCentiLoop(); };
	static void AddSoundMushBonus() { Instance().privAddSoundMushBonus(); };
	static void AddSoundPlayerDeath() { Instance().privAddSoundPlayerDeath(); };
	static void AddSoundExtraLife() { Instance().privAddSoundExtraLife(); };
	static void AddSoundShotOne() { Instance().privAddSoundShotOne(); };
	static void AddSoundShotTwo() { Instance().privAddSoundShotTwo(); };
	static void AddSoundNewFlea() { Instance().privAddSoundNewFlea(); };
	static void AddSoundEnemyDeath() { Instance().privAddSoundEnemyDeath(); };
	static void AddSoundNewCenti() { Instance().privAddSoundNewCenti(); };
	static void AddSoundNewScorp() { Instance().privAddSoundNewScorp(); };
	static void AddSoundNewSpider() { Instance().privAddSoundNewSpider(); };
	static void AddSoundSpiderLoop() { Instance().privAddSoundSpiderLoop(); };
	static void StopSoundCentiLoop() { Instance().privStopSoundCentiLoop(); };
	static void StopSoundSpriderLoop() { Instance().privStopSoundSpiderLoop(); };
	static void SendSoundCmd(CmdSound* c) { Instance().privSendSoundCommand(c); };
	static void SetStrategy(SoundStrategy* newStrat) { Instance().privSetStrategy(newStrat); };
	static CmdSound* GetSoundCommand(SoundEvents ev);
	static void SendSoundCommandAfterStrategy(CmdSound* c);

	static void ProcessSound();
	static void Terminate();

private:

	sf::Sound centiSound;
	sf::Sound mushBonus;
	sf::Sound playerDeath;
	sf::Sound extraLife;
	sf::Sound shotOne;
	sf::Sound shotTwo;
	sf::Sound newFlea;
	sf::Sound enemyDeath;
	sf::Sound newCenti;
	sf::Sound newScorp;
	sf::Sound newSpider;
	sf::Sound spiderSound;

	bool isSpiderOn;
	bool isCentiOn;

	std::queue<CmdSound*> QueueCmds;

	SoundStrategy* myStrategy;

	static SoundManager* ptrInstance;

	SoundManager();
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;
	~SoundManager() = default;

	static SoundManager& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new SoundManager;
		return *ptrInstance;
	};

	void privProcessSound();

	void privAddSoundCentiLoop();
	void privAddSoundMushBonus();
	void privAddSoundPlayerDeath();
	void privAddSoundExtraLife();
	void privAddSoundShotOne();
	void privAddSoundShotTwo();
	void privAddSoundNewFlea();
	void privAddSoundEnemyDeath();
	void privAddSoundNewCenti();
	void privAddSoundNewScorp();
	void privAddSoundNewSpider();
	void privAddSoundSpiderLoop();
	void privStopSoundCentiLoop();
	void privStopSoundSpiderLoop();
	void privSendSoundCommand(CmdSound* c);
	void privSetStrategy(SoundStrategy* newStrat);
};

#endif _SoundManager
