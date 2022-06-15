#ifndef _CmdScore
#define _CmdScore

#include "TEAL/CommonElements.h"

class CmdScore : public GameObject
{
public:
	// Note: the Excecute method must NOT have _any_ paramters

	CmdScore() = default;
	CmdScore(const CmdScore&) = delete;
	CmdScore& operator=(const CmdScore&) = delete;
	~CmdScore() = default;

	virtual void Execute() = 0;
	virtual void Destroy();
	
};

#endif _CmdScore