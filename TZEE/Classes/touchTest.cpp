#include "touchTest.h"

USING_NS_CC;

Scene* touchTest::createScene()
{
	auto scene = Scene::create();
	auto layer = touchTest::create();
	scene->addChild(layer);
	return scene;
}

bool touchTest::init()
{
	if (!Layer::init())
		return false;
}

void touchTest::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(touchTest::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(touchTest::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(touchTest::ontTouchEnded, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void touchTest::onExit()
{
	Layer::onExit();
}
bool touchTest::onTouchBegan(Touch* touch, Event* event)
{
	CCLOG("Touch began.");
	return true;
}
void touchTest::onTouchMoved(Touch* touch, Event* event)
{
	CCLOG("Touch Moved.");
}
void touchTest::ontTouchEnded(Touch* touch, Event* event)
{
	CCLOG("Touch Ended.");
}