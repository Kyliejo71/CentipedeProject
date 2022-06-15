#include "CmdSoundCentiSound.h"
#include "SoundManager.h"

void CmdSoundCentiSound::Execute()
{
	SoundManager::AddSoundCentiLoop();
}
