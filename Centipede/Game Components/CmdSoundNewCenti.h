#ifndef _CmdSoundNewCenti
#define _CmdSoundNewCenti

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundNewCenti : public CmdSound
{
public:
	CmdSoundNewCenti() = default;
	~CmdSoundNewCenti() = default;
	CmdSoundNewCenti(const CmdSoundNewCenti&) = delete;
	CmdSoundNewCenti& operator=(const CmdSoundNewCenti&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundNewCenti