#include "SoundStrategySound.h"
#include "SoundManager.h"
#include "CmdSound.h"

void SoundStrategySound::getCmdForSM(CmdSound* c)
{
	SoundManager::SendSoundCommandAfterStrategy(c);
}
