#ifndef _SpiderNumbersPool
#define _SpiderNumbersPool

#include <stack>
class SpiderNumbers;

class SpiderNumbersPool
{
private:
	std::stack<SpiderNumbers*> recycledItems;

public:
	SpiderNumbersPool() = default;
	SpiderNumbersPool(const SpiderNumbersPool&) = delete;
	SpiderNumbersPool& operator=(const SpiderNumbersPool&) = delete;
	~SpiderNumbersPool();

	SpiderNumbers* GetSpiderNumbers();

	void ReturnSpiderNumbers(SpiderNumbers* s);
};


#endif _SpiderNumbersPool

