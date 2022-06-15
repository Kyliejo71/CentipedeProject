#ifndef _CmdScoreValue
#define _CmdScoreValue

#include "CmdScore.h"

class CmdScoreValue : public CmdScore
{
protected:
	int points;	// points to add

public:

	CmdScoreValue() = delete;
	CmdScoreValue(int val);
	~CmdScoreValue() = default;
	CmdScoreValue(const CmdScoreValue&) = delete;
	CmdScoreValue& operator=(const CmdScoreValue&) = delete;

	virtual void Execute() override;

};

#endif _CmdScoreValue
