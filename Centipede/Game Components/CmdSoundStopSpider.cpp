#include "CmdSoundStopSpider.h"
#include "SoundManager.h"

void CmdSoundStopSpider::Execute()
{
	SoundManager::StopSoundSpriderLoop();
}
