// Level1
// Andre Berthiaume, March 2013

#ifndef _Level1
#define _Level1

#include "TEAL\CommonElements.h"

class Level1 : public Scene
{
public:

	Level1() = default;
	Level1(const Level1&) = delete;
	Level1& operator=(const Level1&) = delete;
	~Level1() = default;

	virtual void Initialize();
	virtual void Terminate();
};

#endif _Level1