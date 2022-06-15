#ifndef _SoundStrategy
#define _SoundStrategy

#include "TEAL/CommonElements.h"
#include "SoundManager.h"

class CmdSound;

class SoundStrategy : public GameObject
{
public:
	SoundStrategy() = default;
	SoundStrategy(const SoundStrategy&) = delete;
	virtual SoundStrategy& operator=(const SoundStrategy&) = default;
	virtual ~SoundStrategy() = default;

	virtual void getCmdForSM(CmdSound* c) = 0;

};

#endif _SoundStrategy