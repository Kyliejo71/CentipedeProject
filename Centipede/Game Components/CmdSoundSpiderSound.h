#ifndef _CmdSoundSpiderSound
#define _CmdSoundSpiderSound

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundSpiderSound : public CmdSound
{
public:
	CmdSoundSpiderSound() = default;
	~CmdSoundSpiderSound() = default;
	CmdSoundSpiderSound(const CmdSoundSpiderSound&) = delete;
	CmdSoundSpiderSound& operator=(const CmdSoundSpiderSound&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundSpiderSound
