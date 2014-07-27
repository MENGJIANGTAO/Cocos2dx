#include "gestureRecognition.h"
USING_NS_CC;

Scene *gestureRecognition::createScene()
{
	auto scene = Scene::create();
	auto layer = gestureRecognition::create();
	scene->addChild(layer);
	return scene;
}

bool gestureRecognition::init()
{
	if (!Layer::init())
	{
		return false;
	}
	pathLength = 100;
}

void gestureRecognition::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(gestureRecognition::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(gestureRecognition::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(gestureRecognition::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
}

void gestureRecognition::onExit()
{
	Layer::onExit();
}

bool gestureRecognition::onTouchBegan(Touch *touch, Event *event)
{
	Point touchPoint = touch->getLocation();
	curPos = touchPoint;
	this->scheduleOnce(schedule_selector(gestureRecognition::recognitionDirection, this),0.5f);
	return true;
}

void gestureRecognition::onTouchMoved(Touch *touch,Event *event)
{
	Point touchPoint = touch->getLocation();
	endPos = touchPoint;
}

void gestureRecognition::onTouchEnded(Touch *touch, Event *event)
{

}

void gestureRecognition::recognitionDirection(float dt)
{
	Point subPoint = ccpSub(endPos, curPos);

	// horizontal
	if (fabs(subPoint.x) > fabs(subPoint.y))
	{
		if (subPoint.x > pathLength)
		{
			log("right");
		}
		if (subPoint.x < -pathLength)
		{
			log("left");
		}
	}
	else
	{
		if (subPoint.y > pathLength)
		{
			log("up");
		
		}
		if (subPoint.y < -pathLength)
		{
			log("down");
		}
	}
}