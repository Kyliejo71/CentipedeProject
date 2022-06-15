#ifndef _CmdSound
#define _CmdSound

#include "TEAL/CommonElements.h"

class CmdSound : GameObject
{
public:
	CmdSound() = default;
	CmdSound(const CmdSound&) = delete;
	virtual CmdSound& operator=(const CmdSound&) = delete;
	virtual ~CmdSound() = default;

	// Note: the Excecute method must NOT have _any_ paramters
	virtual void Execute() = 0;
	virtual void Destroy();

};

#endif _CmdSound
