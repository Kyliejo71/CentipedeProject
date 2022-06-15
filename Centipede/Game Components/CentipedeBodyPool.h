#ifndef _CentipedeBodyPool
#define _CentipedeBodyPool

#include <stack>
class CentipedeBody;

class CentipedeBodyPool
{
private:
	std::stack<CentipedeBody*> recycledItems;

public:
	CentipedeBodyPool();
	CentipedeBodyPool(const CentipedeBodyPool&) = delete;
	CentipedeBodyPool& operator=(const CentipedeBodyPool&) = delete;
	~CentipedeBodyPool();

	CentipedeBody* GetBody();

	void ReturnBody(CentipedeBody* b);
};


#endif _CentipedeBodyPool
