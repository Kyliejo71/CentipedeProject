#ifndef _HUD
#define _HUD

#include "TEAL\CommonElements.h"
#include "Font.h"
#include <string>
#include <vector>

class Glyph;
class BlankShip;
class CmdSound;

class HUD : public GameObject
{
public:
	virtual void Update();

	static void AttractorStarts() { Instance().privAttractorStarts(); };
	static void ScoreUpdate(int score) { Instance().privScoreUpdate(score); };
	static void AttractorEnds() { Instance().privAttractorEnds(); };
	static void LifeLost() { Instance().privLifeLost(); };
	static void ExtraLife() { Instance().privExtraLife(); };
	static std::string EnterName() { return Instance().privEnterName(); };
	static void Terminate();

private:
	static HUD* ptrInstance;

	HUD();
	HUD(const HUD&) = delete;
	HUD& operator=(const HUD&) = delete;
	~HUD() = default;

	static HUD& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new HUD;
		return *ptrInstance;
	};


	Font myFont;

	std::string p1Score;
	std::string p2Score;
	std::string highestScore;
	std::string bottomLable;
	std::string HSlable;
	std::string credits;
	std::string bonusLable;
	std::string HS1;			
	std::string HS2;			
	std::string HS3;			
	std::string HS4;			
	std::string HS5;			
	std::string HS6;			
	std::string HS7;			
	std::string HS8;
	std::string gameOver;
	std::string greatScore;
	std::string enterYourInitials;

	std::vector<Glyph*> symbols;
	std::vector<Glyph*> highScore;
	std::vector<Glyph*> playerScore;
	std::vector<Glyph*> gameOverVec;

	sf::Vector2f nextpos;

	Glyph* initial1;
	Glyph* initial2;
	Glyph* initial3;

	bool ATTRACTOR;

	BlankShip* life1;
	BlankShip* life2;
	BlankShip* extraLife;

	CmdSound* pExtraLife;

	void privAttractorStarts();
	void privAttractorEnds();
	void privScoreUpdate(int score);
	void privLifeLost();
	void privExtraLife();
	std::string privEnterName();

};

#endif _HUD