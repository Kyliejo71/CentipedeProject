#ifndef _CmdSoundStopCenti
#define _CmdSoundStopCenti

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundStopCenti : public CmdSound
{
public:
	CmdSoundStopCenti() = default;
	~CmdSoundStopCenti() = default;
	CmdSoundStopCenti(const CmdSoundStopCenti&) = delete;
	CmdSoundStopCenti& operator=(const CmdSoundStopCenti&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundStopCenti