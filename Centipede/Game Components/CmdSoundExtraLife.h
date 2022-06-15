#ifndef _CmdSoundExtraLife
#define _CmdSoundExtraLife

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundExtraLife : public CmdSound
{
public:
	CmdSoundExtraLife() = default;
	~CmdSoundExtraLife() = default;
	CmdSoundExtraLife(const CmdSoundExtraLife&) = delete;
	CmdSoundExtraLife& operator=(const CmdSoundExtraLife&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundExtraLife

