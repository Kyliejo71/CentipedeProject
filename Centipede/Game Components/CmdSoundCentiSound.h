#ifndef _CmdSoundCentiSound
#define _CmdSoundCentiSound

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundCentiSound : public CmdSound
{
public:
	CmdSoundCentiSound() = default;
	~CmdSoundCentiSound() = default;
	CmdSoundCentiSound(const CmdSoundCentiSound&) = delete;
	CmdSoundCentiSound& operator=(const CmdSoundCentiSound&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundCentiSound
