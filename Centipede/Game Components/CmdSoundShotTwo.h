#ifndef _CmdSoundShotTwo
#define _CmdSoundShotTwo

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundShotTwo : public CmdSound
{
public:
	CmdSoundShotTwo() = default;
	~CmdSoundShotTwo() = default;
	CmdSoundShotTwo(const CmdSoundShotTwo&) = delete;
	CmdSoundShotTwo& operator=(const CmdSoundShotTwo&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundShotTwo
