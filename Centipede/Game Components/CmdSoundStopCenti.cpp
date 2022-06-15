#include "CmdSoundStopCenti.h"
#include "SoundManager.h"

void CmdSoundStopCenti::Execute()
{
	SoundManager::StopSoundCentiLoop();
}
