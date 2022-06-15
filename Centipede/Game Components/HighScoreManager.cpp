#include "HighScoreManager.h"
#include "HUD.h"
#include "ScoreManager.h"
#include "GameController.h"

HighScoreManager* HighScoreManager::ptrInstance = NULL;

HighScoreManager::HighScoreManager()
{
	highestScore = 15000;
	HS2 = 10000;
	HS3 = 8000;
	HS4 = 6000;
	HS5 = 3000;
	HS6 = 1000;
	HS7 = 500;
	HS8 = 250;

	highestScoreLabel = "TMP";
	HS2Label = "TMP";
	HS3Label = "TMP";
	HS4Label = "TMP";
	HS5Label = "TMP";
	HS6Label = "TMP";
	HS7Label = "TMP";
	HS8Label = "TMP";
}

void HighScoreManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

std::string HighScoreManager::privReturnHighestScore()
{
	std::string newString = std::to_string(highestScore);

	return newString;
}

std::string HighScoreManager::privReturnHS1()
{
	std::string newString = std::to_string(highestScore);
	newString = newString + " " + highestScoreLabel;

	return newString;
}

std::string HighScoreManager::privReturnHS2()
{
	std::string newString = std::to_string(HS2);
	newString = newString + " " + HS2Label;

	return newString;
}

std::string HighScoreManager::privReturnHS3()
{
	std::string newString = std::to_string(HS3);
	newString = newString + " " + HS3Label;

	return newString;
}

std::string HighScoreManager::privReturnHS4()
{
	std::string newString = std::to_string(HS4);
	newString = newString + " " + HS4Label;

	return newString;
}

std::string HighScoreManager::privReturnHS5()
{
	std::string newString = std::to_string(HS5);
	newString = newString + " " + HS5Label;

	return newString;
}

std::string HighScoreManager::privReturnHS6()
{
	std::string newString = std::to_string(HS6);
	newString = newString + " " + HS6Label;

	return newString;
}

std::string HighScoreManager::privReturnHS7()
{
	std::string newString = std::to_string(HS7);
	newString = newString + " " + HS7Label;

	return newString;
}

std::string HighScoreManager::privReturnHS8()
{
	std::string newString = std::to_string(HS8);
	newString = newString + " " + HS8Label;

	return newString;
}

void HighScoreManager::privCheckForNewHS(int finalScore)
{
	if(finalScore > HS8)
	{
		if(finalScore > HS7)
		{
			if(finalScore > HS6)
			{
				if(finalScore > HS5)
				{
					if(finalScore > HS4)
					{
						if(finalScore > HS3)
						{
							if(finalScore > HS2)
							{
								if(finalScore > highestScore)
								{
									//highestScoreLabel = HUD::EnterName();
									HS8 = HS7;
									HS7 = HS6;
									HS6 = HS5;
									HS5 = HS4;
									HS4 = HS3;
									HS3 = HS2;
									HS2 = highestScore;
									highestScore = finalScore;
									ScoreManager::setLastFinalScore(finalScore);
									HUD::AttractorStarts();
									GameController::attractorStart();
								}
								else
								{
									//HS2Label = HUD::EnterName();
									HS8 = HS7;
									HS7 = HS6;
									HS6 = HS5;
									HS5 = HS4;
									HS4 = HS3;
									HS3 = HS2;
									HS2 = finalScore;
									ScoreManager::setLastFinalScore(finalScore);
									HUD::AttractorStarts();
									GameController::attractorStart();
								}
							}
							else
							{
								//HS3Label = HUD::EnterName();
								HS8 = HS7;
								HS7 = HS6;
								HS6 = HS5;
								HS5 = HS4;
								HS4 = HS3;
								HS3 = finalScore;
								ScoreManager::setLastFinalScore(finalScore);
								HUD::AttractorStarts();
								GameController::attractorStart();
							}
						}
						else
						{
							//HS4Label = HUD::EnterName();
							HS8 = HS7;
							HS7 = HS6;
							HS6 = HS5;
							HS5 = HS4;
							HS4 = finalScore;
							ScoreManager::setLastFinalScore(finalScore);
							HUD::AttractorStarts();
							GameController::attractorStart();
						}
					}
					else
					{
						//HS5Label = HUD::EnterName();
						HS8 = HS7;
						HS7 = HS6;
						HS6 = HS5;
						HS5 = finalScore;
						ScoreManager::setLastFinalScore(finalScore);
						HUD::AttractorStarts();
						GameController::attractorStart();
					}
				}
				else
				{
					//HS6Label = HUD::EnterName();
					HS8 = HS7;
					HS7 = HS6;
					HS6 = finalScore;
					ScoreManager::setLastFinalScore(finalScore);
					HUD::AttractorStarts();
					GameController::attractorStart();
				}
			}
			else
			{
				//HS7Label = HUD::EnterName();
				HS8 = HS7;
				HS7 = finalScore;
				ScoreManager::setLastFinalScore(finalScore);
				HUD::AttractorStarts();
				GameController::attractorStart();
			}
		}
		else
		{
			//HS8Label = HUD::EnterName();
			HS8 = finalScore;
			ScoreManager::setLastFinalScore(finalScore);
			HUD::AttractorStarts();
			GameController::attractorStart();
		}
	}
}
