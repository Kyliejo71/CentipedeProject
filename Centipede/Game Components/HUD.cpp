#include "HUD.h"
#include "GameController.h"
#include "Glyph.h"
#include "HighScoreManager.h"
#include "BlankShip.h"
#include "SoundManager.h"
#include "ScoreManager.h"
#include "PlayerManager.h"
#include "Player.h"
#include "Grid.h"

HUD* HUD::ptrInstance = NULL;

HUD::HUD()
{
	p2Score = "00";
	bottomLable = "[1980 ATARI";
	HSlable = "HIGH SCORES";
	credits = "CREDITS 2";
	bonusLable = "BONUS EVERY 12000";
	gameOver = "GAME OVER";
	greatScore = "GREAT SCORE";
	enterYourInitials = "ENTER YOUR INITIALS";

	ATTRACTOR = true;
	life1 = nullptr;
	life2 = nullptr;
	extraLife = nullptr;
	pExtraLife = SoundManager::GetSoundCommand(SoundManager::SoundEvents::ExtraLife);
}

void HUD::privAttractorStarts()
{
	Grid* currGrid = PlayerManager::returnCurrPlayer()->getGrid();

	p1Score = ScoreManager::getLastFinalScore();
	highestScore = HighScoreManager::returnHighestScore();
	HS1 = HighScoreManager::returnHS1();
	HS2 = HighScoreManager::returnHS2();
	HS3 = HighScoreManager::returnHS3();
	HS4 = HighScoreManager::returnHS4();
	HS5 = HighScoreManager::returnHS5();
	HS6 = HighScoreManager::returnHS6();
	HS7 = HighScoreManager::returnHS7();
	HS8 = HighScoreManager::returnHS8();

	ATTRACTOR = true;

	nextpos = sf::Vector2f(GameController::ScreenMult * 5, 0);

	for(size_t i = p1Score.length(); i > 0; i--) //p1Score
	{
		playerScore.push_back(myFont.GetGlyph(p1Score.at(i-1), nextpos));
	
		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::RightOfScreen - (GameController::ScreenMult * 2), 0);
	
	for (size_t i = 0; i < p2Score.length(); i++) //p2Score
	{
		symbols.push_back(myFont.GetGlyph(p2Score.at(i), nextpos));
	
		nextpos.x += myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 17, 0);

	for (size_t i = highestScore.length(); i > 0; i--) //highest score
	{
		highScore.push_back(myFont.GetGlyph(highestScore.at(i-1), nextpos));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 10, GameController::BottomOfScreen - GameController::ScreenMult);
	
	for (size_t i = 0; i < bottomLable.length(); i++) //bottom lable
	{
		symbols.push_back(myFont.GetGlyph(bottomLable.at(i), nextpos));
	
		nextpos.x += myFont.CellWidth() * 4;
	}
	
	nextpos = sf::Vector2f(GameController::ScreenMult * 10, GameController::ScreenMult * 2);
	
	for (size_t i = 0; i < HSlable.length(); i++) //High Score lable
	{
		symbols.push_back(myFont.GetGlyph(HSlable.at(i), nextpos));
	
		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x += myFont.CellWidth() * 4;
	}
	
	nextpos = sf::Vector2f(GameController::ScreenMult * 10, GameController::ScreenMult * 13);
	
	for (size_t i = 0; i < credits.length(); i++) //credits
	{
		symbols.push_back(myFont.GetGlyph(credits.at(i), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));
	
		nextpos.x += myFont.CellWidth() * 4;
	}
	
	nextpos = sf::Vector2f(GameController::ScreenMult * 7, GameController::ScreenMult * 14);
	
	for (size_t i = 0; i < bonusLable.length(); i++) //Bonus
	{
		symbols.push_back(myFont.GetGlyph(bonusLable.at(i), nextpos));
	
		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x += myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 3);

	for (size_t i = HS1.length(); i > 0; i--) //HS1
	{
		symbols.push_back(myFont.GetGlyph(HS1.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 4);

	for (size_t i = HS2.length(); i > 0; i--) //HS2
	{
		symbols.push_back(myFont.GetGlyph(HS2.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 5);

	for (size_t i = HS3.length(); i > 0; i--) //HS3
	{
		symbols.push_back(myFont.GetGlyph(HS3.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 6);

	for (size_t i = HS4.length(); i > 0; i--) //HS4
	{
		symbols.push_back(myFont.GetGlyph(HS4.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 7);

	for (size_t i = HS5.length(); i > 0; i--) //HS5
	{
		symbols.push_back(myFont.GetGlyph(HS5.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 8);

	for (size_t i = HS6.length(); i > 0; i--) //HS6
	{
		symbols.push_back(myFont.GetGlyph(HS6.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 9);

	for (size_t i = HS7.length(); i > 0; i--) //HS7
	{
		symbols.push_back(myFont.GetGlyph(HS7.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 19, GameController::ScreenMult * 10);

	for (size_t i = HS8.length(); i > 0; i--) //HS8
	{
		symbols.push_back(myFont.GetGlyph(HS8.at(i-1), nextpos));

		currGrid->addShroomHere(sf::Vector2f(nextpos.x + GameController::HalfScreenMult, nextpos.y + GameController::HalfScreenMult));

		nextpos.x -= myFont.CellWidth() * 4;
	}
}

void HUD::Update()
{
	if(ATTRACTOR)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			this->ATTRACTOR = false;
			this->AttractorEnds();
			GameController::attractorEnds();
			GameController::gameStart();
		}
	}
}

void HUD::privScoreUpdate(int score)
{
	if (!ATTRACTOR)
	{
		std::string newScore = std::to_string(score);

		Glyph* deleteMe;

		for (int i = playerScore.size(); i > 0; i--)
		{
			deleteMe = playerScore.back();
			deleteMe->MarkForDestroy();
			playerScore.pop_back();
		}

		nextpos = sf::Vector2f(GameController::ScreenMult * 5, 0);

		for (size_t i = newScore.length(); i > 0; i--) //p1Score
		{
			playerScore.push_back(myFont.GetGlyph(newScore.at(i - 1), nextpos));

			nextpos.x -= myFont.CellWidth() * 4;
		}
	}
}

void HUD::privLifeLost()
{
	Player* currPlayer = PlayerManager::returnCurrPlayer();

	if(currPlayer->getLives() == 3)
	{
		extraLife->MarkForDestroy();
	}
	else if(currPlayer->getLives() == 2)
	{
		life2->MarkForDestroy();
	}
	else if(currPlayer->getLives() == 1)
	{
		life1->MarkForDestroy();
	}
}

void HUD::privExtraLife()
{
	Player* currPlayer = PlayerManager::returnCurrPlayer();

	if(currPlayer->getLives() == 2)
	{
		nextpos = sf::Vector2f((GameController::ScreenMult * 6) + GameController::HalfScreenMult, GameController::HalfScreenMult); //POS of life counter 1
		life1 = new BlankShip(nextpos);
	}
	else if (currPlayer->getLives() == 3)
	{
		nextpos = sf::Vector2f((GameController::ScreenMult * 7) + GameController::HalfScreenMult, GameController::HalfScreenMult); //POS of life counter 2
		life2 = new BlankShip(nextpos);
	}
	else if(currPlayer->getLives() == 4)
	{
		nextpos = sf::Vector2f((GameController::ScreenMult * 8) + GameController::HalfScreenMult, GameController::HalfScreenMult); //POS of life counter 2
		extraLife = new BlankShip(nextpos);
	}

	SoundManager::SendSoundCmd(pExtraLife);
}

std::string HUD::privEnterName()
{
	nextpos = sf::Vector2f(GameController::ScreenMult * 10, GameController::ScreenMult * 13);

	for (size_t i = 0; i < credits.length(); i++) //credits
	{
		symbols.push_back(myFont.GetGlyph(credits.at(i), nextpos));

		nextpos.x += myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 11, GameController::ScreenMult * 16);

	for (size_t i = 0; i < gameOver.length(); i++) //game over
	{
		gameOverVec.push_back(myFont.GetGlyph(gameOver.at(i), nextpos));

		nextpos.x += myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 9, GameController::ScreenMult * 19);

	for (size_t i = 0; i < greatScore.length(); i++) //great score
	{
		symbols.push_back(myFont.GetGlyph(greatScore.at(i), nextpos));

		nextpos.x += myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 5, GameController::ScreenMult * 20);

	for (size_t i = 0; i < enterYourInitials.length(); i++) //Enter your initials
	{
		symbols.push_back(myFont.GetGlyph(enterYourInitials.at(i), nextpos));

		nextpos.x += myFont.CellWidth() * 4;
	}

	std::string i1;
	std::string i2;
	std::string i3;

	//scanf("%s", i1);
	//
	//initial1 = myFont.GetGlyph(i1.at(0), nextpos);
	//
	//scanf("%s", i2);
	//
	//initial2 = myFont.GetGlyph(i2.at(0), nextpos);
	//
	//scanf("%s", i3);
	//
	//initial3 = myFont.GetGlyph(i3.at(0), nextpos);
	//
	std::string newLabel = i1 + i2 + i3;

	return newLabel;
}

void HUD::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

void HUD::privAttractorEnds()
{
	Glyph* deleteMe;

	for (int i = symbols.size(); i > 0; i--)
	{ 
		deleteMe = symbols.back();
		deleteMe->MarkForDestroy();
		symbols.pop_back();
	}

	for (int i = playerScore.size(); i > 0; i--)
	{
		deleteMe = playerScore.back();
		deleteMe->MarkForDestroy();
		playerScore.pop_back();
	}

	nextpos = sf::Vector2f(GameController::ScreenMult * 5, 0);
	std::string newScore = "00";

	for (size_t i = newScore.length(); i > 0; i--) //p1Score
	{
		playerScore.push_back(myFont.GetGlyph(newScore.at(i - 1), nextpos));

		nextpos.x -= myFont.CellWidth() * 4;
	}

	nextpos = sf::Vector2f((GameController::ScreenMult * 6) + GameController::HalfScreenMult, GameController::HalfScreenMult); //POS of life counter 1
	life1 = new BlankShip(nextpos);
	nextpos = sf::Vector2f((GameController::ScreenMult * 7) + GameController::HalfScreenMult, GameController::HalfScreenMult); //POS of life counter 2
	life2 = new BlankShip(nextpos);
}
