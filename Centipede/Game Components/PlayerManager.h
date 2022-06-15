#ifndef _PlayerManager
#define _PlayerManager

#include "TEAL\CommonElements.h"

class Player;
class Grid;

class PlayerManager
{
private:
	static PlayerManager* ptrInstance;

	PlayerManager();
	~PlayerManager() = default;
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator=(const PlayerManager&) = delete;

	static PlayerManager& Instance()	     
	{
		if (!ptrInstance)
			ptrInstance = new PlayerManager;
		return *ptrInstance;
	};

	Player* P1;
	Player* Attractor;
	Player* currPlayer;
	Grid* currGrid;

	Player* privReturnCurrAttractor();
	Player* privReturnCurrPlayer();
	void privRemoveLife();
	void privPlayerOneStart();

public:
	static Player* returnCurrAttractor() { return Instance().privReturnCurrAttractor(); };
	static void removeLife() { Instance().privRemoveLife(); };
	static void playerOneStart() { Instance().privPlayerOneStart(); };
	static Player* returnCurrPlayer() { return Instance().privReturnCurrPlayer(); };

	static void Terminate();
};

#endif _PlayerManager

