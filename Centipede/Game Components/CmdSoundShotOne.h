#ifndef _CmdSoundShotOne
#define _CmdSoundShotOne

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundShotOne : public CmdSound
{
public:
	CmdSoundShotOne() = default;
	~CmdSoundShotOne() = default;
	CmdSoundShotOne(const CmdSoundShotOne&) = delete;
	CmdSoundShotOne& operator=(const CmdSoundShotOne&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundShotOne