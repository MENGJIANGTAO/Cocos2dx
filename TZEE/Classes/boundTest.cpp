#include "boundTest.h"

USING_NS_CC;

Scene* boundTest::createScene()
{
	auto scene = Scene::create();
	auto layer = boundTest::create();
	scene->addChild(layer);
	return scene;
}

bool boundTest::init()
{
	if (!Layer::init())
		return false;
	visibleSize = Director::sharedDirector()->getVisibleSize();
	sp1 = Sprite::create("person/poster_char_aisi.png");
	sp2 = Sprite::create("person/poster_char_guyina.png");
	label = LabelBMFont::create("no collide.", "fonts/myfont.fnt");
	UserDefault::sharedUserDefault()->setStringForKey("name:", "mengjiangtao");
	label->setPosition(visibleSize.width / 2, visibleSize.height * 0.9);
	sp1->setScale(0.2f);
	sp1->setPosition(100, 100);
	sp2->setPosition(300, 300);
	sp2->setScale(0.2f);
	addChild(sp1,0);
	addChild(sp2,0);
	addChild(label,0);
}

void boundTest::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(boundTest::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(boundTest::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(boundTest::ontTouchEnded, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	Device::setAccelerometerEnabled(true);
	auto listener2 = EventListenerAcceleration::create(CC_CALLBACK_2(boundTest::onAcceleration, this));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
}
void boundTest::onExit()
{
	Layer::onExit();
}
bool boundTest::onTouchBegan(Touch* touch, Event* event)
{
	//CCLOG("Touch began.");
	return true;
}
void boundTest::onTouchMoved(Touch* touch, Event* event)
{
	//CCLOG("Touch Moved.");
	if (sp1->boundingBox().containsPoint(touch->getStartLocation()));
	{
		sp1->setPosition(touch->getLocation());
	}
	if (sp1->getBoundingBox().intersectsRect(sp2->getBoundingBox()))
	{
		label->setString("Done!");
	}
	else
	{
		label->setString("no collide.");
	}
}
void boundTest::ontTouchEnded(Touch* touch, Event* event)
{
	std::string name = UserDefault::sharedUserDefault()->getStringForKey("name");
	//CCLOG("The user name is %s",name);
	//CCLOG("Touch Ended.");
	canMove = false;
}

void boundTest::onAcceleration(Acceleration *p, Event * event)
{
	double posx = p->x;
	double posy = p->y;
	double posz = p->z;
	sp2->setPosition(100 + posx * 5, 100 + posy * 5);
	//CCLog("x = %f,y= %f,z=%f", posx, posy, posz);
}