#ifndef _HighScoreManager
#define _HighScoreManager

#include <string>

class HighScoreManager
{
private:

	static HighScoreManager* ptrInstance;

	HighScoreManager();
	HighScoreManager(const HighScoreManager&) = delete;
	HighScoreManager& operator=(const HighScoreManager&) = delete;
	~HighScoreManager() = default;

	static HighScoreManager& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new HighScoreManager;
		return *ptrInstance;
	};

	std::string privReturnHighestScore();
	std::string privReturnHS1();
	std::string privReturnHS2();
	std::string privReturnHS3();
	std::string privReturnHS4();
	std::string privReturnHS5();
	std::string privReturnHS6();
	std::string privReturnHS7();
	std::string privReturnHS8();

	void privCheckForNewHS(int finalScore);

	int highestScore;
	int HS2;
	int HS3;
	int HS4;
	int HS5;
	int HS6;
	int HS7;
	int HS8;

	std::string highestScoreLabel;
	std::string HS2Label;
	std::string HS3Label;
	std::string HS4Label;
	std::string HS5Label;
	std::string HS6Label;
	std::string HS7Label;
	std::string HS8Label;

public:
	static std::string returnHighestScore() { return Instance().privReturnHighestScore(); };
	static std::string returnHS1() { return Instance().privReturnHS1(); };
	static std::string returnHS2() { return Instance().privReturnHS2(); };
	static std::string returnHS3() { return Instance().privReturnHS3(); };
	static std::string returnHS4() { return Instance().privReturnHS4(); };
	static std::string returnHS5() { return Instance().privReturnHS5(); };
	static std::string returnHS6() { return Instance().privReturnHS6(); };
	static std::string returnHS7() { return Instance().privReturnHS7(); };
	static std::string returnHS8() { return Instance().privReturnHS8(); };
	static void checkForNewHS(int finalScore) { return Instance().privCheckForNewHS(finalScore); };

	static void Terminate();
};

#endif _HighScoreManager
