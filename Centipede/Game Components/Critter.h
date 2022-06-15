#ifndef _Critter
#define _Critter

#include "TEAL\CommonElements.h"

class Critter : public GameObject
{
public:

	Critter() = default;
	~Critter() = default;
	Critter(const Critter&) = delete;
	Critter& operator=(const Critter&) = default;

	virtual void Update() {};
	virtual void Draw() {};
	virtual void Destroy() {};

	virtual const void stopMoving();


protected:

	bool STOP;

};

#endif _Critter
