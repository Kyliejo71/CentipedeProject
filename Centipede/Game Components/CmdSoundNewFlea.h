#ifndef _CmdSoundNewFlea
#define _CmdSoundNewFlea

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundNewFlea : public CmdSound
{
public:
	CmdSoundNewFlea() = default;
	~CmdSoundNewFlea() = default;
	CmdSoundNewFlea(const CmdSoundNewFlea&) = delete;
	CmdSoundNewFlea& operator=(const CmdSoundNewFlea&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundNewFlea