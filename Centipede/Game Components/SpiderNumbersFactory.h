#ifndef _SpiderNumbersFactory
#define _SpiderNumbersFactory

#include "SpiderNumbersPool.h"
#include "SFML/Graphics.hpp"
#include "SpiderNumbers.h"

class GameObject;

class SpiderNumbersFactory
{
private:

	static SpiderNumbersFactory* ptrInstance;

	SpiderNumbersFactory() = default;
	SpiderNumbersFactory(const SpiderNumbersFactory&) = delete;
	SpiderNumbersFactory& operator=(const SpiderNumbersFactory&) = delete;
	~SpiderNumbersFactory() = default;

	static SpiderNumbersFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new SpiderNumbersFactory();
		return *ptrInstance;
	};

	SpiderNumbersPool mySpiderNumbersPool;  // Back to be a non-static member instance


	void privCreateSpiderNumbers(sf::Vector2f pos, int val);
	void privRecycleSpiderNumbers(GameObject* s);

public:

	static void CreateSpiderNumbers(sf::Vector2f pos, int val) { Instance().privCreateSpiderNumbers(pos, val); };
	static void RecycleSpiderNumbers(GameObject* s) { Instance().privRecycleSpiderNumbers(s); };

	static void Terminate();
};


#endif _SpiderNumbersFactory
