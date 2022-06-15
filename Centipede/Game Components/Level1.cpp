// CentipedeLevel
// Andre Berthiaume, MArch 2013

#include "TEAL\CommonElements.h"

#include "Level1.h"
#include "Ship.h"
#include "Bullet.h"
#include "GameController.h"
#include "Scorp.h"
#include "CentipedeBody.h"
#include "Spider.h"
#include "CentipedeHead.h"
#include "Flea.h"
#include "Mushroom.h"
#include "Scorp.h"
#include "PlayerManager.h"
#include "WaveManager.h"
#include "HUD.h"

void Level1::Initialize()
{
	WindowManager::SetBackgroundColor( sf::Color(0,0,0,0) );

	WaveManager::readFiles();
	GameController::attractorStart();
	HUD::AttractorStarts();

	CollisionTestPair<Bullet,Mushroom>(); 
	CollisionTestPair<Ship, Mushroom>();
	CollisionTestPair<Flea, Bullet>();
	CollisionTestPair<Spider, Bullet>();
	CollisionTestPair<Spider, Mushroom>();
	CollisionTestPair<Scorp, Bullet>();
	CollisionTestPair<CentipedeHead, Bullet>();
	CollisionTestPair<CentipedeBody, Bullet>();
	CollisionTestPair<Ship, Spider>();
	CollisionTestPair<Ship, CentipedeBody>();
	CollisionTestPair<Ship, CentipedeHead>();
};

void Level1::Terminate()
{
}

