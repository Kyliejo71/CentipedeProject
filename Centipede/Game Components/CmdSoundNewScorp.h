#ifndef _CmdSoundNewScorp
#define _CmdSoundNewScorp

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundNewScorp : public CmdSound
{
public:
	CmdSoundNewScorp() = default;
	~CmdSoundNewScorp() = default;
	CmdSoundNewScorp(const CmdSoundNewScorp&) = delete;
	CmdSoundNewScorp& operator=(const CmdSoundNewScorp&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundNewScorp
