// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../Level1.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene(new Level1());

	AddTexture("Spaceship", "blaster.png");
	AddTexture("Shots", "bullet.png");
	AddTexture("Mushroom", "mushroom.png");
	AddTexture("Flea", "flea.png");
	AddTexture("Spider", "spider.png");
	AddTexture("Scorp", "scorpion.png");
	AddTexture("CentiH", "centipede_head.png");
	AddTexture("CentiB", "centipede_segment.png");
	AddTexture("PlayerExplosion", "death.png");
	AddTexture("EnemyExplosion", "spawn.png");
	AddTexture("SheetForNumbers", "SPRITES.BMP");

	AddSound("CentiStep", "beat.wav");
	AddSound("BonusMush", "bonus.wav");
	AddSound("PlayerDeath", "death.wav");
	AddSound("ExtraLife", "extraLife.wav");
	AddSound("ShootOne", "fire1.wav");
	AddSound("ShootTwo", "fire2.wav");
	AddSound("NewFlea", "flea_new.wav");
	AddSound("EnemyDeath", "kill.wav");
	AddSound("NewCenti", "newBeat.wav");
	AddSound("NewScorp", "scorpion_new.wav");
	AddSound("NewSpider", "spider_new.wav");
	AddSound("SpiderSong", "spiderloop.wav");

	AddTexture("Font", "FONT.bmp");

}

