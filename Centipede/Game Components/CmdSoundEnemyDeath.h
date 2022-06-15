#ifndef _CmdSoundEnemyDeath
#define _CmdSoundEnemyDeath

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundEnemyDeath : public CmdSound
{
public:
	CmdSoundEnemyDeath() = default;
	~CmdSoundEnemyDeath() = default;
	CmdSoundEnemyDeath(const CmdSoundEnemyDeath&) = delete;
	CmdSoundEnemyDeath& operator=(const CmdSoundEnemyDeath&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundEnemyDeath
