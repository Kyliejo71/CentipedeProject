#ifndef _MovementCollection
#define _MovementCollection

#include "TEAL\CommonElements.h"

struct OffsetArray
{
	int rowoffset;
	int coloffset;
	float rotation;

	OffsetArray(int r, int c, float ro) : rowoffset(r), coloffset(c), rotation(ro) {};

};

class MovementCollection
{
public:

	MovementCollection() = default;
	~MovementCollection() = default;
	MovementCollection(const MovementCollection&) = delete;
	MovementCollection& operator=(const MovementCollection&) = default;



	static const OffsetArray OffsetsStraightRight;
	static const OffsetArray OffsetsTurnUpEndRight;
	static const OffsetArray OffsetsTurnDownEndRight;
	static const OffsetArray OffsetsStraightLeft;
	static const OffsetArray OffsetsTurnUpEndLeft;
	static const OffsetArray OffsetsTurnDownEndLeft;
};

#endif _MovementCollection
