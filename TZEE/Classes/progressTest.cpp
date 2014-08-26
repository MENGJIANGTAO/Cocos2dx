#include "progressTest.h"

Scene *progressTest::createScene()
{
	auto scene = Scene::create();
	auto layer = progressTest::create();
	scene->addChild(layer);
	return scene;
}

bool progressTest::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size size = Director::sharedDirector()->getWinSize();
	ProgressTimer *progress = ProgressTimer::create(Sprite::create("icon.png"));
	progress->setType(kCCProgressTimerTypeRadial);
	addChild(progress); 
	progress->setPosition(ccp(size.width * 0.5, size.height*0.5));
	progress->runAction(ProgressTo::create(10, 100));

	//Sprite *sp = Sprite::create("icon.png"); 
	MenuItemImage *sp = MenuItemImage::create("icon.png","icon.png");

	Menu *menu = Menu::create(sp, NULL);
	menu->setPosition(ccp(size.width*0.5, size.height*0.5));
	addChild(menu);
	menu->setOpacity(100);


	ProgressTo *to1 = ProgressTo::create(10, 100);

	ProgressTimer *horizontal = ProgressTimer::create(Sprite::create("icon.png"));
	horizontal->setType(kCCProgressTimerTypeBar);
	horizontal->setMidpoint(ccp(0, 0));
	horizontal->setBarChangeRate(ccp(1, 0));
	addChild(horizontal);
	horizontal->setPosition(ccp(size.width*0.5, size.height*0.3));
	horizontal->runAction(RepeatForever::create(to1));

	return true;
}