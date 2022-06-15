#ifndef _MushroomPool
#define _MushroomPool

#include <stack>
class Mushroom;

class MushroomPool
{
private:
	std::stack<Mushroom*> recycledItems;

public:
	MushroomPool();
	MushroomPool(const MushroomPool&) = delete;
	MushroomPool& operator=(const MushroomPool&) = delete;
	~MushroomPool();

	Mushroom* GetMushroom();

	void ReturnMushroom(Mushroom* b);
};


#endif _MushroomPool