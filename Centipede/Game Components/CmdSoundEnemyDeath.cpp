#include "CmdSoundEnemyDeath.h"
#include "SoundManager.h"

void CmdSoundEnemyDeath::Execute()
{
	SoundManager::AddSoundEnemyDeath();
}
