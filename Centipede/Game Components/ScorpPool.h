#ifndef _ScorpPool
#define _ScorpPool

#include <stack>
class Scorp;

class ScorpPool
{
private:
	std::stack<Scorp*> recycledItems;

public:
	ScorpPool();
	ScorpPool(const ScorpPool&) = delete;
	ScorpPool& operator=(const ScorpPool&) = delete;
	~ScorpPool();

	Scorp* GetScorp();

	void ReturnScorp(Scorp* b);
};


#endif _ScorpPool