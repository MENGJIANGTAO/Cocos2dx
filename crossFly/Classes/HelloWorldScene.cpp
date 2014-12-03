#include "HelloWorldScene.h"
#include "tinyxml2/tinyxml2.h"
#include "cocos2d.h"
#include "myScene.h"

using namespace tinyxml2;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto title = LabelTTF::create("fonts/Marker Felt.ttf", "CrossFly",50);
	title->setPosition(visibleSize.width / 2, visibleSize.height*0.95);
	addChild(title);

	auto startGame = MenuItemFont::create("StartGame", CC_CALLBACK_1(HelloWorld::menuStartCallback, this));
	startGame->setFontSize(25);

	auto menu = Menu::create(startGame,nullptr);
	menu->setPosition(visibleSize.width / 2, visibleSize.height*0.5);
	addChild(menu);

	return true;
}

void HelloWorld::menuStartCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->replaceScene(myScene::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
