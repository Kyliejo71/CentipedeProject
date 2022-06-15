#ifndef _SoundStrategyMute
#define _SoundStrategyMute

#include "TEAL/CommonElements.h"
#include "SoundManager.h"
#include "SoundStrategy.h"

class SoundStrategyMute : public SoundStrategy
{
public:
	SoundStrategyMute() = default;
	SoundStrategyMute(const SoundStrategyMute&) = delete;

	virtual void getCmdForSM(CmdSound* c) override;

};

#endif _SoundStrategyMute

