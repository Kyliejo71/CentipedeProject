#include "CmdSoundPlayerDeath.h"
#include "SoundManager.h"

void CmdSoundPlayerDeath::Execute()
{
	SoundManager::AddSoundPlayerDeath();
}
