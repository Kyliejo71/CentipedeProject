#ifndef _SoundStrategySound
#define _SoundStrategySound

#include "TEAL/CommonElements.h"
#include "SoundManager.h"
#include "SoundStrategy.h"

class SoundStrategySound : public SoundStrategy
{
public:
	SoundStrategySound() = default;
	SoundStrategySound(const SoundStrategySound&) = delete;

	virtual void getCmdForSM(CmdSound* c) override;

};

#endif _SoundStrategySound
