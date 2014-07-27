#include "clickTest.h"
USING_NS_CC;


Scene *clickTest::createScene()
{
	auto scene = Scene::create();
	auto layer = clickTest::create();
	scene->addChild(layer);
	return scene;
}

bool clickTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
}

void clickTest::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(clickTest::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void clickTest::onExit()
{
	Layer::onExit();
}

bool clickTest::onTouchBegan(Touch *touch, Event *event)
{
	if (isClick)
	{
		isClick = false;
		doubleClick();
	}
	else
	{
		isClick = true;
		scheduleOnce(schedule_selector(clickTest::judgeClick), 0.3f);
		
	}
	return true;
}

void clickTest::singleClick()
{
	log("single click.");
}

void clickTest::doubleClick()
{
	log("double click.");
}

void clickTest::judgeClick(float dt)
{
	if (isClick)
	{
		isClick = false;
		singleClick();
	}
}