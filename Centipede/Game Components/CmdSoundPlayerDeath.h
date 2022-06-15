#ifndef _CmdSoundPlayerDeath
#define _CmdSoundPlayerDeath

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundPlayerDeath : public CmdSound
{
public:
	CmdSoundPlayerDeath() = default;
	~CmdSoundPlayerDeath() = default;
	CmdSoundPlayerDeath(const CmdSoundPlayerDeath&) = delete;
	CmdSoundPlayerDeath& operator=(const CmdSoundPlayerDeath&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundPlayerDeath