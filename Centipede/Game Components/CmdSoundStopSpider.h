#ifndef _CmdSoundStopSpider
#define _CmdSoundStopSpider

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundStopSpider : public CmdSound
{
public:
	CmdSoundStopSpider() = default;
	~CmdSoundStopSpider() = default;
	CmdSoundStopSpider(const CmdSoundStopSpider&) = delete;
	CmdSoundStopSpider& operator=(const CmdSoundStopSpider&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundStopSpider