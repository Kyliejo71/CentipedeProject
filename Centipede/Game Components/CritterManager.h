#ifndef _CritterManager
#define _CritterManager

#include "TEAL\CommonElements.h"
#include <list>
using namespace std;

class Critter;
class CmdSound;

class CritterManager
{
public:
	static CritterManager* ptrInstance;

	CritterManager();
	CritterManager(const CritterManager&) = delete;
	CritterManager& operator=(const CritterManager&) = delete;
	~CritterManager() = default;

	static CritterManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CritterManager;
		return *ptrInstance;
	};

	static void AddCritter(Critter* addMe) { Instance().privAddCritter(addMe); };
	static void RemoveCritter(Critter* removeMe) { Instance().privRemoveCritter(removeMe); };
	static void EndOfRound() { Instance().privEndOfRound(); };
	static void addcenties() { Instance().privAddCenties(); };
	static void removeCenties() { Instance().privRemoveCenties(); };
	static void addSpiders() { Instance().privAddSpiders(); };
	static void removeSpiders() { Instance().privRemoveSpiders(); };
	static void stopMoving() { Instance().privStopMoving(); };

	static void Terminate();
private:

	void privAddCritter(Critter* addMe);
	void privRemoveCritter(Critter* removeMe);
	void privEndOfRound();
	void privAddCenties();
	void privRemoveCenties();
	void privAddSpiders();
	void privRemoveSpiders();
	void privStopMoving();

	std::list<Critter*> onScreenCritters;
	int totalSpiders;
	int totalCenti;
	CmdSound* pStopSpider;
	CmdSound* pStopCenti;
	
};

#endif _CritterManager
