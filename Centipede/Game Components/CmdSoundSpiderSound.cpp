#include "CmdSoundSpiderSound.h"
#include "SoundManager.h"

void CmdSoundSpiderSound::Execute()
{
	SoundManager::AddSoundSpiderLoop();
}
