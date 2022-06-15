#include "CmdSoundExtraLife.h"
#include "SoundManager.h"

void CmdSoundExtraLife::Execute()
{
	SoundManager::AddSoundExtraLife();
}
