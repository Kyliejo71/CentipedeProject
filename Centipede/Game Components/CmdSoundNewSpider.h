#ifndef _CmdSoundNewSpider
#define _CmdSoundNewSpider

#include "CmdSound.h"
#include "TEAL/CommonElements.h"

class CmdSoundNewSpider : public CmdSound
{
public:
	CmdSoundNewSpider() = default;
	~CmdSoundNewSpider() = default;
	CmdSoundNewSpider(const CmdSoundNewSpider&) = delete;
	CmdSoundNewSpider& operator=(const CmdSoundNewSpider&) = default;

	virtual void Execute() override;

};

#endif _CmdSoundNewSpider
