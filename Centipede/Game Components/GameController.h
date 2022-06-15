#ifndef _GameController
#define _GameController

#include "TEAL\CommonElements.h"

class Grid;
class Player;
class Ship;
class ShipStrategy;
class ShipStrategyAttractor;
class ShipStrategyKeyboard;
class SoundStrategySound;
class SoundStrategyMute;

class GameController : GameObject
{
private:
	static GameController* ptrInstance;	

	GameController();									 
	GameController(const GameController&) = delete;				
	GameController& operator=(const GameController&) = delete;
	~GameController() = default;

	static GameController& Instance()					
	{
		if (! ptrInstance) 
			ptrInstance = new GameController;
		return *ptrInstance;
	};


	Player* currPlayer;
	Grid* currGrid;
	Ship* playerShip;
	sf::Vector2f spiderDeathPos;
	ShipStrategy* currStrat;
	ShipStrategyAttractor* pAttractorStrat;
	ShipStrategyKeyboard* pKeyboardStrat;
	SoundStrategySound* pYesSound;
	SoundStrategyMute* pNoSound;

	bool gameEnded;

	void privAttractorStart();
	void privGameStart();
	void privGameOver();
	void privLifeLost();
	void privNextRound();
	void privnextRoundAfterDeath();
	sf::Vector2f privGetCurrShipPos();
	void privSetSpiderDeathPos(sf::Vector2f Pos);
	sf::Vector2f privGetSpiderDeathPos();
	void privContinueGame();
	void privAttractorEnds();

public:


	static const int PlayerAreaTop = 768;		  // 
	static const int PlayerAreaBottom = 992;	  // 
	static const int ScreenMult = 32;			  // 
	static const int BottomOfShrooms = 992;		  // 
	static const int GridW = 30;				  // 
	static const int GridH = 31;				  //   Values used across the game
	static const int HalfScreenMult = 16;		  // 
	static const int BottomOfScreen = 1024;		  // 
	static const int LeftOfScreen = 0;			  // 
	static const int RightOfScreen = 960;		  // 
	static const int TopOfScreen = 0;			  // 

	static void attractorStart() { Instance().privAttractorStart(); };
	static void gameStart() { Instance().privGameStart(); };
	static void gameOver() { Instance().privGameOver(); };
	static void lifeLost() { Instance().privLifeLost(); };
	static void nextRound() { Instance().privNextRound(); };
	static void nextRoundAfterDeath() { Instance().privnextRoundAfterDeath(); };
	static sf::Vector2f getCurrShipPos() { return Instance().privGetCurrShipPos(); };
	static void setSpiderDeathPos(sf::Vector2f Pos) { Instance().privSetSpiderDeathPos(Pos); };
	static sf::Vector2f getSpiderDeathPos() { return Instance().privGetSpiderDeathPos(); };
	static void ContinueGame() { Instance().privContinueGame(); };
	static void attractorEnds() { Instance().privAttractorEnds(); };
	static void Terminate();
};

#endif _GameController