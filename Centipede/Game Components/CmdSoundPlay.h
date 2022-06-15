#ifndef _CmdSoundPlay
#define _CmdSoundPlay

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundPlay : public CmdSound
{
public:
	CmdSoundPlay() = default;
	~CmdSoundPlay() = default;
	CmdSoundPlay(const CmdSoundPlay&) = delete;
	CmdSoundPlay& operator=(const CmdSoundPlay&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundPlay