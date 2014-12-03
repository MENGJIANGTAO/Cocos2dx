#include "endGame.h"

Scene * endGame::createScene()
{
	auto scene = Scene::create();
	auto layer = endGame::create();
	scene->addChild(layer);
	return scene;
}

bool endGame::init()
{
	if (!Layer::init())
	{
		return false;
	}
	int i = UserDefault::getInstance()->getIntegerForKey("score");
	CCLOG("score is %d", i);
	return true;
}